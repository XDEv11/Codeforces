//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;

	for (int i{0}; i + 1 <= n - i; ++i) {
		cout << (i + 1) << ' ';
		if (i + 1 < n - i) cout << (n - i) << ' ';
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
