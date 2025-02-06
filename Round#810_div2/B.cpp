//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define fi first
#define se second
#include <limits>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> uh(n);
	for (auto& x : uh) cin >> x;
	vector<pair<int, int>> f(m);
	for (auto& [x, y] : f) cin >> x >> y, --x, --y;

	if (m % 2 == 0) return cout << "0\n", []{}();

	vector<int> cnt(n);
	for (auto& [x, y] : f) ++cnt[x], ++cnt[y];
	int ans{numeric_limits<int>::max()};
	for (int i{0}; i < n; ++i) {
		if (cnt[i] & 1) ans = min(ans, uh[i]);
	}
	for (auto& [x, y] : f) {
		if ((cnt[x] + cnt[y]) % 2 == 0) ans = min(ans, uh[x] + uh[y]);
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
