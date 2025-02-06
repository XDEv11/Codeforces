//#pragma GCC optimize ("O3")

#include <iostream>
#include <utility>
#define fi first
#define se second
#include <vector>
#include <queue>
#include <optional>
#include <algorithm>
#include <limits>

using namespace std;

// Dijkstra algorithm
template<typename T>
vector<optional<T>> Dijkstra(const vector<vector<pair<int, T>>>& adj, int s) {
	const auto& n{adj.size()};
	vector<optional<T>> d(n, nullopt);
	d[s] = 0;

	using pq_t = pair<T, int>;
	priority_queue<pq_t, vector<pq_t>, greater<pq_t>> pq{};
	pq.emplace(d[s].value(), s);
	while (!pq.empty()) {
		auto [_, u]{pq.top()}; pq.pop();
		if (_ != d[u].value()) continue;
		for (auto& [v, c] : adj[u]) {
			if (!d[v] || d[v].value() > d[u].value() + c) {
				d[v] = d[u].value() + c;
				pq.emplace(d[v].value(), v);
			}
		}
	}

	return d;
}

namespace {
	using ll = long long;
	void solve() {

		int n, m, w;
		cin >> n >> m >> w, --w;
		vector<vector<pair<int, ll>>> adl(n), adr(n);
		while (m--) {
			int u, v; ll l, r;
			cin >> u >> v >> l >> r, --u, --v;
			adl[u].emplace_back(v, l), adl[v].emplace_back(u, l);
			adr[u].emplace_back(v, r), adr[v].emplace_back(u, r);
		}

		auto d{Dijkstra(adr, w)};

		vector<ll> t(n, numeric_limits<ll>::max());
		t[0] = -d[0].value();

		vector<bool> found(n, false);
		using pq_t = pair<ll, int>;
		priority_queue<pq_t, vector<pq_t>, greater<pq_t>> pq{};
		pq.emplace(t[0], 0);
		while (!pq.empty()) {
			auto [_, u]{pq.top()}; pq.pop();
			if (found[u] || t[u] >= d[u].value()) continue;
			found[u] = true;
			for (auto& [v, c] : adl[u]) {
				ll x{max(-d[v].value(), t[u] + c)};
				if (t[v] > x) t[v] = x, pq.emplace(x, v);
			}
		}

		cout << (found[n - 1] ? "YES\n" : "NO\n");
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
