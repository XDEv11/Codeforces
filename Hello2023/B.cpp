//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;

	if (n % 2 == 0) {
		cout << "YES\n";
		for (int i{0}; i < n; ++i) cout << (i & 1 ? -1 : 1) << " \n"[i == n - 1];
	} else if (n == 3) cout << "NO\n";
	else {
		cout << "YES\n";
		for (int i{0}; i < n; ++i) cout << (i & 1 ? n / 2 : 1 - n / 2) << " \n"[i == n - 1];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
