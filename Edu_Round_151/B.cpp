//#pragma GCC optimize ("O3")

#include <iostream>
#include <array>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
	array<array<int, 2>, 3> p;
	for (auto& [x, y] : p) cin >> x >> y;

	int ans{1};
	if ((p[0][0] <= p[1][0]) == (p[0][0] <= p[2][0])) ans += min(abs(p[1][0] - p[0][0]), abs(p[2][0] - p[0][0]));
	if ((p[0][1] <= p[1][1]) == (p[0][1] <= p[2][1])) ans += min(abs(p[1][1] - p[0][1]), abs(p[2][1] - p[0][1]));

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
