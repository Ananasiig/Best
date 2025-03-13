#pragma once

void test_one(ofstream& out, string& bitString, int m, int k, double a, double b, vector<vector <double>>& res) {

    string test = "";
    double pvalue1 = 0, pmin = 1;
    vector <vector <double>> pvalue(8, vector<double>());

    int l = bitString.length() / m;

    out << "\t\ttest Entropy\n\nP-value(s):" << fixed << setprecision(6) << endl;


    for (int i = 0; i < m; ++i) {
        test = bitString.substr(i * 80000, 80000);

        pvalue1 = appent(test);
        pvalue[0].push_back(pvalue1);

        test = bitString.substr(i * 80000, 80000);

        pvalue1 = lseries(128, test);
        pvalue[1].push_back(pvalue1);

        test = bitString.substr(i * 80000, 80000);

        pvalue1 = mdu2(11, test);
        pvalue[2].push_back(pvalue1);

        test = bitString.substr(i * 80000, 80000);

        pvalue1 = mdu(9, test);
        pvalue[3].push_back(pvalue1);

        test = bitString.substr(i * 80000, 80000);

        pvalue1 = empbo(18, test);
        pvalue[4].push_back(pvalue1);

        test = bitString.substr(i * 80000, 80000);

        pvalue1 = series(test);
        pvalue[5].push_back(pvalue1);

        test = bitString.substr(i * 80000, 80000);

        pvalue1 = spect(test);
        pvalue[6].push_back(pvalue1);

        test = bitString.substr(i * 80000, 80000);

        pvalue1 = scapro(4, 10, test);
        pvalue[7].push_back(pvalue1);

        cout << (double)(i + 1) * 100 / m << "%\n";  
    }
    ber(pvalue, a, res);


    chi(pvalue, a, k, res);


    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < m; ++j) {
            out << '\t' << pvalue[i][j];
        }
        out << "\nBernoulli: " << res[0][i] << "\nChi:" << res[1][i] << "\n\n";

        pmin = min(res[0][i], pmin);
        pmin = min(res[1][i], pmin);

        if (i == 0) out << "\t\ttest Long Series\n\nP-value(s):" << endl;

        else if (i == 1) out << "\t\ttest MDU2\n\nP-value(s):" << endl;

        else if (i == 2) out << "\t\ttest MDU\n\nP-value(s):" << endl;

        else if (i == 3) out << "\t\ttest Empty Boxes\n\nP-value(s):" << endl;

        else if (i == 4) out << "\t\ttest Series\n\nP-value(s):" << endl;

        else if (i == 5) out << "\t\ttest Spectral\n\nP-value(s):" << endl;

        else if (i == 6) out << "\t\ttest Scalar\n\nP-value(s):" << endl;

     //   cout << (double)(i + 1) * 100 / 8 << "%\n";

    }
    system("cls");

    if (pmin < b) { out << 
        "-----------------------------------------------------------------------------------------------\nH1, Pmin < B: \t " 
        << pmin << " < " << b << endl << 
        "-----------------------------------------------------------------------------------------------\n"; }
    else out << "-----------------------------------------------------------------------------------------------\nH0, Pmin = " << pmin << endl << 
        "-----------------------------------------------------------------------------------------------\n";

    out.close();

}
