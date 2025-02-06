//#pragma GCC optimize ("O3")

#include <iostream>
#include <utility>
#define fi first
#define se second
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;

		if (n == 4) {
			cout << "3\n";
			cout << "1 3\n";
			cout << "2 2\n";
			cout << "3 1\n";
			return ;
		}
		assert(n == 250000);
		const int m{63};

		vector<pair<int, int>> ans{};
		int ck{};
		for (int d{1}; d <= n; d *= m)
			for (int k{m - 1}; k >= 1; --k) {
				ck += 1000;
				for (int i{n - d * k}; i >= 1; i -= d * m) {
					ans.emplace_back(i, d);
					ck += d;
				}
			}

		cout << ans.size() << '\n';
		for (auto& [x, y] : ans) cout << x << ' ' << y << '\n';

		cerr << ck << endl; //
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
