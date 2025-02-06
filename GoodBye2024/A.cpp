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

		for (int i{0}; i + 1 < n; ++i) {
			int x{v[i]}, y{v[i + 1]};
			if (x > y) swap(x, y);
			if (x + x > y) return cout << "YES\n", []{}();
		}
		cout << "NO\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
