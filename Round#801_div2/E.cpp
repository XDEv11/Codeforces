//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

namespace E {
	vector<vector<pair<int, int>>> adj{};
	vector<bool> vvis{}, evis{};
	vector<int> order{};
	vector<vector<int>> ans{};
	void dfs(int u) {
		order.push_back(u);
		if (!vvis[u]) {
			vvis[u] = true;
			for (auto& [v, i] : adj[u])
				if (!evis[i]) {
					evis[i] = true;
					dfs(v);
					order.push_back(u);
				}
		}
	}
	void solve() {
		int m;
		cin >> m;
		vector<pair<int, int>> e(m);
		for (auto& [u, v] : e) cin >> u >> v;
		int n{2 * m + 1};

		adj.assign(n, {});
		for (int i{0}; i < m; ++i) {
			adj[e[i].fi].emplace_back(e[i].se, i);
			adj[e[i].se].emplace_back(e[i].fi, i);
		}

		int idx{0};
		ans.assign(2, vector<int>(m));
		string ptop(m, 'U'), pbot(m, 'D');
		string mtop(m, 'U'), mbot(m, 'D');
		vvis.assign(n, false);
		evis.assign(m, false);
		for (int u{1}; u < n; ++u) {
			if (vvis[u]) continue;
			order.clear();
			dfs(u);
			int k{order.size() / 2};
			if (k == 1) return cout << "-1\n", []{}();

			for (int i{0}; i < k; ++i) {
				ans[0][i + idx] = order[i];
				ans[1][i + idx] = order[2 * k - 1 - i];
			}

			for (int i{0}; i + 1 < k; i += 2) ptop[i + idx] = pbot[i + idx] = 'L', ptop[i + 1 + idx] = pbot[i + 1 + idx] = 'R';
			for (int i{1}; i + 1 < k; i += 2) mtop[i + idx] = mbot[i + idx] = 'L', mtop[i + 1 + idx] = mbot[i + 1 + idx] = 'R';

			idx += k;
		}

		cout << "2 " << m << '\n';
		for (auto& x : ans[0]) cout << x << ' ';
		cout << '\n';
		for (auto& x : ans[1]) cout << x << ' ';
		cout << "\n\n";
		cout << ptop << '\n' << pbot << "\n\n";
		cout << mtop << '\n' << mbot << "\n\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) E::solve();
}
