#pragma once

void ber(vector<vector <double> > p, double a, vector<vector <double> >&res) {
	int q = p.size(), m = p[0].size();
	vector<int> v(q);

	for (int i = 0; i < q; ++i) {
		for (int j = 0; j < m; ++j) {
			if (p[i][j] > a) ++v[i];
		}
	}

	for (int i = 0; i < q; ++i) {
		res[0][i] = 1 - norm_fun(-((double)v[i] / m - (1 - a)) / sqrt(a * (1 - a) / m), 0, 1);
	}
}
