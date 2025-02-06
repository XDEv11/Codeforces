//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve1() {
		int n, a;
		cin >> n >> a;
		vector<vector<char>> g(n, vector<char>(n));
		for (auto& v : g)
			for (auto& x : v) cin >> x;

		for (int k{0}; k < n; ++k) {
			int i, j;
			for (i = 0; i < n; ++i) {
				if (g[i][k] != g[k][k]) break;
			}
			for (j = 0; j < n; ++j) {
				if (g[k][j] != g[k][k]) break;
			}
			if (i == n && j == n) continue;

			if (a == (g[k][k] == '0')) {
				if (i < n) return void(cout << (i + 1) << ' ' << (k + 1) << '\n');
			} else {
				if (j < n) return void(cout << (k + 1) << ' ' << (j + 1) << '\n');
			}
			return void(cout << (k + 1) << ' ' << (k + 1) << '\n');
		}
		cout << "1 1\n";
	}

	void solve2() {
		int n;
		cin >> n;
		vector<char> r(n), c(n);
		for (auto& x : r) cin >> x;
		for (auto& x : c) cin >> x;

		for (int i{0}; i < n; ++i) {
			if (r[i] == c[i]) continue;
			return void(cout << (r[i] == '1') << '\n');
		}
		cout << "1\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string r{};
	cin >> r;

	int t{1};
	cin >> t;
	while (t--) r == "first" ? solve1() : solve2();
}
