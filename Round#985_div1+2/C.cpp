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

		int ans{0}, x{0}, mx{x};
		for (int i{0}; i < n; ++i) {
			if (i) {
				if (v[i] > ans) ++ans;
				else if (v[i] < ans) --ans;
			}

			if (v[i] > x) ++x;
			else if (v[i] < x) --x;

			ans = max(ans, mx);

			mx = max(mx, x);
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
