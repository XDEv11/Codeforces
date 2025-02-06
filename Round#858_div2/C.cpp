//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<int> v(2 * n);
	for (auto& x : v) cin >> x;
	sort(v.rbegin(), v.rend());

	if (n == 1) return cout << abs(v[0] - v[1]) << '\n', []{}();

	ll ans{accumulate(v.begin(), v.end(), 0ll, [](ll a, int b) { return a + abs(b - 0); })};
	if (n == 2) {
		ans = min(ans, 
			accumulate(v.begin(), v.end(), 0ll, [](ll a, int b) { return a + abs(b - 2); }));
		ans = min(ans, 
			abs(v[0] - 2) + accumulate(v.begin() + 1, v.end(), 0ll, [](ll a, int b) { return a + abs(b - (-1)); }));
	} else if (n % 2 == 0) {
		ans = min(ans, 
			abs(v[0] - n) + accumulate(v.begin() + 1, v.end(), 0ll, [](ll a, int b) { return a + abs(b - (-1)); }));
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
