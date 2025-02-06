//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;

	if (k == 1) {
		cout << "YES\n";
		for (int i{0}; i < n; ++i) cout << i + 1 << '\n';
		return ;
	} else if (n & 1) return cout << "NO\n", []{}();

	cout << "YES\n";
	for (int i{0}; i < n; i += 2) {
		for (int j{0}; j < k; ++j) cout << i * k + j * 2 + 1 << ' ';
		cout << '\n';
		for (int j{0}; j < k; ++j) cout << i * k + j * 2 + 2 << ' ';
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
