//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

static void solve() {
	using ll = long long;
	int n; ll l, r;
	cin >> n >> l >> r;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	int ans{}; ll s{0};
	for (int i{0}, j{0}; i < n; ++i) {
		s += v[i];
		while (s > r) s -= v[j++];
		if (s >= l) ++ans, s = 0, j = i + 1;
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
