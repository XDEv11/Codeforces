//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n - 2);
		for (auto& x : v) cin >> x;

		int c{2};
		for (int i{0}; i < n - 2; ++i) {
			if (v[i]) {
				if (c == 1) return cout << "NO\n", []{}();
				c = 0;
			} else ++c;
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
