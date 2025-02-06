//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>
#include <queue>
#include <set>
#include <map>

using namespace std;

template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& x) {
	return os << "(" << x.fi << ", " << x.se << ")";
}

namespace D {
	using ll = long long;
	using vertex_t = pair<int, int>;
	using value_t = pair<ll, ll>;
	using pq_t = pair<value_t, vertex_t>;
	bool value_gt(const value_t& x, const value_t& y) {
		return x.fi > y.fi || (x.fi == y.fi && x.se < y.se);
	}
	void solve() {
		int n, m; ll p;
		cin >> n >> m >> p;
		vector<ll> cp(n);
		for (auto& x : cp) cin >> x;
		vector<vector<pair<int, ll>>> adj(n);
		while (m--) {
			int u, v; ll w;
			cin >> u >> v >> w, --u, --v;
			adj[u].emplace_back(v, w);
		}

		set<vertex_t> found{};
		map<vertex_t, value_t> d{};
		struct pq_cmp { bool operator()(const pq_t& x, const pq_t& y) const { return value_gt(x.fi, y.fi); } };
		priority_queue<pq_t, vector<pq_t>, pq_cmp> pq{};
		d[{0, 0}] = {0, p}, pq.emplace(vertex_t{0, p}, value_t{0, 0});
		while (!pq.empty()) {
			auto [uw, u]{pq.top()}; pq.pop();
			if (found.count(u)) continue;
			found.insert(u);
			for (auto& [vfi, w] : adj[u.fi]) {
				ll vse{(value_t{cp[vfi], vfi} > value_t{cp[u.se], u.se} ? vfi : u.se)};
				vertex_t v{vfi, vse};
				value_t vw{uw};
				ll k{(max(0ll, (w - vw.se)) + cp[u.se] - 1) / cp[u.se]}; vw.fi += k, vw.se += k * cp[u.se] - w;
				if (!d.count(v) || value_gt(d[v], vw)) {
					d[v] = vw;
					pq.emplace(vw, v);
				}
			}
		}

		ll ans{-1};
		for (auto& [k, v] : d) {
			if (k.fi == n - 1 && (ans == -1 || ans > v.fi)) ans = v.fi;
		}
		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) D::solve();
}
