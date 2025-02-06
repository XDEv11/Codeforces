//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <queue>
#include <optional>
#include <limits>
#include <algorithm>

using namespace std;

// Bellman-Ford algorithm
template<typename T>
optional<vector<optional<T>>> Bellman_Ford(const vector<vector<pair<int, T>>>& adj, int s) {
    const auto& n{adj.size()};
    vector<optional<T>> d(n, nullopt);
    d[s] = 0;

    queue<int> qu{}, qu2{};
    vector<bool> in(n, false), in2(n, false);
    qu.push(s), in[s] = true;
    for (int i{0}; i < n; ++i) { // at most n-1 edges
        while (!qu.empty()) {
            int u{qu.front()};
            qu.pop(), in[u] = false;
            for  (auto& [v, w] : adj[u])
                if (!d[v] || d[v] > d[u].value() + w) { // relax
                    d[v] = d[u].value() + w;
                    if (!in2[v]) qu2.push(v), in2[v] = true;
                }
        }
        qu.swap(qu2), in.swap(in2);
    }

    if (qu.empty()) return d;
    return nullopt; // if negative cycle
}

void solve() {
	using ll = long long;

	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, ll>>> adj(n + 1);
	for (int v{1}; v <= n; ++v) adj[0].emplace_back(v, 0);
	ll mn{numeric_limits<ll>::max()};
	while (m--) {
		int u, v; ll c;
		cin >> u >> v >> c;
		adj[u].emplace_back(v, c);
		mn = min(mn, c);
	}
	if (mn >= 0) return cout << mn << '\n', []{}();

	ll ans{};
	auto d{Bellman_Ford(adj, 0)};
	if (!d) return cout << "-inf\n", []{}();
	for (auto& x : d.value()) ans = min(ans, x.value());

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
