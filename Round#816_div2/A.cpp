//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	int ans{2 * (n - 1 + m - 1)};
	ans -= max(0, max(n - 2, m - 2));
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
