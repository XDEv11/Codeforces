//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int x, y, k;
		cin >> x >> y >> k;

		vector<int> vx{}, vy{};
		if (k & 1) vx.push_back(x);
		for (int i{1}; i <= k / 2; ++i) vx.push_back(x + i), vx.push_back(x - i);
		if (k & 1) vy.push_back(y);
		for (int i{1}; i <= k / 2; ++i) vy.push_back(y + i), vy.push_back(y - i);

		for (int i{0}; i < k; ++i) cout << vx[i] << ' ' << vy[i] << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
