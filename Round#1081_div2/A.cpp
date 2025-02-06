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

		int ans{}, f{};
		for (int i{0}; i < n; ++i) {
			if (i && v[i] == v[i - 1]) {
				f = 1;
				continue;
			}
			++ans;
		}
		if (v[0] != v[n - 1]) ans += f;

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
