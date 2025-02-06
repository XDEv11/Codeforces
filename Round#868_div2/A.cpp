//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;

	for (int i{0}; i <= n; ++i) {
		int j{n - i};
		if (i * (i - 1) / 2 + j * (j - 1) / 2 == k) {
			cout << "YES\n";
			for (int k{0}; k < i; ++k) cout << "1 ";
			for (int k{0}; k < j; ++k) cout << "-1 ";
			return cout << '\n', []{}();
		}
	}
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
