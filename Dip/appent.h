#pragma once

double appent(string& x) {
	int l = 1, u = 2, n = x.length(), k = 0;
	unordered_map<string, double> v, v1;
	double f = 0, f1 = 0, apen = 0, s = 0;
	

	while (u < 0.01 * n) {
		++l;
		u *= 2;
	}
	--l;
	u /= 2;
	x += x.substr(0, l-1);
	n = x.length();

	vector<int> vec(u), vec1(0.5*u);
//	cout << "\n" << l << "\n";
//	cout << n << "\n";

	for (int i = 0; i <= n - l; i++) {
		//++v[x.substr(i, l)];
	//	++v1[x.substr(i, l-1)];
		k = 0;
		for (int j = 0; j < l; j++) {
		k <<= 1;
		if (x[i+j] == '1')
			k++;
		}
		vec[k]++;
		k = 0;
		for (int j = 0; j < l-1; j++) {
			k <<= 1;
			if (x[i + j] == '1')
				k++;
		}
		vec1[k]++;
	//	cout << vec1[k] << endl;
	}
//	cout << "help\n";
	for (int i = 0; i < u; i++) {

		if (vec[i] != 0) {
			f -= log(1.0 * vec[i] / (n + 1 - l)) * vec[i];
		}
	//		cout << vec[i]<< ' ' << vec1[i] << endl;
	}

	for (int i = 0; i < 0.5*u; i++) {
		if (vec1[i] != 0) {
			f1 -= log(1.0 * vec1[i] / (n + 1 - l)) * vec1[i];
		}
	//	cout << vec[i] << ' ' << vec1[i] << endl;
	}
	f /= (n + 1 - l);
	f1 /= (n + 1 - l);
	apen = f - f1;

	s = 2 * (n-l+1) * fabs(log(2) - apen);
//	cout << f << ' ' << f1 << ' ' << apen << ' ' << 0.25*u << ' ' << s/2 << "\n";
	return 1 - gamain(s/2, 0.25*u, 1);
}