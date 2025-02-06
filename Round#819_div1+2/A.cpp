//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	if (n == 1) return cout << "0\n", []{}();

	int ans{0};
	for (int i{0}; i < n; ++i) ans = max(ans, v[i] - v[(i + 1) % n]);

	int mx{0};
	for (int i{1}; i < n; ++i) mx = max(mx, v[i]);
	ans = max(ans, mx - v[0]);

	int mn{999};
	for (int i{0}; i < n - 1; ++i) mn = min(mn, v[i]);
	ans = max(ans, v[n - 1] - mn);

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
