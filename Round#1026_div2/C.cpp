//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;
		vector<pair<int, int>> c(n);
		for (auto& [x, y] : c) cin >> x >> y;

		int x{};
		for (int i{n - 1}; i >= 0; --i) {
			x = c[i].fi = max(x, c[i].fi);
			if (v[i] == -1) --x;
			else x -= v[i];
		}

		x = 0;
		for (int i{0}; i < n; ++i) {
			if (v[i] == -1) v[i] = (x < c[i].fi);
			x += v[i];
			if (!(c[i].fi <= x && x <= c[i].se)) return cout << "-1\n", []{}();
		}
		for (auto& x : v) cout << x << ' ';
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
