//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <string>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;

	if (k == 0) {
		for (int i{0}; i < n - 1 - i; ++i) cout << i << ' ' << n - 1 - i << '\n';
	} else if (k == n - 1) {
		if (n >= 8) {
			for (int i{3}; i < n - 1 - i; ++i) cout << i << ' ' << n - 1 - i << '\n';
			cout << "0 2\n"s;
			cout << "1 "s << n - 3 << '\n';
			cout << n - 2 << ' ' << n - 1 << '\n';
		} else cout << "-1\n"s;
	} else {
		for (int i{1}; i < n - 1 - i; ++i) {
			if (i == k || i == n - 1 - k) continue;
			cout << i << ' ' << n - 1 - i << '\n';
		}
		cout << "0 "s << n - 1 - k << '\n';
		cout << k << ' ' << n - 1 << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
