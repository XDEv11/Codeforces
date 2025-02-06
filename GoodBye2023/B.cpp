//#pragma GCC optimize ("O3")

#include <iostream>
#include <numeric>

using namespace std;

void solve() {
	using ll = long long;

	ll a, b;
	cin >> a >> b;

	ll ans{a * b / gcd(a, b)};
	if (ans == b) {
		bool f{false};
		for (ll t{2}; t * t <= ans; ++t) {
			if (ans % t == 0) {
				f = true;
				ans *= t;
				break;
			}
		}
		if (!f) ans *= ans;
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
