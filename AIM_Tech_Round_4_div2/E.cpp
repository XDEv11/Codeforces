//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

namespace E {
	int n;
	vector<vector<int>> adj{};
	int c1, c2;
	int dfs1(int u = 0, int w = -1) {
		bool f{true};
		int sz{1};
		for (auto& v : adj[u]) {
			if (v == w) continue;
			int cs{dfs1(v, u)};
			sz += cs;
			if (cs > n / 2) f = false;
		}
		if (n - sz > n / 2) f = false;
		if (f) (c1 == -1 ? c1 : c2) = u;
		return sz;
	}
	vector<array<int, 3>> ans{};
	vector<int> link1{}, link2{};
	array<int, 2> append(array<int, 2> lst1, array<int, 2> lst2) {
		if (lst1[0] == -1) return lst2;
		(lst1[0] == lst1[1] ? link1 : link2)[lst1[1]] = lst2[0];
		(lst2[0] == lst2[1] ? link1 : link2)[lst2[0]] = lst1[1];
		return {lst1[0], lst2[1]};
	}
	array<int, 2> dfs2(int u, int w) {
		array<int, 2> lst{-1, -1};
		int y{w};
		for (auto& v : adj[u]) {
			if (v == w) continue;
			auto x{dfs2(v, u)};
			ans.push_back({y, u, x[1]}), y = x[0];
			swap(x[0], x[1]), lst = append(lst, x);
		}
		return lst = append(lst, {u, u});
	}
	bool solve() {
		if (!(cin >> n)) return false;
		adj.assign(n, {});
		for (int _{0}; _ < n - 1; ++_) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		c1 = c2 = -1, dfs1();

		link1.resize(n), link2.resize(n), ans.clear();
		for (auto& v : adj[c1]) {
			if (v == c2) continue;
			auto lst{dfs2(v, c1)};
			int x{lst[1]}, y{-1}, z{-1};
			for (int i{0}; ; ++i) {
				if (i == 0) ;
				else if (i == 1) z = x;
				else if (i == 2) ;
				else ans.push_back({x, y, z});
				if (x == lst[0]) break;
				int t{x};
				x = (link1[x] == y ? link2[x] : link1[x]);
				y = t;
			}
			if (z != -1 && x != z) ans.push_back({c1, x, z});
		}
		if (c2 != -1) {
			for (auto& v : adj[c2]) {
				if (v == c1) continue;
				auto lst{dfs2(v, c2)};
				int x{lst[1]}, y{-1}, z{-1};
				for (int i{0}; ; ++i) {
					if (i == 0) ;
					else if (i == 1) z = x;
					else if (i == 2) ;
					else ans.push_back({x, y, z});
					if (x == lst[0]) break;
					int t{x};
					x = (link1[x] == y ? link2[x] : link1[x]);
					y = t;
				}
				if (z != -1 && x != z) ans.push_back({c2, x, z});
			}
		}

		cout << ans.size() << '\n';
		for (auto& [x, y, z] : ans) cout << (x + 1) << ' ' << (y + 1) << ' ' << (z + 1) << '\n';
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (E::solve()) ;
}
