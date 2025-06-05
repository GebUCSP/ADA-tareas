#include <iostream>
#include<vector>
#include<tuple>
#include <algorithm>

using namespace std;

bool order1(tuple<int, int, int>a, tuple<int, int, int>b) {
	return get<1>(a) < get<1>(b);
}

int main(int argc, char* argv[]) {
	int n, beneficio, tiempo;
	cin >> n;

	vector<tuple<int, int, int>> entradas;

	for (int i = 0; i < n; i++) {
		cin >> beneficio >> tiempo;
		tuple<int, int, int> p = make_tuple(beneficio, tiempo, i + 1);
		entradas.push_back(p);
	}
	cin >> beneficio;
	if (beneficio != 0) return 0; 

	sort(entradas.begin(), entradas.end(), order1);

	int total = 0;
	tuple<int, int, int> max = entradas[0];
	vector<int> soluciones;
	int tiempo_actual = get<1>(entradas[0]);

	for (int i = 0; i < entradas.size(); i++) {
		if (tiempo_actual == get<1>(entradas[i])) {
			if (get<0>(max) < get<0>(entradas[i]))
				max = entradas[i];
		}
		else {
			soluciones.push_back(get<2>(max));
			total += get<0>(max);
			max = entradas[i];
			tiempo_actual = get<1>(entradas[i]);
		}
		
	}
	soluciones.push_back(get<2>(max));
	total += get<0>(max);

	sort(soluciones.begin(), soluciones.end());

	cout << "Total: " << total << endl;

	for (int i = 0; i < soluciones.size(); i++)
		cout << soluciones[i] << " ";

	return 0;
}

