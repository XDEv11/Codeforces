//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m)), b{a};
		for (auto& v : a)
			for (auto& x : v) {
				char c; cin >> c;
				x = c - '0';
			}
		for (auto& v : b)
			for (auto& x : v) {
				char c; cin >> c;
				x = c - '0';
			}

		for (int i{0}; i < n; ++i) {
			int s{};
			for (int j{0}; j < m; ++j) s += a[i][j];
			for (int j{0}; j < m; ++j) s -= b[i][j];
			if (s % 3) return cout << "NO\n", []{}();
		}
		for (int j{0}; j < m; ++j) {
			int s{};
			for (int i{0}; i < n; ++i) s += a[i][j];
			for (int i{0}; i < n; ++i) s -= b[i][j];
			if (s % 3) return cout << "NO\n", []{}();
		}
		cout << "YES\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
