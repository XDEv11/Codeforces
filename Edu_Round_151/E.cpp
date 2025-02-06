//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;
const ll PM{1000000007};
inline void MA(ll& a, ll b) { a = (a + b) % PM; }

void solve() {
	int n, kk;
	cin >> n >> kk;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<vector<ll>> dp0(77, vector<ll>(kk + 1)), mx{dp0};
	dp0[0 + 38][0] = 1;
	for (int i{0}; i < n; ++i) {
		vector<vector<ll>> dp1(77, vector<ll>(kk + 1));
		for (int k{0}; k <= kk; ++k)
			for (int j{-38}; j <= 38; ++j) {
				if (!dp0[j + 38][k]) continue;
				if (k + abs(j) <= kk) MA(dp1[j + 38][k + abs(j)], dp0[j + 38][k]);
				if (!v[i] && j - 1 >= -38 && k + abs(j - 1) <= kk) MA(dp1[j - 1 + 38][k + abs(j - 1)], dp0[j + 38][k]);
				if (v[i] && j + 1 <= 38 && k + abs(j + 1) <= kk) MA(dp1[j + 1 + 38][k + abs(j + 1)], dp0[j + 38][k]);
			}
		dp0.swap(dp1);
		for (int k{0}; k <= kk; ++k)
			for (int j{0}; j < 77; ++j) dp1[j][k] = 0;
	}

	ll ans{};
	for (int k{kk & 1}; k <= kk; k += 2) MA(ans, dp0[0 + 38][k]);

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
