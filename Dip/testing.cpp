#define _USE_MATH_DEFINES
int fullOutputFlag = 1, inFileSize = 0;
double progress = 0;

#include <random>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <string>
#include <map>
#include <unordered_map>
#include <math.h>
#include <ctime>
#include <bitset>
#include <omp.h>
#include "2igamc.h"
#include "mduonis.h"
#include "mduois.h"
#include "normal.h"
#include "empbo.h"
#include "series.h"
#include "lseries.h"
#include "appent.h"
#include "scapro.h"
#include "spect.h"
#include "dfft.h"
#include "ber.h"
#include "chi.h"
#include "test_one.h"
#include "test_n.h"


using namespace std;

int main()
{
    setlocale(LC_ALL, ".1251");
    string infilename = ""; //E:\\labs\\l0\\rnd_10MB.bin
    string outfilename = "rnd.txt";
    ifstream e(infilename, ios::binary);
    ofstream out(outfilename);
    vector<vector <double>> res(2, vector<double>(8));
    vector<vector<vector <double>>> results;
    vector <string> bitStrings;
    string sbitString, bitString2;
    char byte1;

    cout << "������� ������ ���� � �����\n������: E:" << "\\\\" << "labs" << "\\\\" << "l0" << "\\\\" << "rnd_10MB.bin" << endl;


    while (!e.is_open()) {
        cin >> infilename;
        e.open(infilename, ios::binary);
        if (e.is_open()) cout << "file " << infilename << " was opened.\n";
        else cout << "file " << infilename << " was not opened.\n" << "try again\n";
    }
    // ���������� ��������� � ����� �����
    e.seekg(0, ios::end);

    // �������� ������� ������� ��������� (��� � ����� ������ �����)
    streampos fileSize = e.tellg();
    inFileSize = 8 * fileSize;

    e.seekg(0, ios::beg);

    if (out.is_open()) cout << "file " << outfilename << " was opened.\n\n";

    cout << "�������� p-�������� � ����?\n0 - �� ��������\n1 - ��������\n";

    cin >> fullOutputFlag; 

    double G = 0.1;
    int it = 0, numthr = 1, num = inFileSize/83886080, part;

    cout << "file [" << infilename << "] size: " << inFileSize << endl;

    if (num < 10) numthr = num;
    else numthr = 10;
    if (omp_get_max_threads()-2 < numthr) numthr = omp_get_max_threads()-2;
    part = numthr;

    cout << "max threads: " << omp_get_max_threads() << endl;
    cout << "���������� �������: " << numthr << endl;

    string bitString = ""; 
    
    string bitString1 = "", output; 
    char byte;



    while (e.get(byte)) {
        // �������������� ������� ����� � ������ �� 8 ���
        bitString1 = bitset<8>(static_cast<unsigned char>(byte)).to_string();
        reverse(bitString1.begin(), bitString1.end());
        bitString += bitString1;

        if (bitString.length() == 83886080) {
            bitStrings.push_back(bitString);
            bitString.clear();

            if (bitStrings.size() == part) {

                #pragma omp parallel for num_threads(numthr)
                for (int i = 0; i < part; ++i) {
                    #pragma omp critical
                    {
                        output = "����� " + to_string(omp_get_thread_num()) + ": ������������ ����� [" 
                            + to_string((results.size() / part + 1)*i * 83886080) + ", "
                            + to_string((results.size() / part + 1) * (i + 1) * 83886080) + "]\n";
                        cout << output;
                    }

                    vector<vector <double>> res1(2, vector<double>(8));
                    test_one(out, bitStrings[i], 200, 10, 0.05, 0.0001, res1);

                    #pragma omp critical
                    {
                        results.push_back(res1);
                    }
                }
                bitStrings.clear();
            }

        }

    }
    if (bitStrings.size() > 0) {

        #pragma omp parallel for num_threads(bitStrings.size())
        for (int i = 0; i < bitStrings.size(); ++i) {
            #pragma omp critical
            {
                output = "����� " + to_string(omp_get_thread_num()) + ": ������������ ����� ["
                    + to_string((results.size() / part + 1) * i * 83886080) + ", "
                    + to_string((results.size() / part + 1) * (i + 1) * 83886080) + "]\n";
                cout << output;
            }

            vector<vector <double>> res1(2, vector<double>(8));
            test_one(out, bitStrings[i], 200, 10, 0.05, 0.0001, res1);

            #pragma omp critical
            {
                results.push_back(res1);
            }
        }
        bitStrings.clear();
    }

    if (results.size() == 0) {
        while (e.get(byte1)) {
            // �������������� ������� ����� � ������ �� 8 ���
            bitString2 = bitset<8>(static_cast<unsigned char>(byte1)).to_string();
            reverse(bitString2.begin(), bitString2.end());
            sbitString += bitString2;
            if (sbitString.length() == 8388608) {
                test_one(out, sbitString, 104, 10, 0.05, 0.0001, res);
                results.push_back(res);
                sbitString = "";
            }
        }
        if (results.size() > 1) {
            test_n(out, results, 104, 10, 0.05, 0.0001, 0.01);
        }
    }
    else if (results.size() > 1)
            test_n(out, results, 200, 10, 0.05, 0.0001, 0.01);

    e.close();
    if (!e.is_open()) cout << "file " << infilename << " was closed.\n";



    out.close();
    if (!out.is_open()) cout << "file " << outfilename << " was closed.\n";

    return 0;
}