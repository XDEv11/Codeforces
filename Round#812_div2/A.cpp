//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (auto& [x, y] : v) cin >> x >> y;

	int mnx{0}, mxx{0}, mny{0}, mxy{0};
	for (auto& [x, y] : v) {
		mnx = min(mnx, x);
		mxx = max(mxx, x);
		mny = min(mny, y);
		mxy = max(mxy, y);
	}
	cout << 2 * (mxx - mnx) + 2 * (mxy - mny) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
