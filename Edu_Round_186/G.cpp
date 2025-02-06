//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	const int MAXN{300000};
	using ll = long long;
	const ll PM{998244353};
	ll MC(ll a) { return (a % PM + PM) % PM; }
	ll MA(ll a, ll b) { return (a + b) % PM; }
	ll& MAA(ll& a, ll b) { return a = MA(a, b); }
	ll MS(ll a, ll b) { return (a - b + PM) % PM; }
	ll& MSA(ll& a, ll b) { return a = MS(a, b); }
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
	vector<ll> MF{[] {
		vector<ll> t(MAXN + 1);
		t[0] = 1;
		for (int i{1}; i <= MAXN; ++i) t[i] = MM(t[i - 1], i);
		return t;
	}()};

	int n, m;
	vector<int> p{};
	vector<vector<int>> ch{};

	vector<vector<ll>> dp{};
	vector<ll> mz{}, az{}; // lazy multiplier and addend
	ll get(int v, int i) {
		return MA(MM(dp[v][max(0, int(dp[v].size()) - 1 - i)], mz[v]), az[v]);
	}
	void dfs(int u) {
		if (ch[u].empty()) {
			dp[u] = {1}, mz[u] = 1, az[u] = 0;
			return ;
		}

		ll a{MF[ch[u].size() - 1]}; int b{};
		int w{-1}, ss{1}; // child with largest dp and second largest size
		for (auto& v : ch[u]) {
			dfs(v);
			dp[v].push_back(MD(MS(0, az[v]), mz[v]));
			if (w == -1) w = v;
			else if (dp[v].size() > dp[w].size()) ss = dp[w].size(), w = v;
			else if (dp[v].size() > ss) ss = dp[v].size();
			ll t{get(v, m - 1)};
			if (!t) ++b;
			else a = MM(a, t);
		}

		ll t{get(w, m - 1)};
		if (b == 0) t = MD(a, t);
		else if (b == 1 && !t) t = a;
		else t = 0;
		if (t) mz[w] = MM(mz[w], t), az[w] = MM(az[w], t);
		else dp[w].assign(ss, 0), mz[w] = 1, az[w] = 0;
		swap(dp[u], dp[w]), swap(mz[u], mz[w]), swap(az[u], az[w]);

		for (auto& v : ch[u]) {
			if (v == w) continue;

			t = get(v, m - 1);
			if (b == 0) t = MD(a, t);
			else if (b == 1 && !t) t = a;
			else t = 0;
			MAA(az[u], MM(get(v, n), t));
			for (int i{0}; i < dp[v].size() - 1; ++i) {
				MSA(dp[u][dp[u].size() - 1 - i], MD(MM(get(v, n), t), mz[u]));
				MAA(dp[u][dp[u].size() - 1 - i], MD(MM(get(v, i), t), mz[u]));
			}
		}
	}
	void solve() {
		cin >> n >> m;
		p.resize(n);
		ch.assign(n, {});
		for (int v{1}; v < n; ++v) {
			cin >> p[v], --p[v];
			ch[p[v]].push_back(v);
		}

		dp.resize(n), mz.resize(n), az.resize(n), dfs(0);
		cout << get(0, n) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
