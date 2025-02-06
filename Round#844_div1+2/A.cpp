//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
	int w, d, h, a, b, f, g;
	cin >> w >> d >> h >> a >> b >> f >> g;

	int ans{a + f + abs(b - g)};
	ans = min(ans, w - a + w - f + abs(b - g));
	ans = min(ans, b + g + abs(a - f));
	ans = min(ans, d - b + d - g + abs(a - f));

	cout << ans + h << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
