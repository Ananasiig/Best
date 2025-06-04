#pragma once

double mdu2(string &x) {
	//Terms of use: n >= 20 * 2^l (l <= log2(n/20))
	int l = 1;
	while (l <= log2(0.05 * x.length())) {
		++l;
	}
	--l;

	int u = pow(2, l), u2 = u / 2, k;

	if (x.length() < 20 * u) { cout << x.length() << ' ' << 20 * u << " \n-1\n"; return -1; }

	vector<int> vec(u), vec1(u2);
	string sub;
	double svalue = 0, gvalue = 0,gvalue2 = 0, n2_l = 1.0 * x.length() / u, n2_l1 = 1.0 * x.length() / u2;

	x = x + x.substr(0, l);

	if (x.length() < 20 * u) { return -1; }
	///l-fragments frequencies
	//(l-1)-fragments frequencies
	for (int t = 0; t < x.length()-l+1; t++) {
		k = 0;
		for (int j = 0; j < l; j++) {
			k <<= 1;
			if (x[t + j] == '1')
				k++;
		}
		vec[k]++;

		k = 0;
		for (int j = 0; j < l - 1; j++) {
			k <<= 1;
			if (x[t + j] == '1')
				k++;
		}
		vec1[k]++;
	}


	//statistics calculation

	for (int i = 0; i < u; i++) {
		gvalue += pow(n2_l - vec[i], 2);
	}
	gvalue /= n2_l;

	for (int i = 0; i < u2; i++) {
		gvalue2 += pow(n2_l1 - vec1[i], 2);
	}
	gvalue2 /= n2_l1;

	svalue = gvalue - gvalue2;

	x.erase(x.length() - l, l);
		//return P-value q
	return 1 - gamain(svalue/2, 0.5*u2, 1);
}
