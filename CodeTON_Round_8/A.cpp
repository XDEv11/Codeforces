//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;

	if (k == 1) {
		for (int i{0}; i < n; ++i) cout << (i + 1) << ' ';
		cout << '\n';
	} else if (k == n) {
		for (int i{0}; i < n; ++i) cout << 1 << ' ';
		cout << '\n';
	} else cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
