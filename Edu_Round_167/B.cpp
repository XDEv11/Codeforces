//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		string a{}, b{};
		cin >> a >> b;
		int n{a.size()}, m{b.size()};

		int ans{n + m};
		for (int j{0}; j < m; ++j) {
			int c{0};
			for (int i{0}; i < n && j + c < m; ++i) {
				if (a[i] == b[j + c]) ++c;
			}
			ans = min(ans, n + m - c);
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
