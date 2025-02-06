//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(m));
	for (auto& v : g)
		for (auto& x : v) cin >> x;

	long long ans{0};
	vector<pair<long long, long long>> c(100001);
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < m; ++j) {
			ans += i * c[g[i][j]].fi - c[g[i][j]].se;
			++c[g[i][j]].fi, c[g[i][j]].se += i;
		}
	fill(c.begin(), c.end(), make_pair(0LL, 0LL));
	for (int j{0}; j < m; ++j)
		for (int i{0}; i < n; ++i) {
			ans += j * c[g[i][j]].fi - c[g[i][j]].se;
			++c[g[i][j]].fi, c[g[i][j]].se += j;
		}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
