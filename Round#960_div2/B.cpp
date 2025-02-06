//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n, j, k;
		cin >> n >> j >> k, --j, --k;

		vector<int> ans(n);
		for (int i{k}; i <= j; ++i) ans[i] = 1;
		for (int i{k - 1}; i >= 0; i -= 2) {
			ans[i] = -1;
			if (i - 1 >= 0) ans[i - 1] = 1;
		}
		for (int i{j + 1}; i < n; i += 2) {
			ans[i] = -1;
			if (i + 1 < n) ans[i + 1] = 1;
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
