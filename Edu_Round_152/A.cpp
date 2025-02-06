//#pragma GCC optimize ("O3")

#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
	int b, c, h;
	cin >> b >> c >> h;

	cout << min(b * 2 - 1, (c + h) * 2 + 1) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
