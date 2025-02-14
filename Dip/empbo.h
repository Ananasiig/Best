#pragma once

double empbo(int l, string &x) {
	string sub;
	int nu0 = 0;
	double u = pow(2, l), p = -1, e = M_E;
	int m = x.length() / l;
	double lam, lamp, nu, sig2;
	map<string, int> v;
	for (int t = 0; t < m; t++) {
		++v[x.substr(l * t, l)];
	}
	for (const auto& element : v) {
		if (element.second > 0)
		{
			nu0 += 1;
		}
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
