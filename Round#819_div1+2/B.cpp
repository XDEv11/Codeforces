//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	if (m < n) cout << "No\n";
	else if (n & 1) {
		cout << "Yes\n";
		for (int i{0}; i < n - 1; ++i) cout << "1 ";
		int k{m - (n - 1)};
		cout << k << '\n';
	} else if (!(m & 1)) {
		cout << "Yes\n";
		for (int i{0}; i < n - 2; ++i) cout << "1 ";
		int k{m - (n - 2)};
		cout << k / 2 << ' ' << k / 2 << '\n';
	} else cout << "No\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
