//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <utility>
#define fi first
#define se second
#include <algorithm>
#include <optional>
#include <queue>
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

bool solve() {
	int n, t, ag1, ag2;
	if (!(cin >> n >> t >> ag1 >> ag2)) return false;
	--t;
	map<pair<int, int>, int> angle{};
	vector<vector<array<int, 3>>> g(n);
	vector<int> dst{};
	int c{1};
	for (int u{0}; u < n; ++u) {
		int m;
		cin >> m;
		g[u].resize(m);
		for (auto& [v, w, k] : g[u]) {
			int a;
			cin >> v >> w >> a, --v, k = v ? c++ : 0;
			angle[{u, v}] = a;
			if (v == t) dst.push_back(k);
		}
	}

	auto inside{[&ag1, &ag2](int a1, int a2) {
		a1 = (a1 + 180) % 360;
		int l{(a1 - ag2 + 360) % 360}, r{(a1 + ag1) % 360};
		if (l <= r) return l <= a2 && a2 <= r;
		else return l <= a2 || a2 <= r;
	}};

	vector<vector<pair<int, int>>> adj(c);
	for (auto& [v, w, k] : g[0]) adj[0].emplace_back(k, w);
	for (int u{0}; u < n; ++u)
		for (auto& [v1, w1, k1] : g[u]) {
			if (!v1) continue;
			for (auto& [v2, w2, k2] : g[v1]) {
				if (!inside(angle[{v1, u}], angle[{v1, v2}])) continue;
				adj[k1].emplace_back(k2, w2);
			}
		}

	int ans{numeric_limits<int>::max()};
	auto d1{Dijkstra(adj, 0)};
	for (auto& v : dst) {
		if (!d1[v]) continue;
		auto d2{Dijkstra(adj, v)};
		if (!d2[0]) continue;
		ans = min(ans, d1[v].value() + d2[0].value());
	}

	if (ans == numeric_limits<int>::max()) cout << "impossible\n";
	else cout << ans << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
