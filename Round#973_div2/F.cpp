//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	vector<vector<int>> adj{};
	vector<int> p{}, d{}, h{};
	void dfs(int u, int w = -1) {
		p[u] = w;
		d[u] = (w == -1 ? 0 : (d[w] + 1));
		h[u] = 0;
		for (auto& v : adj[u]) {
			if (v == w) continue;
			dfs(v, u);
			h[u] = max(h[u], h[v] + 1);
		}
	}
	void solve() {
		int n;
		cin >> n;
		adj.assign(n, {});
		for (int i{0}; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int s;
		cin >> s >> s, --s;

		p.resize(n), d.resize(n), h.resize(n), dfs(0);

		int mxA{}, mxB{h[s]};

		int x{s}, y{x};
		for (int i{1}; i < d[s] - 1; ++i) {
			y = x, x = p[x];
			for (auto& z : adj[x]) {
				if (z == y) continue;
				if (i < (d[s] - 1) / 2) {
					mxB = max(mxB, i + (h[z] + 1));
				} else {
					mxA = max(mxA, (d[s] - 1 - i) + (h[z] + 1));
				}
			}
		}
		for (auto& v : adj[0]) {
			if (v == x) continue;
			mxA = max(mxA, h[v] + 1);
		}

		cout << (mxA > mxB ? "Alice\n" : "Bob\n");
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
