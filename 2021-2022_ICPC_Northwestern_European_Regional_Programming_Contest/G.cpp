//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

bool solve() {
	int n, w;
	if (!(cin >> n >> w)) return false;
	vector<string> v(n);
	for (auto& x : v) cin >> x;

	vector<int> rec{};
	int l{0}, r{n + 1};
	while (r - l > 1) {
		int m{(l + r) / 2};
		vector<int> dp(n + 1, w + 1);
		dp[0] = -1;
		for (int i{0}; i < n; ++i) {
			for (int j{i}, mx{}; j >= 0 && i - j + 1 <= m; --j) {
				mx = max(mx, int(v[j].size()));
				dp[i + 1] = min(dp[i + 1], dp[j] + 1 + mx);
			}
		}
		if (dp[n] <= w) r = m, rec = dp;
		else l = m;
	}

	vector<vector<string>> ans{};
	for (int i{n - 1}; i >= 0; ) {
		ans.emplace_back();
		int j{i};
		for (int mx{}; ; --j) {
			mx = max(mx, int(v[j].size()));
			if (rec[j] + 1 + mx == rec[i + 1]) break;
		}
		for (int k{j}; k <= i; ++k) ans.back().push_back(v[k]);
		i = j - 1;
	}
	reverse(ans.begin(), ans.end());

	cout << r << ' ' << ans.size() << '\n';
	vector<int> t(ans.size());
	for (int i{0}; i < ans.size(); ++i)
		for (int j{0}; j < ans[i].size(); ++j) t[i] = max(t[i], int(ans[i][j].size()));
	for (auto& x : t) cout << x << ' ';
	cout << '\n';
	for (int j{0}; j < r; ++j) {
		for (int i{0}; i < ans.size(); ++i) cout << left << setw(t[i] + 1) << (j < ans[i].size() ? ans[i][j] : ""s);
		cout << '\n';
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
