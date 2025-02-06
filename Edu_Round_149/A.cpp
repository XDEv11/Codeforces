//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

void solve() {
	int x, k;
	cin >> x >> k;

	if (x % k) cout << "1\n" << x << '\n';
	else cout << "2\n" << x - 1 << " 1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
