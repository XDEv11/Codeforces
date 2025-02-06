//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

namespace {
	void solve() {
		int x, y;
		cin >> x >> y;

		if (y > 0) x -= 2 * y;
		else x += 4 * y;

		cout << (x < 0 || x % 3 ? "NO\n" : "YES\n");
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
