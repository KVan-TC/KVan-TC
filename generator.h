#include<bits/stdc++.h>
#include "func.h"
using namespace std;

void gen(int idx, string file) {
	ofstream cout(file);

	int n = Rand(1, 1e5), q = Rand(1, 1e5);

	cout << n << " " << q << "\n";
	for (int i = 0; i < n; i++)
		cout << Rand(-1e6, 1e6) << " ";
	cout << "\n";
	for (int i = 0; i < q; i++) {
		int l = Rand(1, n - 2);
		int r = Rand(l + 2, n);

		cout << l << " " << r << "\n";
	}
}