#include <iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;

	long long ans{1}, mod{1000000007};
	for (int i{3}; i <= 2 * n; ++i) ans = ans * i % mod;

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
