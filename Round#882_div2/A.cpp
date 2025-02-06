//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<int> d(n - 1);
	for (int i{0}; i + 1 < n; ++i) d[i] = abs(v[i + 1] - v[i]);

	int ans{};
	sort(d.begin(), d.end());
	for (int i{0}; i < n - 1 - (k - 1); ++i) ans += d[i];

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
