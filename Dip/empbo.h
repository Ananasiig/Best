#pragma once

double empbo(int l, string &x) {
	string sub;
	int nu0 = 0, k;
	double u = pow(2, l), p = -1, e = M_E;
	int m = x.length() / l;
	double lam, lamp, nu, sig2;
	vector<int> vec(u);
//	unordered_map<string, int> v;
	for (int t = 0; t < m; t++) {
		k = 0;
		for (int j = 0; j < l; j++) {
			k <<= 1;
			if (x[t + j] == '1')
				k++;
		}
		vec[k]++;
		//++v[x.substr(l * t, l)];
	}
	for (int i = 0; i<u; ++i){
		if (vec[i] > 0) ++nu0;
	}
	int s = m - nu0;
	lam = m / u;
	lamp = lam * m / 2;
	nu = u * pow(e, - lam);
	sig2 = nu * (1 - (1 + lam)/pow(e, lam));
//	cout << s  << ' ' << lamp << ' ' <<  nu-(u-nu0) << endl;
	if (lam <= 1.0 / 32) {
		p = gamain(2*s, 2*lamp, 1);
	}
	else if (lam > 1.0 / 32 && lam < 5.0) {
		p = norm_fun(-((u-nu0)-nu) / sqrt(sig2),0,1);
	}
	return p;
}
