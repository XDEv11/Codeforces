//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int r, l, d, n;
		cin >> r >> l >> d >> n;
		vector<char> v(n);
		for (auto& x : v) cin >> x;

		int ans{};
		for (auto& x : v) {
			if (x == '1' || r < l) r -= d, ++ans;
		}

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
