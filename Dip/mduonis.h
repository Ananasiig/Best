#pragma once

double mdu(int l, string &x) {
	//”—Ћќ¬»я ѕ–»ћ≈Ќ≈Ќ»я: m >=50, m2_l >= 10

	int m, u = pow(2, l), k;
	m = x.length() / l;
	map<string, int> v;
	string sub;
	double svalue = 0, m2_l = 1.0*m/u;
	vector<int> vec(u);
	if (m < 50 || m2_l < 10) { return -1; }

	//частоты l-фрагментов
	for (int t = 0; t < m; t++) {/*
		sub = x.substr(l*t, l);
		++v[sub];*/

		k = 0;
		for (int j = 0; j < l; j++) {
			k <<= 1;
			if (x[t + j] == '1')
				k++;
		}
		vec[k]++;

//		cout << x.length() << ' ' << m << endl;
	}

	//вычисление статистики
	for (int i = 0; i < u; i++) {
		svalue += 1.0 * pow(vec[i] - m2_l, 2) / m2_l;
//		cout << element.first << ' ' << m2_l << '\n';
	}
//	cout << '\t' << u << ' ' << v.size() << '\n';
//	cout << svalue << '\n';

	//возвращаем P-значение
	return 1 - gamain(svalue, u - 1, 1);
}