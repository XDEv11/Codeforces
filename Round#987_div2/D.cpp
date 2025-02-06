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

		vector<int> mx{v};
		for (int i{1}; i < n; ++i) mx[i] = max(mx[i], mx[i - 1]);

		vector<int> ans(n);
		ans[n - 1] = mx[n - 1];
		for (int i{n - 2}, mn{v[n - 1]}; i >= 0; mn = min(mn, v[i--])) {
			ans[i] = (mx[i] > mn ? ans[i + 1] : mx[i]);
		}

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
