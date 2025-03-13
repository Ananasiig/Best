#pragma once

double mdu(int l, string &x) {
	//”—Ћќ¬»я ѕ–»ћ≈Ќ≈Ќ»я: m >=50, m2_l >= 10

	int m, u = pow(2, l), k;
	m = x.length() / l;
	string sub;
	double svalue = 0, m2_l = 1.0*m/u;
	vector<int> vec(u);
	if (m < 50 || m2_l < 10) { cout << endl << m << ' ' << m2_l << " "; return -1; }

	//частоты l-фрагментов
	for (int t = 0; t < m; t++) {

		k = 0;
		for (int j = 0; j < l; j++) {
			k <<= 1;
			if (x[t*l + j] == '1')
				k++;
		}
		vec[k]++;

//		cout << x.length() << ' ' << m << endl;
	}

	//вычисление статистики
	for (int i = 0; i < u; ++i) {
		svalue += pow(vec[i] - m2_l, 2);
	//	cout << vec[i] << ' ' << m2_l << '\n';
	}

	svalue /= m2_l;
//	cout << '\t' << u << ' ' << v.size() << '\n';
//x	cout << svalue <<  ' ' << u-1 << '\n';

	//возвращаем P-значение
	return 1 - gamain(svalue/2, 0.5*(u - 1), 1);
}