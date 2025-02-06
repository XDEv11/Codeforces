//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		string s{};
		cin >> s;
		int n{s.size()};

		int k{0};
		while (k < n / 2 && s[k] == s[n - 1 - k]) ++k;
		if (k == n / 2) return cout << "0\n", []{}();

		int ans{n - k * 2};
		array<int, 26> cnt{};
		for (int i{k}; i <= n - 1 - k; ++i) ++cnt[s[i] - 'a'];

		array<int, 26> tmp{};
		int i;
		for (i = k; i < n / 2; ++i) {
			if (++tmp[s[i] - 'a'] > cnt[s[i] - 'a'] / 2) break;
			ans = min(ans, n - 1 - k - i);
		}
		if (i == n / 2) {
			for (; i <= n - 1 - k; ++i) {
				if (s[i] != s[n / 2 - 1 - (i - n / 2)]) break;
				ans = min(ans, n - 1 - k - i);
			}
		} else {
			tmp.fill(0);
			for (i = n - 1 - k; i >= n / 2; --i) {
				if (++tmp[s[i] - 'a'] > cnt[s[i] - 'a'] / 2) break;
				ans = min(ans, i - k);
			}
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
