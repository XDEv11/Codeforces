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
		for (int i{0}; i + 1 < n; ++i) {
			if ((v[i + 1] - v[i]) & 1) return cout << "-1\n", []{}();
		}

		vector<int> ans{};
		int x{v[n - 1]};
		if (x > 1) {
			while (x > 1) {
				ans.push_back(x / 2);
				x = (x + 1) / 2;
			}
			ans.push_back(1);
		} else if (x == 1) ans = {1};

		cout << ans.size() << '\n';
		for (auto& x : ans) cout << x << ' ';
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
