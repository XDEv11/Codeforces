//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

bool solve() {
	using ll = long long;
	const ll inf{1000000000000ll};

	int n, s1, s2;
	if (!(cin >> n >> s1 >> s2)) return false;
	vector<array<int, 4>> v(n);
	for (auto& [x, t, y, r] : v) cin >> x >> t >> y >> r;
	sort(v.begin(), v.end());

	vector<vector<ll>> dp(s1 + 1, vector<ll>(s2 + 1, inf));
	dp[0][0] = 0;
	for (int i{0}; i < n; ++i)
		for (int j{s1}; j >= 0; --j)
			for (int k{s2}; k >= 0; --k) {
				if (j < s1) {
					int nj{j + v[i][0]}, nk{k};
					if (nj > s1) nk = min(s2, nk + nj - s1), nj = s1;
					dp[nj][nk] = min(dp[nj][nk], dp[j][k] + v[i][1]);
				}
				if (k < s2) {
					int nk{min(s2, k + v[i][2])};
					dp[j][nk] = min(dp[j][nk], dp[j][k] + v[i][3]);
				}
			}

	return cout << (dp[s1][s2] == inf ? -1 : dp[s1][s2]) << '\n', true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
