//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

namespace {
	using ll = long long;
	vector<ll> a{};
	vector<vector<int>> ch{};
	ll dfs(int u) {
		if (ch[u].empty()) return a[u];

		ll mn{numeric_limits<ll>::max()};
		for (auto& v : ch[u]) mn = min(mn, dfs(v));
		if (mn <= a[u]) return mn;
		else return a[u] + (mn - a[u]) / 2;
	}
	void solve() {
		int n;
		cin >> n;
		a.resize(n);
		for (auto& x : a) cin >> x;
		ch.assign(n, {});
		for (int v{1}; v < n; ++v) {
			int u;
			cin >> u, --u;
			ch[u].push_back(v);
		}

		ll mn{numeric_limits<ll>::max()};
		for (auto& v : ch[0]) mn = min(mn, dfs(v));

		cout << a[0] + mn << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
