//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <utility>
#define fi first
#define se second
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<array<ll, 4>> v(n);
	for (auto& [a, b, c, d] : v) cin >> a >> b >> c >> d;

	ll ans{};
	map<pair<ll, ll>, int> mp{};
	for (auto& [a, b, c, d] : v) {
		ll dx{c - a}, dy{d - b};
		if (dx && dy) {
			ll g{gcd(dx, dy)};
			dx /= g, dy /= g;
		} else if (dx) dx = dx > 0 ? 1 : -1;
		else dy = dy > 0 ? 1 : -1;
		ans += mp[{-dx, -dy}];
		++mp[{dx, dy}];
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
