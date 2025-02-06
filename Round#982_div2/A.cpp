//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<array<int, 2>> v(n);
		for (auto& [x, y] : v) cin >> x >> y;

		int mxx{}, mxy{};
		for (auto& [x, y] : v) mxx = max(mxx, x), mxy = max(mxy, y);

		cout << (2 * (mxx + mxy)) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
