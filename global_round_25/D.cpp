//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

void solve() {
	using ll = long long;

	ll n, m;
	cin >> n >> m;

	if (n >= m + (m - 1)) {
		cout << "YES\n";
		cout << "2\n";
		cout << (n - (m - 1)) << " 1\n";
	} else if (n == m) {
		cout << "YES\n";
		cout << "1\n";
		cout << "1\n";
	} else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
