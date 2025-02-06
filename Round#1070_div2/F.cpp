//#pragma GCC optimize ("O3")

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	const ll PM{998244353};
	ll MC(ll a) { return (a % PM + PM) % PM; }
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
		int n, m;
		cin >> n >> m;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		vector<int> cnt(n + 1);
		for (auto& x : v) ++cnt[x];

		const int M{6}; // max(w(x)) <= M
		vector<int> w(n + 1);
		for (int i{2}; i <= n; ++i) {
			if (w[i]) continue;
			for (int j{i}; j <= n; j += i) ++w[j];
		}

		vector<array<ll, M + 1>> aux(n + 1);
		for (int i{1}; i <= n; ++i)
			for (int j{i}; j <= n; j += i) aux[i][w[j]] += cnt[j];

		vector<array<ll, M * 2 + 1>> dp(n + 1);
		for (int i{n}; i >= 1; --i) {
			for (int w1{0}; w1 <= M; ++w1) {
				dp[i][w1 * 2] = MA(dp[i][w1 * 2], MC(aux[i][w1] * (aux[i][w1] - 1) / 2));
				for (int w2{max(w[i] + 1 - w1, w1 + 1)}; w2 <= M; ++w2) {
					dp[i][w1 + w2] = MA(dp[i][w1 + w2], MC(aux[i][w1] * aux[i][w2]));
				}
			}
			for (int j{i * 2}; j <= n; j += i)
				for (int ws{w[i] + 1}; ws <= M * 2; ++ws) dp[i][ws] = MS(dp[i][ws], dp[j][ws]);
		}

		ll ans{};
		array<ll, M * 2 + 1> a;
		for (int k{1}; k <= M * 2; ++k) a[k] = MP(k, m);
		for (int i{1}; i <= n; ++i)
			for (int ws{w[i] + 1}; ws <= M * 2; ++ws) ans = MA(ans, MM(a[ws - w[i]], dp[i][ws]));

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
