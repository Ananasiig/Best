#pragma once

double empbo(int l, string &x) {
	
	double u = pow(2, l), p = -1, e = M_E;
	int m = x.length() / l;
	int nu0 = 0, k;
	double lam, lamp, nu, sig2;
	vector<int> vec(u);

	for (int t = 0; t < m; t++) {
		k = 0;
		for (int j = 0; j < l; j++) {
			k <<= 1;
			if (x[l*t + j] == '1')
				k++;
		}
		vec[k]++;
		//++v[x.substr(l * t, l)];
	}
	for (int i = 0; i<u; ++i){
		if (vec[i] == 0) nu0++;
	}
	double s = m - (u-nu0);
//	cout << s << ' ' << m << ' ' << u << ' ' << nu0;
	lam = 1.0 * m / u;
	lamp = lam * m / 2;
	nu = pow(e, - lam) * u;
	sig2 = nu * (1.0 - (1.0 + lam)*pow(e, -lam));
//	cout << s  << ' ' << lamp << ' ' <<  nu-(u-nu0) << endl;
	if (lam <= 1.0 / 32) {
		p = gamain(lamp, s, 1);
	}
	else if (lam > 1.0 / 32 && lam < 5.0) {
		p = norm_fun(-((u-nu0)-nu) / sqrt(sig2),0,1);
	}
	return p;
}
