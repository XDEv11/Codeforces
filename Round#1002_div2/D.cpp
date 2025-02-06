//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <queue>
#include <optional>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

namespace {
	template<typename T>
	using matrix = vector<vector<T>>;

	// Dijkstra algorithm
	template<typename T>
	vector<optional<T>> Dijkstra(const vector<vector<pair<int, T>>>& adj, int s) {
		const auto& n{adj.size()};
		vector<optional<T>> d(n, nullopt);
		d[s] = 0;

		vector<bool> found(n, false);
		using pq_t = pair<T, int>;
		priority_queue<pq_t, vector<pq_t>, greater<pq_t>> pq{};
		pq.emplace(0, s);
		while (!pq.empty()) {
			auto [_, u]{pq.top()}; pq.pop();
			if (found[u]) continue;
			found[u] = true;
			for (auto& [v, w] : adj[u])
				if (!d[v] || d[v] > d[u].value() + w) {
					d[v] = d[u].value() + w;
					pq.emplace(d[v].value(), v);
				}
		}

		return d;
	}

	void solve() {
		int n, s0, s1, m0, m1;
		cin >> n >> s0 >> s1, --s0, --s1;
		cin >> m0;
		vector<pair<int, int>> e0(m0);
		for (auto& [u, v] : e0) {
			cin >> u >> v, --u, --v;
			if (u > v) swap(u, v);
		}
		cin >> m1;
		vector<pair<int, int>> e1(m1);
		for (auto& [u, v] : e1) {
			cin >> u >> v, --u, --v;
			if (u > v) swap(u, v);
		}

		auto tr{[&n](int v0, int v1) { return v0 * n + v1; }};
		matrix<pair<int, int>> adj(n * n);
		set<int> d{};
		for (auto& [u0, v0] : e0)
			for (auto& [u1, v1] : e1) {
				int u{tr(u0, u1)}, v{tr(v0, v1)};
				adj[u].emplace_back(v, abs(v0 - v1));
				adj[v].emplace_back(u, abs(u0 - u1));
				u = tr(u0, v1), v = tr(v0, u1);
				adj[u].emplace_back(v, abs(v0 - u1));
				adj[v].emplace_back(u, abs(u0 - v1));

				if (u0 == u1 && v0 == v1) d.insert(u0), d.insert(v0);
			}

		auto r{Dijkstra(adj, tr(s0, s1))};
		int ans{-1};
		for (auto& v : d) {
			int x;
			if (r[tr(v, v)]) x = r[tr(v, v)].value();
			else continue;

			if (ans == -1) ans = x;
			else ans = min(ans, x);
		}

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
