//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <utility>

using namespace std;

// fast disjoint set union
class DSU {
	vector<int> p, sz;
public:
	explicit DSU(int n) : p(n, -1), sz(n, 1) {}
	int findr(int x) { // collapsing find
		return p[x] == -1 ? x : p[x] = findr(p[x]);
	}
	int finds(int x) {
		return sz[findr(x)];
	}
	void unionn(int x, int y) { // weighted union
		auto rx{findr(x)}, ry{findr(y)};
		if (rx == ry) return ;
		if (sz[rx] < sz[ry]) swap(rx, ry);
		p[ry] = rx, sz[rx] += sz[ry];
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (auto& x : a) cin >> x;
	vector<vector<int>> adj(n);
	while (m--) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> vis(n);
	queue<int> qu{};
	qu.push(0), vis[0] = 1;
	while (!qu.empty()) {
		auto u{qu.front()}; qu.pop();
		vis[u] = 2;
		for (auto& v : adj[u]) {
			if (vis[v]) continue;
			qu.push(v), vis[v] = 1;
		}
	}
	if (count(vis.begin(), vis.end(), 2) != n) return cout << "NO\n", []{}();

	DSU dsu{n};
	fill(vis.begin(), vis.end(), 0);
	vector<set<pair<int, int>>> st(n);
	for (int i{0}; i < n; ++i) {
		if (!(a[i] == 0 && vis[i] == 0)) continue;
		st[i].emplace(a[i], i), vis[i] = 1;
		while (!st[i].empty()) {
			auto [val, u]{*st[i].begin()};
			if (val > dsu.finds(i)) break;
			st[i].erase(st[i].begin());
			vis[u] = 2;
			dsu.unionn(i, u);
			for (auto& v : adj[u]) {
				if (vis[v] == 0) st[i].emplace(a[v], v), vis[v] = 1;
				else if (vis[v] == 2 && dsu.findr(v) != dsu.findr(i)) {
					int vr{dsu.findr(v)};
					dsu.unionn(i, vr);
					for (auto& [_, w] : st[vr]) {
						if (vis[w] == 0) st[i].emplace(a[w], w), vis[w] = 1;
					}
					st[vr].clear();
				}
			}
		}
		for (auto& [_, w] : st[i]) {
			vis[w] = 0;
		}
	}
	cout << (count(vis.begin(), vis.end(), 2) != n ? "NO\n" : "YES\n");
}

void solve2() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (auto& x : a) cin >> x;
	vector<vector<int>> adj(n);
	while (m--) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	{
	vector<bool> vis(n, false);
	queue<int> qu{};
	qu.push(0), vis[0] = true;
	while (!qu.empty()) {
		auto u{qu.front()}; qu.pop();
		for (auto& v : adj[u]) {
			if (vis[v]) continue;
			qu.push(v), vis[v] = true;
		}
	}
	if (count(vis.begin(), vis.end(), true) != n) return cout << "NO\n", []{}();
	}

	{
	vector<bool> vis(n, false);
	set<int> st{};
	for (int i{0}; i < n; ++i) {
		if (a[i] == 0) st.insert(i);
	}
	while (!st.empty()) {
		auto s{*st.begin()}; st.erase(st.begin());
		int cnt{0};
		set<pair<int, int>> qu{};
		queue<int> dt{};
		qu.emplace(a[s], s), vis[s] = true, dt.push(s);
		while (!qu.empty()) {
			auto [val, u]{*qu.begin()}; qu.erase(qu.begin());
			if (val > cnt) break;
			++cnt, st.erase(u);
			for (auto& v : adj[u]) {
				if (vis[v]) continue;
				qu.emplace(a[v], v), vis[v] = true, dt.push(v);
			}
		}
		if (cnt == n) return cout << "YES\n", []{}();
		while (!dt.empty()) {
			auto u{dt.front()}; dt.pop();
			vis[u] = false;
		}
	}
	cout << "NO\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve2();
}
