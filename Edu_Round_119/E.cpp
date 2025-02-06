//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <tuple>
#include <numeric>

using namespace std;

void solve() {
	int q;
	cin >> q;
	vector<tuple<int, int, int>> v(q);
	for (auto& [op, x, y] : v) {
		cin >> op >> x;
		if (op == 2) cin >> y;
	}

	vector<int> r(500000 + 1); iota(r.begin(), r.end(), 0);
	for (int i{q - 1}; i >= 0; --i) {
		auto& [op, x, y]{v[i]};
		if (op == 2) r[x] = r[y];
		else x = r[x];
	}

	for (auto& [op, x, y] : v)
		if (op == 1) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
