//#pragma GCC optimize ("O3")

#include <ios>
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

	ll ans{0};
	sort(v.begin(), v.end());
	for (int i{1}; i + 1 < n; ++i) ans = max(ans, v[i + 1] - v[i] + v[i + 1] - v[0]);
	for (int i{n - 2}; i - 1 >= 0; --i) ans = max(ans, v[i] - v[i - 1] + v[n - 1] - v[i - 1]);

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
