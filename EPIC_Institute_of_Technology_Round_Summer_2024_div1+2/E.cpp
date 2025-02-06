//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n;
		cin >> n;
		vector<ll> a(n);
		for (auto& x : a) cin >> x;
		vector<int> pa(n);
		for (int i{1}; i < n; ++i) cin >> pa[i], --pa[i];

		vector<vector<int>> ch(n);
		for (int i{1}; i < n; ++i) ch[pa[i]].push_back(i);

		ll ans{};
		vector<vector<ll>> b(n, vector<ll>(n, -1));
		for (int u{n - 1}; u >= 0; --u) {
			if (!ch[u].empty()) {
				for (int i{1}; i <= n; ++i) {
					ll t{0};
					for (auto& v : ch[u]) {
						if (b[v][i - 1] == -1) {
							t = -1;
							break;
						}
						t += b[v][i - 1];
					}
					b[u][i] = t;
					if (t == -1) break;
				}
				ll s{};
				for (auto& v : ch[u]) s += a[v];
				if (a[u] > s) {
					b[u][0] = 0;
					ll r{a[u] - s};
					for (int i{1}; i <= n && r; ++i) {
						if (b[u][i] == -1) {
							ans += r * i, r = 0;
						} else {
							ll t{min(r, b[u][i])};
							ans += t * i, r -= t;
							b[u][i] -= t;
						}
					}
				} else b[u][0] = s - a[u];
			}
		}

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int b{1};
	cin >> b;
	while (b--) solve();
}
