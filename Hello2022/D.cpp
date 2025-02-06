//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<vector<ll>> c(2 * n, vector<ll>(2 * n));
	for (auto& v : c)
		for (auto& x : v) cin >> x;

	ll ans{};
	for (int i{n}; i < 2 * n; ++i)
		for (int j{n}; j < 2 * n; ++j) ans += c[i][j];
	ans += min({
		c[n - 1][n], c[n - 1][2 * n - 1],
		c[n][n - 1], c[2 * n - 1][n - 1],
		c[0][n], c[0][2 * n - 1],
		c[n][0], c[2 * n - 1][0],
	});

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
