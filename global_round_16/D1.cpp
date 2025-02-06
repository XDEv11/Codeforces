#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> v(m);
	for (int i{0}; i < m; ++i) cin >> v[i].fi, v[i].se = -i;

	sort(v.begin(), v.end());

	for (int i{0}; i < m; ++i) v[i].fi = -v[i].se, v[i].se = i;
	sort(v.begin(), v.end());

	int ans{0};
	vector<bool> s(m, false);
	for (auto& [_, p] : v) {
		for (int i{0}; i < p; ++i) ans += s[i];
		s[p] = true;
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
