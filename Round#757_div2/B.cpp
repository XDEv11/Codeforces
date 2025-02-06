#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#define fi first
#define se second

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<pair<long long, int>> v(n);
	for (int i{0}; i < n; ++i) {
		cin >> v[i].fi, v[i].se = i + 1;
	}
	sort(v.rbegin(), v.rend());

	long long cnt{0};
	vector<int> ans(n + 1);
	ans[0] = 0;
	for (int i{0}; i < n; ++i) {
		ans[v[i].se] = (i / 2 + 1) * (i & 1 ? 1 : -1);
		cnt += v[i].fi * 2 * (i / 2 + 1);
	}

	cout << cnt << '\n';
	for (auto& x : ans) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
