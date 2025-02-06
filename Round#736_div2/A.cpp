#include <iostream>

using namespace std;

void solve() {
	int p;
	cin >> p;

	if (p & 1) cout << 2 << ' ' << p - 1 << '\n';
	else cout << 2 << ' ' << p << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
