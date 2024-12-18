#pragma once

double mdu2(int l, string x) {
	//”—Ћќ¬»я ѕ–»ћ≈Ќ≈Ќ»я: n >= 20 * 2^l (l <= log_2(n/20))

	int u = pow(2, l), u2 = u / 2;;
	map<string, int> v, v2;
	string sub;
	double svalue = 0, gvalue = 0,gvalue2 = 0, n2_l = 1.0 * x.length() / u, n2_l1 = 1.0 * x.length() / u2;

	x = x + x.substr(0, l - 1);

	///частоты l-фрагментов
	for (int t = 0; t < x.length()-l; t++) {
		sub = x.substr(t, l);
		v[sub]++;
	}

	//вычисление статистики
	for (const auto& element : v) {
		gvalue += 1.0 * pow(element.second - n2_l, 2) / n2_l;
		
	}
	gvalue += 1.0 * (u - v.size()) * n2_l;
	

	//частоты (l-1)-фрагментов
	for (int t = 0; t < x.length() - l - 1; t++) {
		sub = x.substr(t, l-1);
		v2[sub]++;
	}

	//вычисление статистики
	for (const auto& element : v2) {
		gvalue2 += 1.0 * pow(element.second - n2_l1, 2) / n2_l1;

	}
	gvalue2 += 1.0 * (u - v.size()) * n2_l1;

	svalue = gvalue - gvalue2;
		//возвращаем P-значение
	return 1 - gamain(svalue / 2, 0.5 * (u - u2), 1);
}
