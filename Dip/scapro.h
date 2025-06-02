#pragma once

double comb(int l, int m) {
	if (l > m) return 0;
	int r = max(l, m - l);
	if (r == m) { return 1; }
	double res = 1;
	for (int i = 0; i < m - r; i++) {
		res *= m - i;
		res /= i + 1;
	}
	return res;
}

double scapro(int m, int K, string& x) {
	vector<int> fk, ymax;
	vector<double> qk;
	int l = m * K, M = x.length()/l;
	double y = 0, f = 0, sum1, sum2, s = 0, left = 0, right = 0;
	for (int p = 0; p < m+1; p++) {
		fk.push_back(0);
		qk.push_back(0);
	}
	for (int p = 0; p < M; p++) {
		ymax.push_back(0);
	}
	qk[0] = pow(2, -m) * pow(1 + pow(2, 1 - K), m);


	for (int k = 1; k <= m; k++) {
		for (int i = 0; i <= m; i++) {
			sum1 = 0;
			sum2 = 0;
			for (int j = 0; j < k; j++) {
				sum2 += comb(j, i);
			}
			sum1 = sum2 + comb(k, i);
			left += comb(i, m) * (pow(pow(2, -i)*sum1, K - 1));
			right += comb(i, m) * (pow(pow(2, -i)*sum2, K - 1));
		}
		qk[k] = pow(2, -m) * (left - right);
		left = 0;
		right = 0;
	}

	double qmin = qk[0];
	for (int k = 0; k <= m; k++) {
		qmin = min(qmin, qk[k]);
	}
	if (1.0 * K / qmin > 0.1 * x.length() / m) { cout << qmin << ' ' << 1.0 * K / qmin << ' ' << 0.1 * x.length() / m << '\n';  return -1; }
	if (m != 2 && m != 3 && m != 4 && m != 5 && m != 6 && m != 7 && m != 8) { return -1; }
	if (K != 2 && K != 3 && K != 4 && K != 5 && K != 6 && K != 7 && K != 8 && K != 9 && K != 10 && K != 11) { return -1; }

	for (int i = 0; i < M; i++) {
		for (int j = 1; j < K; j++) {
			y = 0;
			for (int p = 0; p < m; p++) {
				y += (x[i * l + p] - '0') * (x[i * l + j * m + p] - '0');
			}
			if (y > ymax[i]) ymax[i] = y;
		}
	}

	for (int i = 0; i < M; i++) {
		++fk[ymax[i]];
	}
	for (int i = 0; i < m+1; i++) {
	}
	

	for (int k = 0; k <= m; k++) {
		s += pow(fk[k] - M * qk[k], 2)/(M*qk[k]);
	}

	return 1 - gamain(s/2, 0.5*m, 1);
}
		