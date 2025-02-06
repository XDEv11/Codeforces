//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <optional>
#include <algorithm>

using namespace std;

// Tarjan’s strongly connected components algorithm
class SCC {
    int d;
    vector<int> dfn{}, low{};
    vector<int> sccno{};
    vector<vector<int>> scc{};
    stack<int> s{};
    void dfs(const vector<vector<int>>& adj, int u) {
        low[u] = dfn[u] = ++d;
        s.emplace(u);
        for (auto& v : adj[u]) {
            if (sccno[v]) continue; // cross edge
            if (!dfn[v]) { // tree edge
                dfs(adj, v);
                low[u] = min(low[u], low[v]);
            } else low[u] = min(low[u], dfn[v]); // forward / back / cross edge
        }
        if (low[u] == dfn[u]) { // first vertex of a scc
            scc.emplace_back();
            while (true) {
                int x{s.top()}; s.pop();
                sccno[x] = scc.size(), scc.back().push_back(x);
                if (x == u) break;
            }
        }
    }
public:
    SCC()=default;
    vector<vector<int>> operator()(const vector<vector<int>>& adj) {
        int n{adj.size()};
        d = 0, dfn.assign(n, 0), low.resize(n), sccno.assign(n, 0);
        for (int i{0}; i < n; ++i) if (!dfn[i]) dfs(adj, i);
        return move(scc);
    }
};

// topological sort 1
optional<vector<int>> top_sort(vector<vector<int>>& adj) {
    vector<int> res{};
    int n{static_cast<int>(adj.size())};
    vector<int> cnt(n, 0); // predecessor count
    for (int u{0}; u < n; ++u)
        for (auto& v : adj[u]) ++cnt[v];

    queue<int> qu{};
    for (int u{0}; u < n; ++u) if (!cnt[u]) qu.push(u);
    while (!qu.empty()) {
        auto u{qu.front()}; qu.pop();
        res.push_back(u);

        for (auto& v : adj[u])
            if (!--cnt[v]) qu.push(v);
    }

    if (res.size() != adj.size()) return nullopt;
    return res;
}

bool solve() {
	int m1, n, M, m2;
	if (!(cin >> m1 >> n >> M >> m2)) return false;
	vector<vector<int>> adj(2 * n + 2 * M);
	for (int i{1}; i + 1 < M; ++i) {
		adj[2 * n + 2 * (i + 1)].push_back(2 * n + 2 * i);
		adj[2 * n + 2 * i + 1].push_back(2 * n + 2 * (i + 1) + 1);
	}
	while (m1--) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[2 * u + 1].push_back(2 * v);
		adj[2 * v + 1].push_back(2 * u);
	}
	for (int v{0}; v < n; ++v) {
		int l, r;
		cin >> l >> r, --l;
		if (l > 0) {
			adj[2 * v].push_back(2 * n + 2 * l);
			adj[2 * n + 2 * l + 1].push_back(2 * v + 1);
		}
		if (r < M) {
			adj[2 * v].push_back(2 * n + 2 * r + 1);
			adj[2 * n + 2 * r].push_back(2 * v + 1);
		}
	}
	while (m2--) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[2 * u].push_back(2 * v + 1);
		adj[2 * v].push_back(2 * u + 1);
	}

	auto scc{SCC{}(adj)};
	vector<int> sccid(2 * n + 2 * M);
	for (int i{0}; i < scc.size(); ++i) {
		for (auto& v : scc[i]) sccid[v] = i;
	}
	for (int i{0}; i < n + M; ++i) {
		if (sccid[2 * i] == sccid[2 * i + 1]) return cout << "-1\n", true;
	}
	vector<vector<int>> sccadj(scc.size());
	for (int i{0}; i < scc.size(); ++i)
		for (auto& u : scc[i])
			for (auto& v : adj[u]) {
				if (sccid[v] == i) continue;
				sccadj[i].push_back(sccid[v]);
			}
	for (auto& v : sccadj) {
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
	}

	vector<int> ans(n + M, -1);
	auto ts{top_sort(sccadj)};
	for (auto& i : ts.value())
		for (auto& v : scc[i]) {
			if (ans[v / 2] != -1) continue;
			ans[v / 2] = v & 1;
		}

	vector<int> res{};
	for (int v{0}; v < n; ++v) {
		if (!ans[v]) continue;
		res.push_back(v);
	}
	int l{0}, r{M};
	while (r - l > 1) {
		int m{(l + r) / 2};
		if (ans[n + m]) l = m;
		else r = m;
	}

	cout << res.size() << ' ' << (l + 1) << '\n';
	for (auto& v : res) cout << (v + 1) << ' ';
	cout << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
