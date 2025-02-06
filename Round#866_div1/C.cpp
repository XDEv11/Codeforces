//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	for (int i{0}; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int x{-1};
	for (int u{0}; u < n; ++u) {
		if (adj[u].size() == 1) continue;
		int c{0};
		for (auto& v : adj[u]) {
			if (adj[v].size() == 1) continue;
			++c;
		}
		if (c > 2) return cout << "No\n", []{}();
		else if (c == 1) x = u;
	}

	vector<int> ans{};
	if (x == -1) {
		for (int v{0}; v < n; ++v) ans.push_back(v);
	} else {
		bool f{true};
		int y{-1};
		while (true) {
			ans.push_back(x);
			int ny{-1}, nx{-1};
			for (auto& u : adj[x]) {
				if (adj[u].size() == 1 || u == y) continue;
				ny = u;
				for (auto& v : adj[u]) {
					if (adj[v].size() == 1 || v == x) continue;
					nx = v;
					break;
				}
				break;
			}
			if (ny != -1) {
				for (auto& v : adj[ny]) {
					if (adj[v].size() != 1) continue;
					ans.push_back(v);
				}
			}
			if (nx != -1) x = nx, y = ny;
			else if (f) {
				if (ny != -1) x = ny, y = -1;
				else {
					for (auto& v : adj[x]) {
						if (adj[v].size() != 1) continue;
						ans.push_back(v);
					}
					swap(x, y);
				}
				f = false;
			} else break;
		}
	}

	cout << "Yes\n";
	for (auto& v : ans) cout << v + 1 << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
