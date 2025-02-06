//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		int ans{}, f{0};
		for (int i{0}; i < n; ++i) {
			if (v[i] > 4) ++ans, f = 0;
			else if (v[i] > 2) {
				if (f) ++ans, f *= -1;
				else ++ans, f = 0;
			} else if (v[i]) {
				if (f == 1) f = 0;
				else ++ans, f = 1;
			} else f = 0;
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
