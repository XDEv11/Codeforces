//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n, p; ll k;
		cin >> n >> p >> k;
		vector<char> v(n);
		for (auto& x : v) cin >> x;

		for (int i{0}; i < n && k; ++i) {
			--k;
			if (!(p += (v[i] == 'R' ? 1 : -1))) break;
		}

		ll ans{};
		if (!p) {
			ans += 1;
			int c{};
			for (int i{0}; i < n; ++i) {
				++c;
				if (!(p += (v[i] == 'R' ? 1 : -1))) break;
			}
			if (!p) ans += k / c;
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
