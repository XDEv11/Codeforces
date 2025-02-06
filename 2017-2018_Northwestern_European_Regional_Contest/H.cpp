#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;
	auto calc{[](array<ll, 3> a) {
		ll s{};
		for (auto& x : a) s += x * x;
		s += 7 * *min_element(a.begin(), a.end());
		return s;
	}};

	array<ll, 3> a; ll d;
	for (auto& x : a) cin >> x;
	cin >> d;
	
	sort(a.rbegin(), a.rend());
	if (a[0] >= a[2] + 4 || d > 100) return a[0] += d, cout << calc(a) << '\n', []{}();

	ll ans{};
	for (ll i{0}; i <= d; ++i)
		for (ll j{0}; i + j <= d; ++j) {
			ll k{d - i - j};
			auto b{a};
			b[0] += i, b[1] += j, b[2] += k;
			ans = max(ans, calc(b));
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
