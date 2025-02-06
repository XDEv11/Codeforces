#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>
#include <limits>
#include <cmath>
#include <functional>
#include <iomanip>

#define fi first
#define se second

using namespace std;

class DSU {
private:
	vector<int> p{}, w{};
public:
	DSU(int n) : p(n, -1), w(n, 1) {}
	int find(int x) {
		if (p[x] == -1) return x;
		return p[x] = find(p[x]);
	}
	void unionn(int x, int y) {
		auto rx{find(x)}, ry{find(y)};
		if (rx == ry) return ;
		if (w[rx] > w[ry]) p[ry] = rx, w[rx] += w[ry];
		else p[rx] = ry, w[ry] += w[rx];
	}
};

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int, vector<int>>> adj(n);
	for (auto& x : adj) cin >> x.fi, --x.fi;
	while (m--) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].se.push_back(v);
		adj[v].se.push_back(u);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
