#pragma once

double series(string &x) {
	string exam = "";
	vector<double> nui;
	int k = 0;
	map<string, int> v;
	double nu = 10, s = 0;
	while(nu >= 5) {
		nu = (x.length() - k + 3) / pow(2, k + 3);
		nui.push_back(nu);
		k++;
	}

	for (int i = 0; i < k; i++) {
		exam += '0';
	}
	for (int i = 0; i < k; i++) {
		exam += '1';
	}

	size_t cur = 0, next = 0;
	while (next != string::npos) {
		if (x[cur] == '0') {
			next = x.find('1', cur+1);
		}
		else if (x[cur] == '1') {
			next = x.find('0', cur+1);
		}
//		cout << x.substr(cur, next - cur) << endl;
		++v[x.substr(cur, next - cur)];
		cur = next;
	}
	for (int i = 0; i < k; i++) {
		cout << nui[i] << ' ' << v[exam.substr(0, i + 1)] << endl;
		s += (pow(v[exam.substr(0, i + 1)] - nui[i], 2) + (pow(v[exam.substr(k, i + 1)] - nui[i], 2)) )/ nui[i];
		}
//	cout << s << ' ' << v.size() << endl;
	return 1-gamain(s, 2*k-2, 1);
}