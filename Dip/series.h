#pragma once

double series(string &x) {
	string exam = "";
	vector<double> nui;
	int k = 0;
	map<string, int> v0, v1;
	double nu = 10, s = 0;

	while(nu >= 5) {
		k++;
		nu = (x.length() - k + 3) / pow(2, k + 2);
		nui.push_back(nu);
	}
	k--;
	nui.pop_back();

	for (int i = 0; i < k; i++) {
		exam += '0';
	}
	for (int i = 0; i < k; i++) {
		exam += '1';
	}

	size_t cur = 0, next = 0;
	while (next != string::npos) {
		if (x[cur] == '0') {
			next = x.find('1', cur);
			++v0[x.substr(cur, next - cur)];
		}
		else if (x[cur] == '1') {
			next = x.find('0', cur);
			++v1[x.substr(cur, next - cur)];
		}
		cur = next;
	}
	for (int i = 0; i < k; i++) {
		s += (pow(v0[exam.substr(0, i + 1)] - nui[i], 2) + (pow(v1[exam.substr(k, i + 1)] - nui[i], 2)) )/ nui[i];
		}
	return 1-gamain(s/2, k-1, 1);
}