//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <map>
#include <algorithm>

using namespace std;

bool solve() {
	const array<char, 5> tg{'A', 'E', 'I', 'O', 'U'};
	map<char, int> id{};
	for (int k{0}; k < 5; ++k) id[tg[k]] = k;

	string s{};
	if (!(cin >> s)) return false;
	int n{s.size()};
	vector<int> v(n);
	for (auto& x : v) cin >> x;
	int m;
	cin >> m;
	while (m--) {
		int i;
		cin >> i, --i;
		s[i] = 'X', v[i] = 0;
	}
	string t{};
	cin >> t;

	array<int, 5> cnt{};
	for (auto& x : s) {
		if (x == 'X') continue;
		++cnt[id[x]];
	}
	for (auto& x : t) {
		if (x == 'X') continue;
		++cnt[id[x]];
	}

	vector<array<int, 32>> dp(n + 1);
	for (int i{0}; i <= n; ++i) dp[i].fill(15001);
	int x{};
	for (int k{0}; k < 5; ++k) {
		if (cnt[k]) continue;
		x |= (1 << k);
	}
	dp[0][x] = 0;
	for (int i{0}; i < n; ++i)
		for (int j{x}; j < 32; ++j) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + v[i]);
			for (int k{0}; k < 5; ++k) {
				if (j & (1 << k)) continue;
				if (!cnt[k] || i + cnt[k] > n) continue;
				int tot{};
				for (int ii{0}; ii < cnt[k]; ++ii) {
					if (s[i + ii] == 'X' || id[s[i + ii]] == k) continue;
					tot += v[i + ii];
				}
				dp[i + cnt[k]][j | (1 << k)] = min(dp[i + cnt[k]][j | (1 << k)], dp[i][j] + tot);
			}
		}

	return cout << dp[n][31] << '\n', true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (solve()) ;
}
