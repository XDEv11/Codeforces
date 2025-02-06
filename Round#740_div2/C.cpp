#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i{0}; i < n; ++i) {
		int k;
		cin >> k;
		int mx{0};
		for (int j{0}; j < k; ++j) {
			int x;
			cin >> x;
			mx = max(mx, x - j + 1);
		}
		v[i] = {mx, k};
	}

	sort(v.begin(), v.end());

	int ans{0}, ks{0};
	for (int i{0}; i < n; ++i) {
		auto& [mx, k]{v[i]};
		ans = max(ans, mx - ks);
		ks += k;
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
