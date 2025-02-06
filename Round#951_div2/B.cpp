//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int x, y;
		cin >> x >> y;

		for (int b{0}; b < 30; ++b) {
			if ((x ^ y) & (1 << b)) return cout << (1 << b) << '\n', []{}();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
