//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		int mx{numeric_limits<int>::max()};
		for (auto& x : v) {
			if (x > mx) return cout << "NO\n", []{}();
			mx = min(mx, 2 * x - 1);
		}
		cout << "YES\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
