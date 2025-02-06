//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n, x, y;
		cin >> n >> x >> y, --x, --y;

		vector<int> ans(n);
		if (x & 1) {
			for (int i{0}; i + 1 < n; i += 2) ans[i] = 0, ans[i + 1] = 1;
			if (n & 1) ans[n - 1] = 2;

			if (y & 1) ans[x != n - 2 ? x : y] = 2;
		} else {
			for (int i{1}; i < n; i += 2) ans[i] = 0, ans[(i + 1) % n] = 1;
			if (n & 1) ans[0] = 2;

			if (!(y & 1)) ans[x != n - 1 ? x : y] = 2;
		}

		for (auto& e : ans) cout << e << ' ';
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
