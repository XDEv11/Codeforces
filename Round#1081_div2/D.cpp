//#pragma GCC optimize ("O3")

#include <iostream>
#include <utility>
#define fi first
#define se second
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	template<typename T>
	T& maximize(T& a, T b) { return a = max(a, b); }
	template<typename T>
	T& minimize(T& a, T b) { return a = max(a, b); }

	vector<int> c{};
	vector<vector<int>> adj{};

	vector<int> h{};
	vector<ll> a{}, s{}, mx{};
	void dfs(int u, int w = -1) {
		h[u] = 0;
		a[u] = 0, s[u] = 0;
		mx[u] = 0;
		int t1{-1}, t2{-1};
		for (auto& v : adj[u]) {
			if (v == w) continue;
			dfs(v, u);
			maximize(h[u], h[v] + 1);
			a[u] += a[v], s[u] += s[v];

			if (h[v] >= t1) t2 = t1, t1 = h[v];
			else if (h[v] > t2) t2 = h[v];
			maximize(mx[u], mx[v]);
		}
		a[u] += s[u], s[u] += c[u];

		for (auto& v : adj[u]) {
			if (v == w) continue;
			maximize(mx[u], s[v] * ((h[v] == t1 ? t2 : t1) + 1));
		}
	}
	void solve() {
		int n;
		cin >> n;
		c.resize(n), adj.assign(n, {});
		for (auto& x : c) cin >> x;
		for (int _{0}; _ < n - 1; ++_) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		h.resize(n), s.resize(n), a.resize(n), mx.resize(n), dfs(0);

		for (int v{0}; v < n; ++v) cout << (a[v] + mx[v]) << ' ';
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
