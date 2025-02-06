#include <iostream>
#include <vector>
#include <map>
#include <utility>
#define fi first
#define se second
#include <queue>
#include <algorithm>

using namespace std;

bool solve() {
	int n, m, p, l;
	if (!(cin >> n >> m >> p >> l)) return false;
	vector<vector<array<int, 2>>> adj(n);
	for (int i{0}; i < m; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
	}
	vector<vector<int>> a(p, vector<int>(l));
	for (auto& x : a)
		for (auto& v : x) cin >> v, --v;
	int vs, vt;
	cin >> vs >> vt, --vs, --vt;

	map<pair<int, int>, int> idx{};
	for (int u{0}; u < n; ++u)
		for (auto& [v, i] : adj[u]) idx[{u, v}] = i;

	vector<vector<int>> t(m);
	for (int k{0}; k < l; ++k)
		for (int i{0}; i < p; ++i) {
			int ii{idx[{a[i][k], a[i][(k + 1) % l]}]};
			if (!t[ii].empty() && t[ii].back() == k) continue;
			t[ii].push_back(k);
		}

	vector<map<int, int>> wt(m);
	for (int i{0}; i < m; ++i) {
		int z{t[i].size()};
		if (!z) continue;
		if (z == l) {
			for (int k{0}; k < l; ++k) wt[i][k] = -1;
			continue;
		}
		for (int j{0}, k; ; j = k + 1) {
			k = j;
			while ((t[i][k] + 1) % l == t[i][(k + 1) % z]) k = (k + 1) % z;
			for (int ii{k}, tmp{1}; ; ii = (ii - 1 + z) % z, ++tmp) {
				wt[i][t[i][ii]] = tmp;
				if (ii == j) break;
			}
			if (k < j || k == z - 1) break;
		}
	}

	using ll = long long;
	vector<bool> s(n);
	vector<ll> ans(n);
	priority_queue<pair<ll, int>> pq{};
	pq.emplace(0, vs);
	while (!pq.empty()) {
		auto [d, u]{pq.top()}; d *= -1, pq.pop();
		if (s[u]) continue;
		s[u] = true, ans[u] = d;
		for (auto& [v, i] : adj[u]) {
			if (s[v]) continue;
			if (wt[i].count(d % l)) {
				int x{wt[i][d % l]};
				if (x == -1) continue;
				pq.emplace(-(d + x + 1), v);
			} else pq.emplace(-(d + 1), v);
		}
	}

	if (s[vt]) cout << ans[vt] << '\n';
	else cout << "IMPOSSIBLE\n";
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (solve()) ;
}
