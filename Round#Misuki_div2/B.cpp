//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;

		if (n % 2 == 0) return cout << "-1\n", []{}();

		int h{(n + 1) / 2};
		for (int i{n}; i > h; --i) cout << i << ' ';
		for (int i{1}; i <= h; ++i) cout << i << " \n"[i == h];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
