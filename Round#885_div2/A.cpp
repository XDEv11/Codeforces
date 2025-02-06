//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void solve() {
	int n, m, k, x0, y0;
	cin >> n >> m >> k >> x0 >> y0;
	vector<pair<int, int>> v(k);
	for (auto& [x, y] : v) cin >> x >> y;

	for (auto& [x, y] : v) {
		if (((x + y) & 1) == ((x0 + y0) & 1)) return cout << "NO\n", []{}();
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
