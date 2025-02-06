//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	const ll PM{998244353};
	ll MA(ll& a, ll b) { return a = (a + b) % PM; }
	ll MS(ll& a, ll b) { return a = (a - b + PM) % PM; }
	void solve() {
		int n;
		cin >> n;
		vector<int> pa(n);
		vector<vector<int>> ch(n);
		pa[0] = -1;
		for (int v{1}; v < n; ++v) {
			cin >> pa[v], --pa[v];
			ch[pa[v]].push_back(v);
		}

		vector<int> d(n);
		d[0] = 0;
		for (int v{1}; v < n; ++v) d[v] = d[pa[v]] + 1;

		vector<pair<int, int>> t{};
		for (int v{1}; v < n; ++v) t.emplace_back(d[v], v);
		sort(t.rbegin(), t.rend());

		vector<ll> ans(n), aux(n);
		for (auto& [_, u] : t) {
			ans[u] = 1;
			if (d[u] + 1 < n) MA(ans[u], aux[d[u] + 1]);
			for (auto& v : ch[u]) MS(ans[u], ans[v]);

			MA(aux[d[u]], ans[u]);
		}
		ans[0] = 1;
		MA(ans[0], aux[1]);

		cout << ans[0] << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
