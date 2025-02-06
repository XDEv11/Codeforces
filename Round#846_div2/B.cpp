//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	ll ans{1};
	ll s{accumulate(v.begin(), v.end(), 0ll)}, s1{0};
	for (int i{0}; i < n - 1; ++i) {
		s1 += v[i];
		ans = max(ans, gcd(s1, s - s1));
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
