//#pragma GCC optimize ("O3")

#include <iostream>
#include <utility>
#define fi first
#define se second
#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	using pii = pair<int, int>;
	using pli = pair<ll, int>;
	int n, m;
	vector<ll> a{};
	vector<basic_string<int>> adj{};

	vector<ll> s{};
	vector<pii> ht{};
	void dfs1(int u = 0, int w = -1) {
		ht[u] = {0, u};
		for (auto& v : adj[u]) {
			if (v == w) continue;
			dfs1(v, u);
			ht[u] = min(ht[u], {ht[v].fi - 1, ht[v].se});
		}
		s[ht[u].se] += a[u];
	}

	ll ans, sum;
	priority_queue<ll, vector<ll>, greater<>> pq0{}, bd0{};
	priority_queue<ll> pq1{}, bd1{};
	void chg(int v, ll x) {
		if (!pq0.empty() && s[v] >= pq0.top()) {
			sum -= s[v], bd0.push(s[v]);
			while (!bd0.empty() && bd0.top() == pq0.top()) pq0.pop(), bd0.pop();
		} else {
			bd1.push(s[v]);
			while (!bd1.empty() && bd1.top() == pq1.top()) pq1.pop(), bd1.pop();
		}
		s[v] += x;
		if (!pq0.empty() && s[v] >= pq0.top()) sum += s[v], pq0.push(s[v]);
		else pq1.push(s[v]);
	}
	void upd() {
		while (pq0.size() - bd0.size() > m) {
			sum -= pq0.top(), pq1.push(pq0.top()), pq0.pop();
			while (!bd0.empty() && bd0.top() == pq0.top()) pq0.pop(), bd0.pop();
		}
		while (pq0.size() - bd0.size() < m) {
			sum += pq1.top(), pq0.push(pq1.top()), pq1.pop();
			while (!bd1.empty() && bd1.top() == pq1.top()) pq1.pop(), bd1.pop();
		}
	}
	void dfs2(int u = 0, int w = -1, pii mn0 = {1, -1}) {
		chg(ht[u].se, -a[u]);
		upd(), ans = max(ans, a[u] + sum);

		int v1;
		pii mn1{ht[u]}, mn2{0, u};
		for (auto& v : adj[u]) {
			if (v == w) continue;
			auto t{ht[v]}; --t.fi;
			if (t == mn1) v1 = v;
			else mn2 = min(mn2, t);
		}
		mn1 = min(mn1, mn0), mn2 = min(mn2, mn0);
		for (auto& v : adj[u]) {
			if (v == w) continue;
			if (v != v1) {
				chg(mn1.se, a[u]);
				dfs2(v, u, {mn1.fi - 1, mn1.se});
				chg(mn1.se, -a[u]);
			} else {
				chg(mn2.se, a[u]);
				dfs2(v, u, {mn2.fi - 1, mn2.se});
				chg(mn2.se, -a[u]);
			}
		}

		chg(ht[u].se, a[u]);
	}
	void solve() {
		cin >> n >> m;
		a.resize(n), adj.assign(n, {});
		for (auto& x : a) cin >> x;
		for (int _{}; _ < n - 1; ++_) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v), adj[v].push_back(u);
		}

		s.assign(n, 0), ht.resize(n);
		dfs1();

		ans = sum = 0, pq0 = bd0 = {}, pq1 = bd1 = {};
		for (int v{0}; v < n; ++v) {
			if (adj[v].size() > 1) continue;
			pq1.push(s[v]);
		}
		m = min(int(pq1.size()), m - 1);
		dfs2();

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
