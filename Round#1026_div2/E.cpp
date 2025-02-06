//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <map>
#include <stack>
#include <algorithm>
#include <iterator>

using namespace std;

namespace {
	vector<int> euler_cycle(vector<vector<pair<int, int>>>& adj, int w = 0) {
		int n{adj.size()}, m{};
		for (int v{0}; v < n; ++v) m += adj[v].size();
		m /= 2;

		vector<int> res{};
		stack<pair<int, int>> stk{};
		stk.emplace(w, -1);
		vector<int> nxt(n);
		vector<bool> usd(m);
		while (!stk.empty()) {
			auto [u, i]{stk.top()};
			while (nxt[u] < adj[u].size() && usd[adj[u][nxt[u]].se]) ++nxt[u];
			if (nxt[u] < adj[u].size()) {
				auto [v, j]{adj[u][nxt[u]]};
				++nxt[u], usd[j] = true, stk.emplace(v, j);
			} else {
				if (i != -1) res.push_back(i);
				stk.pop();
			}
		}
		return res;
	}
	void solve() {
		int n;
		cin >> n;
		vector<pair<int, int>> e(n);
		for (auto& [x, y] : e) cin >> x >> y;

		int cx{}, cy{};
		map<int, int> idx{}, idy{};
		for (auto& [x, y] : e) idx[x], idy[y];
		for (auto& [k, i] : idx) i = cx++;
		for (auto& [k, i] : idy) i = cy++;
		for (auto& [x, y] : e) x = idx[x], y = idy[y];

		vector<vector<pair<int, int>>> adj(cx + cy);
		for (int i{0}; i < n; ++i) {
			auto& [x, y]{e[i]};
			y += cx;
			adj[x].emplace_back(y, i);
			adj[y].emplace_back(x, i);
		}

		vector<int> t{};
		for (int v{0}; v < cx + cy; ++v) {
			if (adj[v].size() % 2) t.push_back(v);
		}
		if (t.size() == 2) {
			auto u{t[0]}, v{t[1]};
			adj[u].emplace_back(v, n);
			adj[v].emplace_back(u, n);
		} else if (t.size()) return cout << "NO\n", []{}();

		auto ans{euler_cycle(adj)};
		if (ans.size() < n) return cout << "NO\n", []{}();
		else if (t.size() == 2) rotate(ans.begin(), next(max_element(ans.begin(), ans.end())), ans.end());

		cout << "YES\n";
		for (int i{0}; i < n; ++i) cout << (ans[i] + 1) << " \n"[i == n - 1];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
