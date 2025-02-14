#pragma once

double mdu2(int l, string &x) {
	//”—Ћќ¬»я ѕ–»ћ≈Ќ≈Ќ»я: n >= 20 * 2^l (l <= log2(n/20))

	int u = pow(2, l), u2 = u / 2;
	unordered_map<string, int> v, v2;
	string sub;
	double svalue = 0, gvalue = 0,gvalue2 = 0, n2_l = 1.0 * x.length() / (10*u), n2_l1 = 1.0 * x.length() / (10*u2);

	x = x + x.substr(0, l);

	if (x.length() < 20 * u) { return -1; }
	///частоты l-фрагментов
	//частоты (l-1)-фрагментов
	for (int t = 0; t < x.length()/10; t++) {
		++v[x.substr(t, l)];
		++v2[x.substr(t, l - 1)];
	}

	//вычисление статистики
	for (const auto& element : v) {
		gvalue += 1.0 * pow(element.second - n2_l, 2) / n2_l;
		
	}
	gvalue += 1.0 * (u - v.size()) * n2_l;
	//вычисление статистики
	for (const auto& element : v2) {
		gvalue2 += 1.0 * pow(element.second - n2_l1, 2) / n2_l1;

	}
	gvalue2 += 1.0 * (u - v.size()) * n2_l1;

	svalue = gvalue - gvalue2;
		//возвращаем P-значение
	return 1 - gamain(svalue, u2, 1);
}
