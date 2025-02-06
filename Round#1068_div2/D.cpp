//#pragma GCC optimize ("O3")

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	template<typename T>
	void maximize(T& a, T b) {
		a = max(a, b);
	}
	void solve1() {
		int n, m;
		cin >> n >> m;

		array<int, 31> ps{};
		for (int i{0}; i < 30; ++i) ps[i + 1] = ps[i] + ((n >> i) & 1);

		array<array<int, 32>, 31> dp{};
		for (int i{0}; i < 30; ++i) {
			dp[i + 1] = dp[i];
			for (int j{0}; j <= i; ++j) {
				int l{i + 1 - j}, c{l - (ps[i + 1] - ps[j])};
				for (int k{0}; k <= j; ++k) maximize(dp[i + 1][k + c + 1], dp[j][k] + l);
			}
		}

		int ans{};
		for (int k{0}; k <= min(30, m); ++k) maximize(ans, dp[30][k] + m - k);

		cout << ans << '\n';
	}
	void solve2() {
		int n, m;
		cin >> n >> m;

		array<array<int, 31>, 31> dp0{}, dp1{};
		for (int i{0}; i <= 30; ++i) dp1[i][0] = -30;
		for (int i{0}; i < 30; ++i) {
			for (int j{0}; j <= 30; ++j) maximize(dp0[i + 1][j], dp0[i][j]);
			if (n & (1 << i)) {
				for (int j{0}; j + 1 <= 30; ++j) maximize(dp1[i + 1][j + 1], dp0[i][j] + 1);
				for (int j{0}; j <= 30; ++j) maximize(dp1[i + 1][j], dp1[i][j] + 1);
			} else {
				for (int j{0}; j <= 30; ++j) maximize(dp0[i + 1][j], dp1[i][j]);
				for (int j{0}; j + 1 <= 30; ++j) maximize(dp1[i + 1][j + 1], dp1[i][j] + 1);
			}
		}

		int ans{};
		for (int j{0}; j <= min(30, m); ++j) maximize(ans, max(dp0[30][j], dp1[30][j]) + m - j);

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve2();
}
