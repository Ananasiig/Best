#include <random>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <string>
#include <map>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include "2igamc.h"
#include "mduonis.h"
#include "mduois.h"

using namespace std;

int main()
{
 //   ifstream e("e.bin", ios::binary);
 //   ifstream belt("belt.bin", ios::binary);
 //   ifstream phys("phys.bin", ios::binary);

//    ifstream etxt("e.txt");
//    ifstream belttxt("belt.txt");
//    ifstream phystxt("phys.txt");
    
    double G = 0.1;
    
    string s = "0111000101", s2 = "0110101010101", s3 = "010110101001010";
//    etxt >> s;
//    belttxt >> s2;
//   phystxt >> s3;

/*
    unsigned char bin = 0x00;
    int bitt, prov = 0;

    while (e >> bin) {
        bitt = int(bin); 

        prov = pow(2, 7);
        while (prov > 0) {
            if (bitt > prov) {
                s += '1';
                bitt -= prov;
            }
            else {
                s += '0';
            }
            prov /= 2;
        }
    }*/

    cout << "\t\tTEST 5.2\n";
    for (int i = 1; i < 5; i++) {
        cout << fixed << mdu(i, s) << "\t\t" << mdu(i, s2) << "\t\t"  << mdu(i, s3) << "\n";
    }
    cout << "\n\n";

    cout << "\t\tTEST 5.3\n";
    for (int i = 1; i < 5; i++) {
        cout << mdu2(i, s) << "\t\t"  << mdu2(i, s2) << "\t\t"  << mdu2(i, s3) << "\n";
    }

  //  cout << gamain(4.882605/2, 1.5, 1);

}