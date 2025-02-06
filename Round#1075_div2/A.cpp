//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int c, n, m;
		cin >> c >> n >> m;
		vector<int> v(c);
		for (auto& x : v) cin >> x;

		sort(v.begin(), v.end());
		if (n > m) swap(n, m);

		int i{c - 1};
		while (i >= 0 && v[i] > m) --i;
		int ans{(i + 1) / 2};
		while (i >= 0 && v[i] > n) --i;
		ans = min(ans, i + 1);

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
