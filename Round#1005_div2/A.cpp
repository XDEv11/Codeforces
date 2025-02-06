//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<char> v(n);
		for (auto& x : v) cin >> x;

		int ans{};
		for (int i{0}; i < n; ++i) {
			if (i + 1 < n) {
				if (v[i] == '1' && v[i + 1] == '0') ans += 2;
			} else ans += (v[i] == '1');
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
