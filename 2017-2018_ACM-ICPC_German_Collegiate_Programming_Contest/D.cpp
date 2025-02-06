#include <iostream>
#include <vector>
#include <string>
#include <utility>
#define fi first
#define se second
#include <map>
#include <queue>

using namespace std;

bool solve() {
	int n, m;
	if (!(cin >> n >> m)) return false;
	vector<pair<string ,string>> a(n), b(m);
	for (auto& [x, y] : a) cin >> x >> y >> y >> y >> y;
	for (auto& [x, y] : b) cin >> x >> y >> y >> y >> y;

	vector<vector<int>> adj{};
	map<string, int> mp{};
	int sz{0};
	for (auto& [x, y] : a) {
		int idx{mp.count(x) ? mp[x] : (mp[x] = sz++)};
		int idy{mp.count(y) ? mp[y] : (mp[y] = sz++)};
		adj.resize(sz);
		adj[idx].push_back(idy);
	}

	vector<int> ans(m);
	for (int i{0}; i < m; ++i) {
		auto& [x, y]{b[i]};
		if (mp.count(x) && mp.count(y)) {
			int idx{mp[x]}, idy{mp[y]};
			bool f{false};
			{
				queue<int> qu{};
				qu.push(idx);
				while (!qu.empty()) {
					auto u{qu.front()}; qu.pop();
					if (u == idy) {
						f = true;
						break;
					}
					for (auto& v : adj[u]) qu.push(v);
				}
			}
			if (f) {
				ans[i] = 0;
				continue;
			}
			{
				queue<int> qu{};
				qu.push(idy);
				while (!qu.empty()) {
					auto u{qu.front()}; qu.pop();
					if (u == idx) {
						f = true;
						break;
					}
					for (auto& v : adj[u]) qu.push(v);
				}
			}
			if (f) {
				ans[i] = 1;
				continue;
			}
		}
		ans[i] = 2;
	}

	for (auto& x : ans) {
		switch (x) {
			break; case 0: cout << "Fact\n";
			break; case 1: cout << "Alternative Fact\n";
			break; case 2: cout << "Pants on Fire\n";
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
