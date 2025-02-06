//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <queue>

using namespace std;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<array<int, 4>> c(k);
	for (auto& [x1, y1, x2, y2] : c) cin >> x1 >> y1 >> x2 >> y2, --x1, --y1, --x2, --y2;

	vector<vector<int>> adj1(n + m), adj2{adj1};
	for (auto& [x1, y1, x2, y2] : c) {
		if (y1 + 1 == y2) {
			adj2[x1].push_back(n + y1);
			adj2[n + y1].push_back(x1);
		} else {
			adj1[x1].push_back(n + y2);
			adj1[n + y2].push_back(x1);
		}
	}

	vector<int> vis(adj1.size());
	for (int w{0}; w < adj1.size(); ++w) {
		if (vis[w]) continue;
		queue<int> qu{};
		vis[w] = 1, qu.push(w);
		while (!qu.empty()) {
			auto u{qu.front()}; qu.pop();
			for (auto& v : adj1[u]) {
				if (vis[v]) {
					if (vis[v] != vis[u]) return cout << "NO\n", []{}();
					continue;
				}
				vis[v] = vis[u], qu.push(v);
			}
			for (auto& v : adj2[u]) {
				if (vis[v]) {
					if (vis[v] == vis[u]) return cout << "NO\n", []{}();
					continue;
				}
				vis[v] = -1 * vis[u], qu.push(v);
			}
		}
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
