//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		if (!n) return cout << "YES\n", []{}();

		int i{0}, j{29};
		while (!((n >> i) & 1)) ++i;
		while (!((n >> j) & 1)) --j;

		for (int k{i}; ; ++k) {
			int f{j - (k - i)};
			if (k < f) {
				if (((n >> k) & 1) != ((n >> f) & 1)) return cout << "NO\n", []{}();
			} else if (k == f) {
				if ((n >> k) & 1) return cout << "NO\n", []{}();
			} else break;
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
