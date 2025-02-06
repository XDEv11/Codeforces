//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;

	int t{4 * n - 4};

	if (k > t) cout << (t / 2 + (k - t)) << '\n';
	else cout << ((k + 1) / 2) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
