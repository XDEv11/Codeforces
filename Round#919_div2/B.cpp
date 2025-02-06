//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> v(n + 1);
	for (int i{1}; i <= n; ++i) cin >> v[i];

	sort(v.rbegin(), prev(v.rend()));
	for (int i{1}; i <= n; ++i) v[i] += v[i - 1];

	int ans{numeric_limits<int>::min()};
	for (int i{0}; i <= a; ++i) {
		int j{min(n, i + b)};
		ans = max(ans, -(v[j] - v[i]) + (v[n] - v[j]));
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
