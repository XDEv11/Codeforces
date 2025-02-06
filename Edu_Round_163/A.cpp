//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;

	if (n % 2 == 0) {
		cout << "YES\n";
		for (int i{0}; i < n / 2; ++i) cout << (i & 1 ? "AA" : "BB");
		cout << '\n';
	} else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
