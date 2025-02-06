//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	int mx{1000000000}, mn{1};
	vector<int> v{};
	for (int i{0}; i < n; ++i) {
		int t, x;
		cin >> t >> x;
		if (t == 1) mn = max(mn, x);
		else if (t == 2) mx = min(mx, x);
		else if (t == 3) v.push_back(x);
	}

	int ans{max(0, mx - mn + 1)};
	for (auto& x : v) ans -= (mn <= x && x <= mx);

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
