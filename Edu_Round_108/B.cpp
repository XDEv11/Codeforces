#include <iostream>

using namespace std;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;

	cout << (n - 1 + (m - 1) * n == k ? "YES\n"s : "NO\n"s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
