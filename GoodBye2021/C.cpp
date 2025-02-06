//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int ans{n - 1};
	for (int i{0}; i < n; ++i) {
		map<pair<int, int>, int> mp{};
		for (int j{0}; j < n; ++j) {
			if (j == i) continue;

			int d{v[i] - v[j]}, l{i - j}, g{gcd(d, l)};
			if (j > i) d *= -1, l *= -1;
			mp[{d / g, l / g}] += 1;
		}
		for (auto& [_, c] : mp) ans = min(ans, n - 1 - c);
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
