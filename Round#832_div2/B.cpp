//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;

	cout << (n + 1) / 2 << '\n';
	for (int i{0}; i < (n + 1) / 2; ++i) cout << 3 * i + 1 << ' ' << 3 * (n - 1 - i) + 2 + 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
