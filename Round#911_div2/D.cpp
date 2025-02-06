//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	sort(v.begin(), v.end());

	ll ans{};
	for (int i{0}; i < n; ++i) {
		for (int j{0}; j < i; ++j) ans += gcd(v[i], v[j]) * (n - (i + 1));
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
