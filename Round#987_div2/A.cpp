//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		int ans{n - 1}, c{1};
		for (int i{1}; i < n; ++i) {
			c = (v[i] == v[i - 1] ? c + 1 : 1);
			ans = min(ans, n - c);
		}

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
