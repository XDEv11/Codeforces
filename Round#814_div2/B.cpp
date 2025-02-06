//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	
	if (k & 1) {
		cout << "YES\n";
		for (int i{1}; i + 1 <= n; i += 2) cout << i << ' ' << i + 1 << '\n';
	} else if (k & 2) {
		cout << "YES\n";
		for (int i{1}; i + 1 <= n; i += 4) {
			cout << i + 1 << ' ' << i << '\n';
			if (i + 3 <= n) cout << i + 2 << ' ' << i + 3 << '\n';
		}
	} else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
