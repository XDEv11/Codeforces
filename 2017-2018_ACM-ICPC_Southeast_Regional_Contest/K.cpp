//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <algorithm>
#include <queue>
#include <stack>

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

bool solve() {
	int n, m;
	if (!(cin >> n >> m)) return false;
	vector<pair<int, int>> a(m);
	for (auto& [x, y] : a) cin >> x >> y;

	auto neg{[&n](int x) { return x ^ 1; }};

	vector<vector<int>> adj(2 * n);
	for (auto& [x, y] : a) {
		x = 2 * (abs(x) - 1) + (x < 0);
		y = 2 * (abs(y) - 1) + (y < 0);
		adj[x ^ 1].push_back(y);
		adj[y ^ 1].push_back(x);
	}

	auto scc{SCC{}(adj)};
	vector<int> idx(2 * n);
	for (int k{0}; k < scc.size(); ++k)
		for (auto& x : scc[k]) idx[x] = k;
	for (int i{0}; i < n; ++i) {
		if (idx[2 * i] == idx[2 * i + 1]) return cout << "0\n", true;
	}

	vector<bool> f0(scc.size()), f1(scc.size());
	vector<int> cnt(scc.size());
	for (int u{0}; u < scc.size(); ++u)
		for (auto& x : scc[u])
			for (auto& y : adj[x]) {
				auto v{idx[y]};
				if (v == u) continue;
				++cnt[v];
			}
	queue<int> ts{};
	stack<int> its{};
	for (int v{0}; v < scc.size(); ++v) {
		if (!cnt[v]) ts.push(v);
	}
	while (!ts.empty()) {
		auto u{ts.front()}; ts.pop();
		its.push(u);
		for (auto& x : scc[u]) {
			if ((x & 1) == 0) f0[u] = true;
		}
		for (auto& x : scc[u])
			for (auto& y : adj[x]) {
				auto v{idx[y]};
				if (v == u) continue;
				if (f0[u]) f0[v] = true;
				if (!--cnt[v]) ts.push(v);
			}
	}
	while (!its.empty()) {
		auto u{its.top()}; its.pop();
		for (auto& x : scc[u])
			for (auto& y : adj[x]) {
				auto v{idx[y]};
				if (v == u) continue;
				if (f1[v]) f1[u] = true;
			}
		for (auto& x : scc[u]) {
			if ((x & 1) == 1) f1[u] = true;
		}
	}

	int ans{3};
	for (int i{0}; i < n; ++i) {
		queue<int> qu{};
		vector<bool> vis(scc.size());
		vis[idx[2 * i]] = true, qu.push(idx[2 * i]);
		while (!qu.empty()) {
			auto u{qu.front()}; qu.pop();
			for (auto& x : scc[u]) {
				for (auto& y : adj[x]) {
					auto v{idx[y]};
					if (vis[v]) continue;
					vis[v] = true, qu.push(v);
				}
			}
		}
		if (vis[idx[2 * i + 1]]) ans = min(ans, 1);
		else if (f1[idx[2 * i]] && f0[idx[2 * i + 1]]) {
			fill(vis.begin(), vis.end(), false);
			vis[idx[2 * i + 1]] = true, qu.push(idx[2 * i + 1]);
			while (!qu.empty()) {
				auto u{qu.front()}; qu.pop();
				for (auto& x : scc[u]) {
					for (auto& y : adj[x]) {
						auto v{idx[y]};
						if (vis[v]) continue;
						vis[v] = true, qu.push(v);
					}
				}
			}
			ans = min(ans, !vis[idx[2 * i]] + 1);
		}
	}
	if (ans == 3) ans = -1;

	return cout << ans << '\n', true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
