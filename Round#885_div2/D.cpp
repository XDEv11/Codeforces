//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	ll s, k;
	cin >> s >> k;

	ll ans{s * k};
	if (s % 10 == 0) ;
	else if (s % 5 == 0) ans = max(ans, (s + 5) * (k - 1));
	else { // 2 4 8 6 (2 4 ...)
		for (int _{0}; _ < 4 && k; ++_) {
			s += s % 10, --k;

			ll l{0}, r{k / 4};
			while (r - l > 2) {
				ll m1{l + (r - l) / 3}, m2{r - (r - l) / 3};
				ll v1{(s + m1 * 20) * (k - (m1 * 4))}, v2{(s + m2 * 20) * (k - (m2 * 4))};
				if (v1 > v2) r = m2;
				else l = m1;
			}
			for (ll i{l}; i <= r; ++i) ans = max(ans, (s + i * 20) * (k - (i * 4)));
		}
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
