//#pragma GCC optimize ("O3")

#include <iostream>
#include <algorithm>

using namespace std;

static void solve() {
	int p1, p2, p3;
	cin >> p1 >> p2 >> p3;
	if ((p1 + p2 + p3) & 1) return cout << "-1\n", []{}();

	cout << min(p1 + p2, (p1 + p2 + p3) / 2) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
