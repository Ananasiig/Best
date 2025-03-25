#pragma once

double mdu(string &x) {
	int l = 1, m = x.length(), u = 2, k;
	double svalue = 0, m2_l = 1.0*m/u;

	//”—Ћќ¬»я ѕ–»ћ≈Ќ≈Ќ»я: m >=50, m2_l >= 10
	while (m >= 50 && m2_l >= 10) {
		l++;
		m = x.length() / l;
		u *= 2;
		m2_l = (double)m / u;
	}
	--l;
	m = x.length() / l;
	u /= 2;
	m2_l = (double)m / u;

	string sub;
	vector<int> vec(u);

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
		svalue += pow(m2_l - vec[i], 2);
	//	cout << vec[i] << ' ' << m2_l << '\n';
	}

	svalue /= m2_l;
//	cout << '\t' << u << ' ' << v.size() << '\n';
//x	cout << svalue <<  ' ' << u-1 << '\n';

	//возвращаем P-значение
	return 1 - gamain(svalue/2, 0.5*(u - 1), 1);
}