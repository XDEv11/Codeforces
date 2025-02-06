//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <limits>
#include <algorithm>

using namespace std;

// longest prefix which is also suffix
template<typename T>
vector<int> prefix_func(const vector<T>& v) {
    vector<int> len(v.size());
    for (int i{1}; i < v.size(); ++i) {
        int j{len[i - 1]};
        while (j > 0 && v[i] != v[j]) j = len[j - 1];
        len[i] = j + (v[i] == v[j]);
    }
    return len;
}

void solve() {
	string _s{}, _p{};
	cin >> _s >> _p;
	int n{_s.size()}, m{_p.size()};

	vector<char> s(n + 1), p(m);
	for (int i{0}; i < n; ++i) s[i + 1] = _s[i];
	for (int i{0}; i < m; ++i) p[i] = _p[i];

	vector<int> lps{prefix_func(p)};

	vector<array<int, 26>> fsm(m + 1);
	fsm[0][p[0] - 'a'] = 1;
	for (int j{1}; j <= m; ++j)
		for (int c{0}; c < 26; ++c) {
			if (j < m && p[j] == 'a' + c) fsm[j][c] = j + 1;
			else fsm[j][c] = fsm[lps[j - 1]][c];
		}

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, numeric_limits<int>::min()));
	dp[0][0] = 0;
    for (int i{1}; i <= n; ++i)
		for (int k{0}; k <= m; ++k) {
			int b{0}, e{25};
			if (s[i] != '?') b = e = s[i] - 'a';
			for (int c{b}; c <= e; ++c) {
				int j{fsm[k][c]};
				dp[i][j] = max(dp[i][j], dp[i - 1][k] + (j == m));
			}
		}

	int ans{};
	for (int k{0}; k <= m; ++k) ans = max(ans, dp[n][k]);
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
