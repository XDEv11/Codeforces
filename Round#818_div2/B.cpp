//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, k, r, c;
	cin >> n >> k >> r >> c, --r, --c;
	vector<vector<char>> g(n, vector<char>(n, '.'));

	for (int i{0}; i < n; ++i)
		for (int j{i}; j >= 0; j -= k) g[i][j] = g[j][i] = 'X';

	vector<vector<char>> ans(n, vector<char>(n));
	int z{0};
	while (g[r][z] == '.') ++z;
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < n; ++j) ans[i][j] = g[i][(j + z - c + n) % n];

	for (auto& v : ans) {
		for (auto& x : v) cout << x;
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
