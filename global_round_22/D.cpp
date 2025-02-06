//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> b(n + 1);
	for (int i{1}; i <= n; ++i) cin >> b[i];

	int k{0};
	for (int i{1}; i <= n; ++i) {
		if (b[i] > i) k = i;
	}

	vector<vector<int>> adj(n + 2);
	for (int i{1}; i <= n; ++i) adj[b[i]].push_back(i);

	cout << k << '\n';
	int u{adj[0].empty() ? n + 1 : 0};
	while (true) {
		int t{-1};
		for (auto& v : adj[u]) {
			if (adj[v].empty()) cout << v << ' ';
			else t = v;
		}
		if (t == -1) break;
		cout << (u = t) << ' ';
		cout << flush;
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
