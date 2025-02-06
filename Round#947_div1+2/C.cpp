//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

static void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int ans{};
	for (int i{0}; i + 1 < n; ++i) ans = max(ans, min(v[i], v[i + 1]));
	for (int i{0}; i + 2 < n; ++i) {
		array<int, 3> a{v[i], v[i + 1], v[i + 2]};
		sort(a.begin(), a.end());
		ans = max(ans, a[1]);
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
