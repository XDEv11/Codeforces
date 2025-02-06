//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, k, x;
	cin >> n >> k >> x;
	if (k == 1) return cout << "NO\n", []{}();

	if (x != 1) {
		cout << "YES\n";
		cout << n << '\n';
		for (int i{0}; i < n; ++i) cout << 1 << " \n"[i == n - 1];
	} else {
		if (k == 2 && (n & 1)) return cout << "NO\n", []{}();
		cout << "YES\n";
		cout << n / 2 << '\n';
		for (int i{0}; i < n / 2; ++i) {
			cout << (!i && (n & 1) ? 3 : 2);
			cout << " \n"[i == n / 2 - 1];
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
