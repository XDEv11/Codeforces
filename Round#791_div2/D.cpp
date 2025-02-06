//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	long long k;
	cin >> n >> m >> k;
	vector<int> a(n);
	for (auto& x : a) cin >> x;
	vector<vector<int>> adj(n);
	while (m--) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
