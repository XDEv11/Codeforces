//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<char> v(n);
		for (auto& x : v) cin >> x;

		int ans{};
		for (int i{0}; i < n; ) {
			if (v[i] == '0') { ++i; continue; }

			int j{(i + 1) % n}, c{};
			while (v[j] == '0') j = (j + 1) % n, ++c;
			ans = max(ans, c);
			i += c + 1;
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
