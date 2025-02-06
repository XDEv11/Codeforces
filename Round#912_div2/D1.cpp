//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solve() {
	using ll = long long;

	int n, q;
	if (!(cin >> n >> q)) return false;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	while (q--) {
		ll k;
		cin >> k;

		ll ans{};
		vector<bool> usd(n);
		for (int b{59}; b >= 0; --b) {
			auto cp{usd};
			ll j{};
			for (int i{0}; i < n && j <= k; ++i) {
				if (!usd[i]) {
					if (!((v[i] >> b) & 1)) j += (1ll << b) - v[i] % (1ll << b);
				} else j += (1ll << b);
			}
			if (j <= k) {
				k -= j, ans |= (1ll << b);
				for (int i{0}; i < n; ++i) {
					if (!((v[i] >> b) & 1)) usd[i] = true;
				}
			}
		}

		cout << ans << '\n';
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
