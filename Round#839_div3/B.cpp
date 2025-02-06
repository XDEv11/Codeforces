//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

void solve() {
	array<array<int, 2>, 2> mtx;
	for (auto& vt : mtx)
		for (auto& x : vt) cin >> x;

	for (int k{0}; k < 4; ++k) {
		bool flag{true};
		for (int i{0}; i < 2; ++i)
			if (!(mtx[i][0] < mtx[i][1])) flag = false;
		for (int j{0}; j < 2; ++j)
			if (!(mtx[0][j] < mtx[1][j])) flag = false;
		if (flag) return cout << "YES\n", []{}();

		swap(mtx[0][0], mtx[0][1]);
		swap(mtx[1][0], mtx[0][0]);
		swap(mtx[1][1], mtx[1][0]);
	}
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
