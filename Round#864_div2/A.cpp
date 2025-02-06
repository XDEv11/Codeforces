//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2, --x1, --x2, --y1, --y2;

	auto calc = [&n, &m](int x, int y) {
		return (x != 0) + (x != n - 1) + (y != 0) + (y != m - 1);
	};

	cout << min(calc(x1, y1), calc(x2, y2)) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
