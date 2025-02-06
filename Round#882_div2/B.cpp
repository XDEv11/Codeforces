//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int ans{}, c{(1 << 30) - 1};
	for (int i{0}; i < n; ++i) {
		c &= v[i];
		if (!c) ++ans, c = (1 << 30) - 1;
	}
	if (!ans) ans = 1;

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
