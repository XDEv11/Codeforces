//#pragma GCC optimize ("O3")

#include <iostream>
#include <numeric>

using namespace std;

static void solve() { // (Let a=xc, b=yc) yc = k * (x + y) | k >= 1
	using ll = long long;

	ll n, m;
	cin >> n >> m;

	ll ans{0};
	for (ll x{1}; x * x <= n; ++x)
		for (ll y{1}; y * (x + y) <= m; ++y) {
			if (gcd(x, y) > 1) continue;
			ll c{x + y};
			ans += min(n / (x * c), m / (y * c));
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
