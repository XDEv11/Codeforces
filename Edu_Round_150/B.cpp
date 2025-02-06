//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

void solve() {
	int q;
	cin >> q;

	bool flag{false};
	int f, b{-1};
	while (q--) {
		int x;
		cin >> x;

		if (!flag) {
			if (b == -1) f = b = x, cout << '1';
			else if (x >= b) b = x, cout << '1';
			else if (x <= f) flag = true, b = x, cout << '1';
			else cout << '0';
		} else {
			if (x >= b && x <= f) b = x, cout << '1';
			else cout << '0';
		}
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
