#pragma once

void test_n(ofstream& out, vector<vector<vector <double>>>& results, int m, int k, double a, double b, double ga) {
	int M = results.size();
	double dmin, dmax, vmin = 1;
	vector <vector <double>> v(2, vector<double>(8));

	for (int mk = 0; mk < 2; ++mk) {
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < M; ++j) {
				if (results[j][mk][i] >= b) v[mk][i] += 1;
			}
			v[mk][i] /= M;
		}
	}

	dmin = max(0.0, 1 - ga - 3 * sqrt(ga * (1 - ga) / M));
	dmax = min(1.0, 1 - ga + 3 * sqrt(ga * (1 - ga) / M));

	for (int mk = 0; mk < 2; ++mk) {
		for (int i = 0; i < 8; ++i) {
			vmin = min(vmin, v[mk][i]);
		}
	}

	if (vmin >= dmin && vmin <= dmax) out << "\n\n\n-----------------------------------------\nH0, Vmin = " 
		<< vmin << "\tVmin принадлежит [" << dmin << ", " << dmax << "]" << endl
		<< "-----------------------------------------\n";
	else out << "\n\n\n-----------------------------------------\nH1, Vmin = " << vmin << "\tVmin не принадлежит[" << dmin << ", " << dmax << "]" << endl
		<< "-----------------------------------------\n";
}