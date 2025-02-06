//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;

	if (n % 3) { // 1 2 4
		if (n < 7) return cout << "NO\n", []{}();
		cout << "YES\n" << "1 2 " << (n - 3) << '\n';
	} else { // 1 4 5
		if (n < 10) return cout << "NO\n", []{}();
		cout << "YES\n" << "1 4 " << (n - 5) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
