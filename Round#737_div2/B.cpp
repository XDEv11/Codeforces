#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>
#include <string>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> v(n);
	for (int i{0}; i < n; ++i) cin >> v[i].fi, v[i].se = i;

	sort(v.begin(), v.end());

	int cnt{0};
	for (int i{0}; i < n; ++i) {
		while (i + 1 < n && v[i + 1].se == v[i].se + 1) ++i;
		++cnt;
	}

	cout << (cnt <= k ? "Yes\n"s : "No\n"s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
