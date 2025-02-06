#include <iostream>

using namespace std;

void solve() {
	int x, y;
	cin >> x >> y;

	if (y < x) cout << x + y << '\n'; // y
	else cout << y - (y % x) / 2 << '\n'; // (y % x) / 2
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
