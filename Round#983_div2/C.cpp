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

		sort(v.begin(), v.end());

		int ans{n - 2};
		for (int i{0}; i + 2 < n; ++i) {
			int l{i + 1}, r{n};
			while (r - l > 1) {
				int m{(l + r) / 2};
				(v[m] < v[i] + v[i + 1] ? l : r) = m;
			}
			ans = min(ans, i + n - r);
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
