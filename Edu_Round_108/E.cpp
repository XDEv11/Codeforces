#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <numeric>
#include <map>
#include <algorithm>

using namespace std;

namespace E {
	using ll = long long;

	vector<vector<pair<ll, int>>> adj{};
	vector<int> vis{};
	vector<pair<int, int>> ans{};
	bool dfs(int u, int i = -1) {
		vis[u] = 1;
		int k{-1};
		for (auto& [v, j] : adj[u]) {
			if (vis[v] == 1) continue; // backward
			if (vis[v] == 0 && dfs(v, j)) continue;
			if (k == -1) k = j;
			else ans.emplace_back(k, j), k = -1;
		}
		vis[u] = 2;
		if (k == -1 || i == -1) return false;
		else return ans.emplace_back(k, i), true;
	}
	void solve() {
		int n;
		cin >> n;
		adj.clear();
		map<pair<ll, ll>, int> mp{};
		for (int i{0}; i < n; ++i) {
			ll a, b, c, d;
			cin >> a >> b >> c >> d;
			int t1, t2;
			{
				ll num{(a + b) * d}, den{b * c}, g{gcd(num, den)};
				num /= g, den /= g;
				if (!mp.count({num, den})) mp[{num, den}] = mp.size();
				t1 = mp[{num, den}];
			}
			{
				ll num{a * d}, den{b * (c + d)}, g{gcd(num, den)};
				num /= g, den /= g;
				if (!mp.count({num, den})) mp[{num, den}] = mp.size();
				t2 = mp[{num, den}];
			}
			adj.resize(mp.size());
			adj[t1].emplace_back(t2, i);
			adj[t2].emplace_back(t1, i);
		}

		vis.assign(adj.size(), 0);
		ans.clear();
		for (int u{0}; u < adj.size(); ++u) {
			if (vis[u] == 0) dfs(u);
		}

		cout << ans.size() << '\n';
		for (auto& [a, b] : ans) cout << a + 1 << ' ' << b + 1 << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) E::solve();
}
