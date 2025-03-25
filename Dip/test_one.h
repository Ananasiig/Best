#pragma once
extern int fullOutputFlag;
extern unsigned long long int inFileSize;
extern double progress;

void test_one(ofstream& out, string& bitString, int m, int k, double a, double b, vector<vector <double>>& res) {

    string test = "";
    double pvalue1 = 0, pmin = 1, bmin = 1, cmin = 1;
    int ll;
    if (bitString.length() < 100000) ll = 18;
    else ll = 22;
    vector <vector <double>> pvalue(8, vector<double>());

    int l = bitString.length() / m;

    if(fullOutputFlag != 0)
    out << "\t\ttest Entropy\n\nP-value(s):" << fixed << setprecision(6) << endl;
    
    for (int i = 0; i < m; ++i) {
        test = bitString.substr(i * l, l);


        pvalue1 = lseries(test);
        pvalue[1].push_back(pvalue1);


        pvalue1 = mdu2(test);
        pvalue[2].push_back(pvalue1);


        pvalue1 = mdu(test);
        pvalue[3].push_back(pvalue1);


        pvalue1 = empbo(ll, test);
        pvalue[4].push_back(pvalue1);


        pvalue1 = series(test);
        pvalue[5].push_back(pvalue1);


        pvalue1 = spect(test);
        pvalue[6].push_back(pvalue1);


        pvalue1 = scapro(4, 10, test);
        pvalue[7].push_back(pvalue1);

        pvalue1 = appent(test);
        pvalue[0].push_back(pvalue1);

        
        if (i % 10 == 0) {
            progress += ((double)l / inFileSize) * 1000;
        }
        #pragma omp single nowait
        {
            if (i % 10 == 0) 
                cout << progress << "%\n";
        }
    }
    
    ber(pvalue, a, res);

    chi(pvalue, a, k, res);

    if (fullOutputFlag != 0) {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < m; ++j) {
                out << '\t' << pvalue[i][j];
                pmin = min(pmin, pvalue[i][j]);
            }
            out << "\nBernoulli: " << res[0][i] << "\nChi:" << res[1][i] << "\n\n";

            bmin = min(res[0][i], bmin);
            cmin = min(res[1][i], cmin);

            if (i == 0) out << "\t\ttest Long Series\n\nP-value(s):" << endl;

            else if (i == 1) out << "\t\ttest MDU2\n\nP-value(s):" << endl;

            else if (i == 2) out << "\t\ttest MDU\n\nP-value(s):" << endl;

            else if (i == 3) out << "\t\ttest Empty Boxes\n\nP-value(s):" << endl;

            else if (i == 4) out << "\t\ttest Series\n\nP-value(s):" << endl;

            else if (i == 5) out << "\t\ttest Spectral\n\nP-value(s):" << endl;

            else if (i == 6) out << "\t\ttest Scalar\n\nP-value(s):" << endl;

            //   cout << (double)(i + 1) * 100 / 8 << "%\n";

        }
    }
    else
    {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < m; ++j) {
                pmin = min(pmin, pvalue[i][j]);
            }

            bmin = min(res[0][i], bmin);
            cmin = min(res[1][i], cmin);
        }
    }

    if (bmin < b) { out << 
        "----\nH1, Bernoulli - P1min < B: \t " 
        << bmin << " < " << b << endl << 
        "----\n"; }
    else out << "----\nH0, Bernoulli - P1min = " << bmin << endl << 
        "----\n";

    if (cmin < b) {
        out <<
            "----\nH1, Chi - P2min < B: \t "
            << cmin << " < " << b << endl <<
            "----\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    }
    else out << "----\nH0, Chi - P2min = " << cmin << endl <<
        "----\n\n\n\n\n\n\n\n\n\n\n\n\n\n";


}
