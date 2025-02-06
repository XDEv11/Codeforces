//#pragma GCC optimize ("O3")

#include <iostream>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int l, r;
		cin >> l >> r;

		int ans{};
		if (l == 1) ++ans, l = 2;
		ans += max(0, r - l);

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
