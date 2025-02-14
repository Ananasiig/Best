#pragma once

double appent(string& x) {
	int l = 1, u = 2, n = x.length();
	unordered_map<string, double> v, v1;
	double f = 0, f1 = 0, apen = 0, s = 0;

	while (u < 0.01 * n) {
		++l;
		u *= 2;
	}
	--l;
	u /= 2;
	cout << l << "\n";
	for (int i = 0; i < n - l; i++) {
		++v[x.substr(i, l)];
		++v1[x.substr(i, l-1)];
	}
	++v1[x.substr(n - l, l - 1)];
	cout << "help\n";
	for (const auto& element : v) {
		f -= log(element.second / (n + 1 - l)) * element.second;
	}
	f /= (n + 1 - l);
	for (const auto& element : v1) {
		f1 -= log(element.second / (n + 2 - l)) * element.second;
	}
	f1 /= (n + 2 - l);
	apen = f - f1;

	s = 2 * n * fabs(log(2) - apen);
	cout << f << ' ' << f1 << ' ' << apen << ' ' << 0.5*u << ' ' << s << "\n";
	return 1 - gamain(s, 0.5*u, 1);
}