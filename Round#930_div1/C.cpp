//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <optional>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

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
	using ll = long long;

	int n, m;
	cin >> n >> m;
	vector<ll> c(n);
	for (auto& x : c) cin >> x;
	vector<vector<ll>> a(n, vector<ll>(m));
	for (auto& v : a)
		for (auto& x : v) cin >> x;

	vector<vector<pair<int, ll>>> adj(m * n + n);
	for (int v{0}; v < n; ++v)
		for (int k{0}; k < m; ++k) {
			adj[m * n + v].emplace_back(k * n + v, 0);
			adj[k * n + v].emplace_back(m * n + v, c[v]);
		}
	for (int k{0}; k < m; ++k) {
		vector<pair<ll, int>> t(n);
		for (int v{0}; v < n; ++v) t[v] = {a[v][k], v};
		sort(t.begin(), t.end());
		for (int i{0}; i + 1 < n; ++i) {
			auto& [wu, u]{t[i]};
			auto& [wv, v]{t[i + 1]};
			adj[k * n + u].emplace_back(k * n + v, 0);
			adj[k * n + v].emplace_back(k * n + u, wv - wu);
		}
	}

	cout << Dijkstra(adj, m * n + 0)[m * n + n - 1].value() << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
