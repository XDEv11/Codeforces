//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

namespace {
	void solve() {
		int n, a, b;
		cin >> n >> a >> b;

		if ((n & 1) != (b & 1)) return cout << "NO\n", []{}();
		if (a > b && (n & 1) != (a & 1)) return cout << "NO\n", []{}();
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
