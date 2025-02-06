//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;

	cout << (k < n - (n + m - 1) / m ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
