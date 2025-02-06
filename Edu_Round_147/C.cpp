//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
	string s{};
	cin >> s;

	int ans{s.size()};
	for (char c{'a'}; c <= 'z'; ++c) {
		int cnt{0}, mx{0};
		for (int i{0}; i < s.size(); ++i) {
			if (s[i] == c) {
				int ch{0};
				while (cnt) cnt /= 2, ++ch;
				mx = max(mx, ch);
			} else ++cnt;
		}
		int ch{0};
		while (cnt) cnt /= 2, ++ch;
		mx = max(mx, ch);

		ans = min(ans, mx);
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
