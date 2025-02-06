//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;
	ll maxval{ll(1e18) + 1};

	int n, q;
	cin >> n >> q;
	vector<pair<int, int>> v(n);
	for (auto& [x, y] : v) cin >> x >> y;

	ll s{};
	vector<pair<ll, vector<int>>> r{};
	r.push_back({0, {}});
	for (auto& [x, y] : v) {
		if (x == 1) s += 1, r.back().se.push_back(y);
		else if (x == 2) {
			__int128 t{__int128(s) * (y + 1)};
			if (t > maxval) break;
			r.push_back({s = t, {}});
		}
	}
	reverse(r.begin(), r.end());

	while (q--) {
		ll k;
		cin >> k, --k;

		int ans;
		for (auto& [x, y] : r) {
			k %= x + y.size();
			if (k >= x) {
				ans = y[k - x];
				break;
			}
		}
		cout << ans << ' ';
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
