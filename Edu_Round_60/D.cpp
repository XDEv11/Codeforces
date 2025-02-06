
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
template<typename T>
using matrix = vector<vector<T>>;
matrix<ll> MMM(const matrix<ll>& m1, const matrix<ll>& m2) {
	matrix<ll> m3(m1.size(), vector<ll>(m2[0].size()));
	for (int i{0}; i < m1.size(); ++i)
		for (int j{0}; j < m2[0].size(); ++j)
			for (int k{0}; k < m2.size(); ++k) m3[i][j] = MA(m3[i][j], MM(m1[i][k], m2[k][j]));
	return m3;
}

void solve() {
	ll n; int m;
	cin >> n >> m;
	if (n < m) return cout << "1\n", []{}();

	matrix<ll> dp(1, vector<ll>(m));
	for (int i{0}; i < m; ++i) dp[0][i] = 1;

	matrix<ll> r(m, vector<ll>(m));
	for (int i{0}; i < m; ++i) r[i][i] = 1;
	{
		matrix<ll> t(m, vector<ll>(m));
		for (int i{0}; i + 1 < m; ++i) t[i][i + 1] = 1;
		t[m - 1][m - 1] = 1, t[m - 1][0] = 1;

		n -= (m - 1);
		while (n) {
			if (n & 1) r = MMM(r, t);
			t = MMM(t, t), n /= 2;
		}
	}

	dp = MMM(dp, r);

	cout << dp[0][m - 1] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
