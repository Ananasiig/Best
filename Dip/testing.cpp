#define _USE_MATH_DEFINES

#include <random>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <string>
#include <map>
#include <unordered_map>
#include <math.h>
#include <cstdlib>
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

using namespace std;

int main()
{
    ifstream e("E:\\labs\\l0\\phys.bin", ios::binary);
 //   ofstream e2("E:\\labs\\l0\\e2.txt");
 //   ifstream belt("belt.bin", ios::binary);
 //   ifstream phys("phys.bin", ios::binary);

//    ifstream etxt("E:\\labs\\l0\\e.txt");
//    ifstream belttxt("E:\\labs\\l0\\belt.txt");
//    ifstream phystxt("E:\\labs\\l0\\phys.txt");
    
    double G = 0.1;
    
    string bitString;

    string s = "0111000101", s2 = "0110101010101", s3 = "010110101001010";
    for (int i = 1; i < 17; i++) {
        s += s; 
        s2 += s2;
    }

    char byte;
    while (e.get(byte)) {
        // Преобразование каждого байта в строку из 8 бит
        bitString += bitset<8>(static_cast<unsigned char>(byte)).to_string();
    }
    
    e.close();

    // Закрываем файл


//    etxt >> s3;
//    etxt >> s;
//    belttxt >> s2;
//   phystxt >> s3;

/*
* 
* 
* // Имя файла
    std::string filename = "binary_file.bin";

    // Открываем файл в бинарном режиме
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
        return 1;
    }

    // Переменная для хранения битовой строки
    std::string bitString;

    // Чтение файла побайтно
    char byte;
    while (file.get(byte)) {
        // Преобразование каждого байта в строку из 8 бит
        bitString += std::bitset<8>(static_cast<unsigned char>(byte)).to_string();
    }

    // Закрываем файл
    file.close();

    // Вывод битовой строки
    std::cout << "Битовая строка: " << bitString << std::endl;

    return 0;
* 
* 
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
   
     /*  cout << "\t\tTEST 2.1\n";
       for (int i = 3; i < 18; i++) {
           cout << fixed << "L = " << i << ": " << mdu(i, s) << "\t\t" << mdu(i, s2) << "\t\t" << mdu(i, bitString) << "\n";
       }
       cout << "\n\n";

       cout << "\t\tTEST 2.2\n";
       for (int i = 8; i < 18; i++) {
                 cout << "L = " << i << ": " << mdu2(i, s) << "\t\t"  << mdu2(i, s2) << "\t\t"  << mdu2(i, bitString) << "\n";
       }


          cout << "\t\ttest 2.3\n";
          for (int i = 15; i < 25; i++) {
                    cout << "l = " << i << ": " << empbo(i, s) << "\t\t"  << empbo(i, s2) << "\t\t"  << empbo(i, bitString) << "\n";
          }


        cout << "\t\ttest 2.4\n";
        
        cout << "\t" << series(s) << "\t\t" << series(s2) << "\t\t" << series(bitString) << "\n";

    cout << "\t\ttest 2.5-10invalid\n";
        cout << "\t" << lseries(10, s) << "\t\t" << lseries(10, s2) << "\t\t" << lseries(10, bitString) << "\n";

    cout << "\t\ttest 2.5-8\n";
        cout << "\t" << lseries(8, s) << "\t\t" << lseries(8, s2) << "\t\t" << lseries(8, bitString) << "\n";

    cout << "\t\ttest 2.5-128\n";
        cout << "\t" << lseries(128, s) << "\t\t" << lseries(128, s2) << "\t\t" << lseries(128, bitString) << "\n";

    cout << "\t\ttest 2.5-512\n";
        cout << "\t" << lseries(512, s) << "\t\t" << lseries(512, s2) << "\t\t" << lseries(512, bitString) << "\n";

    cout << "\t\ttest 2.5-1000\n";
        cout << "\t" << lseries(1000, s) << "\t\t" << lseries(1000, s2) << "\t\t" << lseries(1000, bitString) << "\n";

    cout << "\t\ttest 2.5-10000\n";
        cout << "\t" << lseries(10000, s) << "\t\t" << lseries(10000, s2) << "\t\t" << lseries(10000, bitString) << "\n";

  cout << "\t\ttest 2.6\n";
        cout << "\t" << appent(s) << "\t\t" << appent(s2) << "\t\t" << appent(bitString) << "\n";


     cout << "\t\ttest 2.7\n";
        cout << "\t" << scapro(6, 11, s) << "\t\t" << scapro(6, 11, s2) << "\t\t" << scapro(4, 2, bitString) << "\n";
*/

       cout << "\t\ttest 2.8\n";
            cout << "\t" << scapro(6, 11, s) << "\t\t" << scapro(6, 11, s2) << "\t\t" << scapro(4, 2, bitString) << "\n";
}