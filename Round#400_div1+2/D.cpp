//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <stack>
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

bool solve() {
	int n, m;
	if (!(cin >> n >> m)) return false;
	vector<bool> c(n);
	for (int i{0}; i < n; ++i) {
		int x;
		cin >> x;
		c[i] = x;
	}
	vector<array<int, 2>> v(n, {-1, -1});
	for (int i{0}; i < m; ++i) {
		int k;
		cin >> k;
		while (k--) {
			int x;
			cin >> x, --x;
			v[x][v[x][0] == -1 ? 0 : 1] = i;
		}
	}

	vector<vector<int>> adj(2 * m);
	for (int i{0}; i < n; ++i) {
		auto& [x, y]{v[i]};
		adj[2 * x].push_back(2 * y + !c[i]);
		adj[2 * y].push_back(2 * x + !c[i]);
		adj[2 * x + 1].push_back(2 * y + c[i]);
		adj[2 * y + 1].push_back(2 * x + c[i]);
	}

	auto scc{SCC{}(adj)};
	for (auto& cp : scc) {
		sort(cp.begin(), cp.end());
		for (int i{0}; i + 1 < cp.size(); ++i) {
			if (cp[i] & 1) continue;
			if (cp[i] + 1 == cp[i + 1]) return cout << "NO\n", true;
		}
	}
	return cout << "YES\n", true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
