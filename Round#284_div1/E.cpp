
#include <iostream>
#include <array>
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
	array<ll, 7> w;
	for (auto& x : w) cin >> x;

	vector<vector<ll>> dp(8);
	dp[0].emplace_back(1);
	for (int k{1}; k <= 7; ++k) {
		vector<vector<ll>> t(1 << k, vector<ll>(1 << k));
		for (int i{0}; i < (1 << k); ++i)
			for (int j{0}; j < (1 << k); ++j) {
				vector<ll> aux0(k + 1), aux1(k + 1);
				aux1[0] = 1;
				for (int kk{1}; kk <= k; ++kk) {
					bool f{!(((i & j) >> (kk - 1)) & 1)};
					aux0[kk] = MA(aux0[kk - 1], aux1[kk - 1]);
					aux1[kk] = MA(aux0[kk - 1], f * aux1[kk - 1]);
				}
				t[i][j] = aux1[k];
			}
		vector<vector<ll>> r(1 << k, vector<ll>(1 << k));
		for (int i{0}; i < (1 << k); ++i) r[i][i] = 1;
		while (w[k - 1]) {
			if (w[k - 1] & 1) r = MMM(r, t);
			t = MMM(t, t), w[k - 1] /= 2;
		}
		vector<vector<ll>> last(1, vector<ll>(1 << k));
		for (int i{1 << (k - 1)}; i < (1 << k); ++i) last[0][i] = dp[k - 1][i - (1 << (k - 1))];
		auto curr{MMM(last, r)};
		dp[k] = curr[0];
	}

	cout << dp[7][0x7F] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
