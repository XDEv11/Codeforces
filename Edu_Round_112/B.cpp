#include <iostream>
#include <limits>

using namespace std;

void solve() {
	int W, H, x1, y1, x2, y2, w, h;
	cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;

	if (w + (x2 - x1) > W && h + (y2 - y1) > H) return cout << "-1\n"s, []{}();

	int ans{numeric_limits<int>::max()};
	if (w + (x2 - x1) <= W) {
		if (w <= x1) ans = 0;
		else ans = w - x1;

		if (w <= W - x2) ans = 0;
		else ans = min(ans, w - (W - x2));
	}

	if (h + (y2 - y1) <= H) {
		if (h <= y1) ans = 0;
		else ans = min(ans, h - y1);

		if (h <= H - y2) ans = 0;
		else ans = min(ans, h - (H - y2));
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
