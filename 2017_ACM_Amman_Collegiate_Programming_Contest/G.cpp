#include <iostream>
#include <vector>
#include <array>
#include <numeric>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	ll ans{};
	for (int l{0}; l < n; ++l) {
		__int128 x{1}; ll y{0};
		for (int r{l}; r < n; ++r) {
			x = x * v[r] / gcd(ll(x), v[r]), y += v[r];
			if (x > 2e12) break;
			ans += (y % x == 0);
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
