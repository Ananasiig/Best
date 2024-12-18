#include <random>
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include "2igamc.h"
#include "mduonis.h"

using namespace std;

int main()
{
    double G = 0.1;
   
 //   cout << gamain(1, 0.4, 1);
    string s = "11111000000111110000";
    for (int i = 0; i < 10; i++) {
        s += s;
    }

    cout << mdu(6, s);
}