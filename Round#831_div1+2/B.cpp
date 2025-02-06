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
	using ll = long long;

	int n;
	cin >> n;
	vector<pair<ll, ll>> v(n);
	for (auto& [x, y] : v) cin >> x >> y;

	for (auto& [x, y] : v) {
		if (x < y) swap(x, y);
	}
	sort(v.rbegin(), v.rend());

	ll ans{2 * v[0].fi};
	for (auto& [x, y] : v) ans += 2 * y;
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
