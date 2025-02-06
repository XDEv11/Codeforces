//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	int sx, sy, d;
	cin >> sx >> sy >> d, --sx, --sy;

	if (sx - d <= 0 && sx + d >= n - 1) return cout << "-1\n", []{}();
	if (sy - d <= 0 && sy + d >= m - 1) return cout << "-1\n", []{}();
	if (sx - d <= 0 && sy - d <= 0) return cout << "-1\n", []{}();
	if (sx + d >= n - 1 && sy + d >= m - 1) return cout << "-1\n", []{}();
	cout << n - 1 + m - 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
