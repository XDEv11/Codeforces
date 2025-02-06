//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> g(n, vector<int>(n));
	for (auto& v : g)
		for (auto& x : v) cin >> x;

	vector<int> ans(n, (1 << 30) - 1);
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < n; ++j) {
			if (i == j) continue;
			ans[i] &= g[i][j];
		}
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < n; ++j) {
			if (i == j) continue;
			if (g[i][j] != (ans[i] | ans[j])) return cout << "NO\n", []{}();
		}

	cout << "YES\n";
	for (auto& x : ans) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
