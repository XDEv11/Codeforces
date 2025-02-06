//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;

	int m;
	vector<ll> b{};
	vector<ll> mn{};
	void bf(ll x, int j = 0, int u = 0) {
		if (j == m) {
			mn[u] = min(mn[u], x);
		} else {
			bf(x, j + 1, u);
			bf(x & b[j], j + 1, u + 1);
		}
	}
	void solve() {
		int n, c;
		cin >> n >> m >> c;
		vector<ll> a(n);
		b.resize(m);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;

		multiset<ll> st{};
		for (int i{0}; i < n; ++i) {
			mn.assign(m + 1, a[i]), bf(a[i]);

			for (int k{0}; k < m; ++k) st.insert(mn[k] - mn[k + 1]);
			while (st.size() > c) st.erase(st.begin());
		}

		ll ans{};
		for (auto& x : a) ans += x;
		for (auto& x : st) ans -= x;

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
