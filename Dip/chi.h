#pragma once

void chi(vector<vector <double> > p, double a, double k, vector<vector <double> >& res) {
	double q = p.size(), m = p[0].size();
	vector<vector <int> > v(q, vector<int>(k));
	vector<double> stat(q);

	for (int i = 0; i < q; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int t = 0; t < k; ++t) {
				if (p[i][j] < (1.0 + t) / k) {
					++v[i][t];
					break;
				}
			}
			if (p[i][j] == 1) ++v[i][k - 1];
		}
	}

	for (int i = 0; i < q; ++i) {
		for (int j = 0; j < k; ++j) {
			stat[i] += pow(v[i][j] - m / k, 2);
		}
		stat[i] /= m / k;
	}

	for (int i = 0; i < q; ++i) {
		res[1][i] = 1 - gamain(stat[i]/2, 0.5*(k-1 ), 1);
	}
}
