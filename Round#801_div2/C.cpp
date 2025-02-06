//#pragma GCC optimize ("O3")
 
#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(m));
	for (auto& v : g)
		for (auto& x : v) cin >> x;
 
	if ((n + m - 1) & 1) return cout << "NO\n", []{}();

	vector<vector<int>> mx(n, vector<int>(m, numeric_limits<int>::min()));
	vector<vector<int>> mn(n, vector<int>(m, numeric_limits<int>::max()));
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < m; ++j) {
			if (i == 0 && j == 0) {
				mx[i][j] = mn[i][j] = g[i][j];
				continue;
			}
			if (i - 1 >= 0) {
				mx[i][j] = mx[i - 1][j] + g[i][j];
				mn[i][j] = mn[i - 1][j] + g[i][j];
			}
			if (j - 1 >= 0) {
				mx[i][j] = max(mx[i][j], mx[i][j - 1] + g[i][j]);
				mn[i][j] = min(mn[i][j], mn[i][j - 1] + g[i][j]);
			}
		}
	cout << (mn.back().back() <= 0 && 0 <= mx.back().back() ? "YES\n" : "NO\n");
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
