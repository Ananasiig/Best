#pragma once

double lseries(int l, string& x) {
	int ij, k;
	if (l == 8) {
		ij = 0;
		k = 3;
	}
	else if (l == 128) {
		ij = 4;
		k = 5;
	}
	else if (l == 512) {
		ij = 10;
		k = 5;
	}
	else if (l == 1000) {
		ij = 16;
		k = 5;
	}
	else if (l == 10000) {
		ij = 22;
		k = 6;
	}
	else { return -1; }

	double pi[29] = { 0.2148, 0.3672, 0.2305, 0.1875 ,
				 0.1174, 0.2430, 0.2493, 0.1752, 0.1027, 0.1124,
				 0.1170, 0.2460, 0.2523, 0.1755, 0.1015, 0.1077 ,
				 0.1307, 0.2437, 0.2452, 0.1714, 0.1002, 0.1088 ,
				 0.0822, 0.2092, 0.2483, 0.1933, 0.1208, 0.0675, 0.0727 };

	int d[29] = { 1, 2, 3, 4,
				 4, 5, 6, 7, 8, 9,
				 6, 7, 8, 9, 10, 11,
				 7, 8, 9, 10, 11, 12,
				 10, 11, 12, 13, 14, 15, 16};

	double s = 0;
	vector<int> b, v;
	int m = x.length()/l;
	size_t cur = 0, next = 0;
	for (int i = 0; i < m; i++) {
		b.push_back(0);
	}
	//cout << m << endl;

	for (int i = 0; i < k+1; i++) {
		v.push_back(0);
	}

	for (int i = 0; i < m; i++) {
		cur = i*l;
		next = i*l;
		while (next < i*l + l) {

		cur = next;

		if (x[cur] == '0') {
			next = x.find('1', cur);
			cur = next;
		}	
		else if (x[cur] == '1') {
			next = x.find('0', cur);
			if (next > i * l + l) {
				next = i * l + l;
			}
			b[i] = max(b[i], int(next - cur));
		}
	}
	//	cout << b[i] << ' ' << m  << ' ' << x.substr(i*l, l)  << endl;
	}

	for (int i = 0; i < m; i++) {
		if (b[i] <= d[ij]) {
			v[0]++;
		}
		else if (b[i] >= d[ij + k]) {
			v[k]++;
		}
		else	
			for (int j = 1; j < k; j++) {
				if (b[i] == d[ij + j]) {
				v[j]++;
			}
		}
	}

	for (int i = 0; i < k + 1; i++) {
	//	cout << v[i] << ' ';
			//	cout << v[i] << ' ' << m * pi[ij + i] << ' ' << m << ' ' << pi[ij + i] << endl;
	}
//	cout << endl;

	for (int i = 0; i < k+1; i++) {
		s += pow(v[i] - m * pi[ij + i], 2)/(m*pi[ij+i]);
	//	cout << v[i] << ' ' << m * pi[ij + i] << ' ' << m << ' ' << pi[ij + i] << endl;
	} 
//	cout << s << ' ' << k << endl;
	return 1 - gamain(0.5*s, 0.5*k, 1);
}