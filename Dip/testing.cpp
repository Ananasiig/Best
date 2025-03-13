#define _USE_MATH_DEFINES

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
#include "2igamc.h"
#include "mduonis.h"
#include "mduois.h"
#include "normal.h"
#include "empbo.h"
#include "series.h"
#include "lseries.h"
#include "appent.h"
#include "scapro.h"
#include "fftan.h"
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
    string outfilename = "E:\\labs\\l0\\outAC.txt";
    string infilename = "E:\\labs\\l0\\ac";
    ifstream e(infilename, ios::binary);
    ofstream out(outfilename);

    double G = 0.1;

    string bitString, bitString1;


    char byte;
    while (e.get(byte)) {
        // ѕреобразование каждого байта в строку из 8 бит
        bitString1 = bitset<8>(static_cast<unsigned char>(byte)).to_string();
        reverse(bitString1.begin(), bitString1.end());
        bitString += bitString1;
    }


    e.close();


    vector<vector <double>> res(2, vector<double>(8));

    test_one(out, bitString, 104, 10, 0.05, 0.0001, res);

    out.close();
}