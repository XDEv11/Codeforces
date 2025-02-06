#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fi first
#define se second

void solve() {
	int n;
	cin >> n;
	vector<pair<long long, int>> v(n);
	for (int i{0}; i < n; ++i) {
		cin >> v[i].fi;
		v[i].se = i + 1;
	}
	sort(v.begin(), v.end());

	int ans{0};
	for (int i{0}; i < n; ++i)
		for (int j{i + 1}; j < n && v[i].fi * v[j].fi < 2 * n; ++j)
			if (v[i].fi * v[j].fi == v[i].se + v[j].se) ++ans;

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
