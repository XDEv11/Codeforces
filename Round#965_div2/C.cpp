//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <queue>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		using ll = long long;
		int n; ll m;
		cin >> n >> m;
		vector<pair<ll, bool>> v(n);
		for (auto& [x, y] : v) cin >> x;
		for (auto& [x, y] : v) cin >> y;

		sort(v.begin(), v.end());

		if (n == 1) cout << (v[0].fi + (v[0].se ? m : 0)) << '\n';
		else {
			int j{n / 2 - 1};
			ll ans{v[j].fi + v[n - 1].fi};
			{
				int k{n - 1};
				while (k >= 0 && !v[k].se) --k;
				if (k > j) ans = max(ans, v[j].fi + v[k].fi + m);
				else if (k >= 0) ans = max(ans, v[j + 1].fi + v[k].fi + m);
			}
			priority_queue<ll> pq{};
			for (int i{0}; i < j; ++i) {
				if (!v[i].se) continue;
				pq.push(v[i].fi);
			}
			for (int i{j}; i + 1 < n; ++i) {
				if (v[i].se) pq.push(v[i].fi);
				if (pq.empty()) break;
				auto x{pq.top()}; pq.pop();
				m -= v[i].fi - x;
				if (m < 0) break;
				ll t{min(m / (i + 1 - j), v[i + 1].fi - v[i].fi)};
				m -= t * (i + 1 - j);
				ans = max(ans, v[i].fi + t + v[n - 1].fi);
				if (v[i].fi + t < v[i + 1].fi) break;
			}
			cout << ans << '\n';
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
