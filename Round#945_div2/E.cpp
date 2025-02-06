//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static void solve() {
	using ll = long long;
	auto calc{[](ll l) { return (l + 1) * l / 2; }};

	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	ll ans{calc(2 * n)};

	int i{1}, j{n};
	while (i - 1 < n && v[i - 1] == i) ++i;
	if (i == n + 1) return cout << ans << '\n', []{}();
	while (v[j - 1] == j) --j;

	ans -= calc((1 + j) - 1) + calc(2 * n - (i + n));

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
