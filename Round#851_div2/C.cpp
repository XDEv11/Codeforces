//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;

	if (n % 2 == 0) return cout << "No\n", []{}();

	// avg: 2n + 1, first: 2n + 1 - (n - 1) / 2
	cout << "Yes\n";
	for (int i{1}; i <= n; i += 2) cout << i << ' ' << (2 * n - (n - 1) / 2) - (i - 1) / 2 << '\n';
	for (int i{2}; i <= n; i += 2) cout << i << ' ' << 2 * n - (i - 2) / 2 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
