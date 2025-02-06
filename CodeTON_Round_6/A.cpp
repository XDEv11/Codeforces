//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

void solve() {
	int n, k, x;
	cin >> n >> k >> x;

	if (n < k || x + 1 < k) return cout << "-1\n", []{}();

	cout << ((k - 1) * k / 2 + (n - k) * (x == k ? x - 1 : x)) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
