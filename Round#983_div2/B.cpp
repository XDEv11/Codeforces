//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

namespace {
	void solve() {
		int n, k;
		cin >> n >> k;
		if (n == 1) return cout << "1\n1\n", []{}();
		if (k == 1 || k == n) return cout << "-1\n", []{}();

		cout << "3\n1 ";
		if (k & 1) cout << k - 1 << ' ' << k + 2 << '\n';
		else cout << k << ' ' << k + 1 << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
