//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

static void solve() {
	using ll = long long;

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<ll>> h(n, vector<ll>(m));
	vector<vector<int>> c(n + 1, vector<int>(m + 1));
	for (auto& v : h)
		for (auto& x : v) cin >> x;
	for (int i{1}; i <= n; ++i)
		for (int j{1}; j <= m; ++j) {
			char t;
			cin >> t, c[i][j] = (t == '1' ? 1 : -1);
		}

	ll s{};
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < m; ++j) s += h[i][j] * c[i + 1][j + 1];

	vector<int> t{};
	for (int i{0}; i <= n; ++i)
		for (int j{1}; j <= m; ++j) c[i][j] += c[i][j - 1];
	for (int i{1}; i <= n; ++i)
		for (int j{0}; j <= m; ++j) c[i][j] += c[i - 1][j];
	for (int i{k}; i <= n; ++i)
		for (int j{k}; j <= m; ++j) {
			t.push_back(c[i][j] - c[i][j - k] - c[i - k][j] + c[i - k][j - k]);
		}

	int g{0};
	for (auto& x : t) {
		if (x) g = gcd(g, x);
	}

	if (!s || (g && s % g == 0)) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
