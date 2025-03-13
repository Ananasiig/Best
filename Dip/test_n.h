#pragma once

void test_n(ofstream& out, vector<string> bitStrings, int m, int k, double a, double b, double ga) {
	int M = bitStrings.size();
	double dmin, dmax, vmin = 1;
	vector<vector<vector <double>>> results(M, vector<vector<double>>(2,vector<double>(8)));
	vector <vector <double>> v(2, vector<double>(8));

	for (int i = 0; i < M; ++i) {
		test_one(out, bitStrings[i], m, k, a, b, results[i]);
	}

	for (int b = 0; b < 2; ++b) {
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < M; ++i) {
				if (results[j][b][i] >= b) v[b][i] += 1;
			}
			v[b][i] /= M;
		}
	}

	dmin = max(0.0, 1 - ga - 3 * sqrt(ga * (1 - ga) / M));
	dmax = min(1.0, 1 - ga + 3 * sqrt(ga * (1 - ga) / M));

	for (int b = 0; b < 2; ++b) {
		for (int i = 0; i < 8; ++i) {
			vmin = min(vmin, v[b][i]);
		}
	}

	if (vmin >= dmin && vmin <= dmax) out << "-----------------------------------------------------------------------------------------------\nH0, Vmin = " 
		<< vmin << "\tVmin принадлежит [" << dmin << ", " << dmax << "]" << endl
		<< "-----------------------------------------------------------------------------------------------\n";
	else out << "-----------------------------------------------------------------------------------------------\nH1, Vmin = " << vmin << "\tVmin не принадлежит [" << dmin << ", " << dmax << "]" << endl
		<< "-----------------------------------------------------------------------------------------------\n";
}