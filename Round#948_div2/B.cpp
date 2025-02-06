//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

static void solve() {
	int n;
	cin >> n;

	cout << "32\n";
	for (int i{0}; i < 32; ++i, n >>= 1) {
		if (n & 1) {
			if (n & 2) ++n, cout << "-1 ";
			else cout << "1 ";
		} else cout << "0 ";
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
