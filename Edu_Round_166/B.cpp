//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

static void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<ll> a(n), b(n + 1);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	ll ans1{}, ans2{numeric_limits<ll>::max()};
	for (int i{0}; i < n; ++i) {
		ll x{a[i]}, y{b[i]};
		if (x > y) swap(x, y);
		ans1 += y - x;
		if (b[n] < x) ans2 = min(ans2, x - b[n]);
		else if (b[n] > y) ans2 = min(ans2, b[n] - y);
		else ans2 = 0;
	}

	cout << (ans1 + ans2 + 1) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
