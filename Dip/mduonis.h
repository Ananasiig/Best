#pragma once

double mdu(int l, string x) {
	//”—Ћќ¬»я ѕ–»ћ≈Ќ≈Ќ»я: m >=50, m2_l >= 10

	int m, u = pow(2, l);
	m = x.length() / l;
	map<string, int> v;
	string sub;
	double svalue = 0, m2_l = 1.0*m/u;

	//частоты l-фрагментов
	for (int t = 0; t < m; t++) {
		sub = x.substr(l*t, l);
		v[sub]++;
//		cout << x.length() << ' ' << m << endl;
	}

	//вычисление статистики
	for (const auto& element : v) {
		svalue += 1.0 * pow(element.second - m2_l, 2) / m2_l;
//		cout << element.first << ' ' << m2_l << '\n';
	}
	cout << '\t' << u << ' ' << v.size() << '\n';
	svalue += 1.0 * (u - v.size()) * m2_l;
	cout << svalue << '\n';

	//возвращаем P-значение
	return 1 - gamain(svalue / 2, 0.5*u - 1, 1);
}