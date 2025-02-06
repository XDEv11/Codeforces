//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

static void solve() { // a + b == k * b * b | k >= 1
	using ll = long long;

	ll n, m;
	cin >> n >> m;

	ll ans{n};
	for (ll b{2}; b <= m; ++b) {
		ans += (n + b) / (b * b);
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
