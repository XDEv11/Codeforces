//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

const long long mod{1000000007};

const int maxn{40000};

const vector<int> p{[]() {
	vector<int> p{};
	for (int i{1}; i <= 9; ++i) p.push_back(i);
	for (int i{1}; i <= 9; ++i) p.push_back(i * 10 + i);
	for (int i{1}; i <= 9; ++i)
		for (int j{0}; j <= 9; ++j) p.push_back(i * 100 + j * 10 + i);
	for (int i{1}; i <= 9; ++i)
		for (int j{0}; j <= 9; ++j) p.push_back(i * 1000 + j * 100 + j * 10 + i);
	for (int i{1}; i <= 9; ++i)
		for (int j{0}; j <= 9; ++j)
			for (int k{0}; k <= 9; ++k) {
				int x{i * 10000 + j * 1000 + k * 100 + j * 10 + i};
				if (x <= maxn) p.push_back(x);
			}
	sort(p.begin(), p.end());
	return p;
}()};

const vector<vector<long long>> dp{[]() {
	vector<vector<long long>> dp(maxn + 1, vector<long long>(p.size()));
	for (auto& x : dp[0]) x = 1;
	for (int i{1}; i <= maxn; ++i) {
		for (int j{0}; j < p.size(); ++j) {
			if (p[j] > i) break;
			dp[i][j] = dp[i - p[j]][j];
		}
		for (int j{1}; j < p.size(); ++j) {
			dp[i][j] += dp[i][j - 1];
			dp[i][j] %= mod;
		}
	}
	return dp;
}()};

void solve() {
	int n;
	cin >> n;

	assert(n <= maxn);

	cout << dp[n].back() << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t{1};
	cin >> t;
	while (t--) solve();
}
