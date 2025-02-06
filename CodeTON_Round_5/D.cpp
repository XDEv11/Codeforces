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
	vector<vector<pair<int, ll>>> adj(n);
	for (int i{0}; i < m; ++i) {
		int u, v; ll w;
		cin >> u >> v >> w, --u, --v;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	auto w{Dijkstra(adj, n - 1)};
	if (!w[0]) return cout << "inf\n", []{}();

	vector<pair<vector<bool>, ll>> ans{};
	vector<pair<ll, int>> t(n);
	for (int i{0}; i < n; ++i) t[i] = {min(w[0].value(), w[i].value_or(numeric_limits<ll>::max())), i};
	sort(t.begin(), t.end());
	vector<bool> ck(n, true);
	for (int j{0}, k{j}; ; j = k) {
		while (k < n && t[k].fi == t[j].fi) ck[t[k++].se] = false;
		if (k == n) break;
		ans.emplace_back(ck, t[k].fi - t[j].fi);
	}

	cout << t[n - 1].fi << ' ' << ans.size() << '\n';
	for (auto& [a1, a2] : ans) {
		for (int i{0}; i < n; ++i) cout << a1[i];
		cout << ' ' << a2 << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
