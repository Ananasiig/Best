#define _USE_MATH_DEFINES
int fullOutputFlag = 1;
unsigned long long int inFileSize = 0;
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
    string infilename = ""; //f.e. : "E:\\labs\\l0\\rnd_10MB.bin"
    string outfilename = "rnd.txt";
    ifstream e(infilename, ios::binary);
    ofstream out(outfilename);
    vector<vector <double>> res(2, vector<double>(8));
    vector<vector<vector <double>>> results;
    vector <string> bitStrings;
    string bitString, bitString1 = "", output; 
    char byte;
    char byte1;
    int mb10 = 83886080, mb1 = 8388608;

    cout << "Enter the full path to the file:\n" << endl;


    while (!e.is_open()) {
        cin >> infilename;
        e.open(infilename, ios::binary);
        if (e.is_open()) cout << "file " << infilename << " was opened.\n";
        else cout << "file " << infilename << " was not opened.\n" << "try again\n";
    }
    if (out.is_open()) cout << "file " << outfilename << " was opened.\n\n";

    // Перемещаем указатель в конец файла
    e.seekg(0, ios::end);

    // Получаем текущую позицию указателя (это и будет размер файла)
    streampos fileSize = e.tellg();
    inFileSize =  fileSize * 8;

    e.seekg(0, ios::beg);


    cout << "Write p-values to file?\n0 - don't write\n1 - write\n";

    cin >> fullOutputFlag; 

    double G = 0.1;
    int it = 0, numthr = 1, num = inFileSize/mb10, part;

    cout << "file [" << infilename << "] size: " << inFileSize << ' ' << omp_get_max_threads() << endl;

    if (num < omp_get_max_threads()-2) numthr = num;
    else numthr = omp_get_max_threads()-2;
    while (num % numthr != 0) numthr - 1;
    part = numthr;

    cout << "max threads: " << omp_get_max_threads() << endl;
    cout << "Количество потоков: " << numthr << endl;
    



    while (e.get(byte)) {
        bitString1 = bitset<8>(static_cast<unsigned char>(byte)).to_string(); // Convert each byte into a string of 8 bits
        reverse(bitString1.begin(), bitString1.end());
        bitString += bitString1;

        if (bitString.length() == mb10) {
            bitStrings.push_back(bitString);
            bitString.clear();

            if (bitStrings.size() == part) {

                #pragma omp parallel for num_threads(numthr)
                for (int i = 0; i < part; ++i) {
                    #pragma omp critical
                    {
                        output = "Stream " + to_string(omp_get_thread_num()) + ": processes [" 
                            + to_string(results.size() * mb10 + i * mb10) + ", "
                            + to_string(results.size() * mb10 + (i + 1) * mb10) + "] bits\n";
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
                output = "Stream " + to_string(omp_get_thread_num()) + ": processes ["
                    + to_string(results.size() * mb10 + i * mb10) + ", "
                    + to_string(results.size() * mb10 + (i + 1) * mb10) + "] bits\n";
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
        while (e.get(byte)) {
            bitString1 = bitset<8>(static_cast<unsigned char>(byte)).to_string();  // Convert each byte into a string of 8 bits
            reverse(bitString1.begin(), bitString1.end());
            bitString += bitString1;
            if (bitString.length() == mb1) {
                test_one(out, bitString, 104, 10, 0.05, 0.0001, res);
                results.push_back(res);
                bitString = "";
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