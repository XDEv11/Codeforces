//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		if (!(n & (n - 1))) return cout << "-1\n", []{}();

		vector<int> ans(n + 1);
		ans[n] = 1;
		ans[1] = n - (n & 1);
		for (int i{2}; i <= n - 1; ++i) ans[i] = i ^ 1;
		if (!(n & 1)) swap(ans[1], ans[n & -n]);

		for (int i{1}; i <= n; ++i) cout << ans[i] << " \n"[i == n];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
