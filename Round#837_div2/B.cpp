//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define fi first
#define se second

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> v(m);
	for (auto& [x, y] : v) cin >> x >> y, --x, --y;

	vector<int> r(n, n);
	for (auto& [x, y] : v) {
		if (x > y) swap(x, y);
		r[x] = min(r[x], y);
	}

	for (int i{n - 2}; i >= 0; --i) r[i] = min(r[i], r[i + 1]);

	long long ans{0};
	for (int i{0}; i < n; ++i) ans += r[i] - i;

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
