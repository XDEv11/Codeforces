//#pragma GCC optimize ("O3")

#include <iostream>
#include <utility>
#define fi first
#define se second
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;

		vector<vector<pair<int, int>>> adj(n + 1);
		for (int i{0}; i < n; ++i) {
			if (a[i] == b[i]) continue;
			adj[a[i]].emplace_back(b[i], i);
			adj[b[i]].emplace_back(a[i], i);
		}

		vector<bool> vis(n), dir(n);
		for (int k{1}; k <= n; ++k) {
			int u{k};
			bool f;
			do {
				f = false;
				while (!f && !adj[u].empty()) {
					auto [v, i]{adj[u].back()};
					adj[u].pop_back();
					if (vis[i]) continue;

					f = vis[i] = true;
					if (a[i] == v) dir[i] = 1;
					u = v;
				}
			} while (f);
			if (u != k) return void(cout << "-1\n");
		}

		vector<int> ans{};
		for (int i{0}; i < n; ++i) {
			if (dir[i]) ans.push_back(i);
		}
		cout << ans.size() << '\n';
		for (auto& x : ans) cout << (x + 1) << ' ';
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
