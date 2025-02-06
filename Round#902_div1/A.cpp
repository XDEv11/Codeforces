//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	int n; ll p;
	cin >> n >> p;
	vector<pair<ll, int>> v(n);
	for (auto& [x, y] : v) cin >> y;
	for (auto& [x, y] : v) cin >> x;

	sort(v.begin(), v.end());

	int c{n - 1};
	ll ans{p};
	for (auto& [x, y] : v) {
		if (x >= p) break;
		int t{min(c, y)};
		c -= t, ans += x * t;
	}
	ans += p * c;

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
