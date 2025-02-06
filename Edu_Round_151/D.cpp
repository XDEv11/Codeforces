//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	vector<ll> ps(n + 1);
	for (int i{1}; i <= n; ++i) ps[i] = ps[i - 1] + v[i - 1];

	ll ans1{-1}, ans2;
	ll c1{}, c2{};
	for (int i{n - 1}; i >= 0; --i) {
		c1 += v[i];
		if (c1 > 0) c2 += c1, c1 = 0;
		if (ps[i] + c2 > ans1) ans1 = ps[i] + c2, ans2 = ps[i];
	}

	cout << ans2 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
