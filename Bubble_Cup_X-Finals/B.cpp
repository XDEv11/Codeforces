//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
const ll PM{1000000007};
ll MA(ll a, ll b) { return (a + b) % PM; }
ll MS(ll a, ll b) { return (a - b + PM) % PM; }
ll MM(ll a, ll b) { return (a * b) % PM; }
ll MP(ll a, ll b) {
    ll res{1};
    do {
        if (b & 1) res = MM(res, a);
    } while (a = MM(a, a), b >>= 1);
    return res;
}
ll MI(ll a) { return MP(a, PM - 2); }
ll MD(ll a, ll b) { return MM(a, MI(b)); }

void solve() {
	auto mm{[](const vector<vector<ll>>& m1, const vector<vector<ll>>& m2) {
		int s1{m1.size()}, s2{m2.size()}, s3{m2[0].size()};
		vector<vector<ll>> m3(s1, vector<ll>(s3));
		for (int i{0}; i < s1; ++i)
			for (int j{0}; j < s3; ++j)
				for (int k{0}; k < s2; ++k)
					m3[i][j] = MA(m3[i][j], MM(m1[i][k], m2[k][j]));
		return m3;
	}};

	int n, l, m;
	cin >> n >> l >> m, l -= 2;
	vector<int> v0(n), v1(n), v2(n);
	for (auto& x : v0) cin >> x, x %= m;
	for (auto& x : v1) cin >> x, x %= m;
	for (auto& x : v2) cin >> x, x %= m;

	vector<vector<ll>> dp(1, vector<ll>(m));
	for (auto& x : v0) ++dp[0][x];

	vector<vector<ll>> r(m, vector<ll>(m));
	for (int i{0}; i < m; ++i) r[i][i] = 1;
	{
		vector<vector<ll>> t(m, vector<ll>(m));
		vector<ll> cnt(m);
		for (auto& x : v1) ++cnt[x];
		for (int i{0}; i < m; ++i)
			for (int j{0}; j < m; ++j) t[i][j] = cnt[(j - i + m) % m];

		while (l) {
			if (l & 1) r = mm(r, t);
			t = mm(t, t), l /= 2;
		}
	}

	dp = mm(dp, r);

	ll ans{};
	for (int i{0}; i < n; ++i) ans = MA(ans, dp[0][(m - ((v1[i] + v2[i]) % m)) % m]);

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
