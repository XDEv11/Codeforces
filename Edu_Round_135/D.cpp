//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	string s{};
	cin >> s;

	vector<int> dp(s.size());
	for (int i{0}; i + 1 < s.size(); ++i) {
		if (s[i] == s[i + 1]) dp[i] = 0;
		else dp[i] = 1;
	}
	for (int l{4}; l <= s.size(); l += 2) {
		for (int i{0}; i + l - 1 < s.size(); ++i) {
			int a{dp[i]};
			if (a == 0) {
				if (s[i + l - 1] < s[i + l - 2]) a = 1;
				else if (s[i + l - 1] == s[i + l - 2]) a = 0;
				else a = -1;
			}
			int b{dp[i + 1]};
			if (b == 0) {
				if (s[i + l - 1] < s[i]) b = 1;
				else if (s[i + l - 1] == s[i]) b = 0;
				else b = -1;
			}
			int c{dp[i + 1]};
			if (c == 0) {
				if (s[i] < s[i + l - 1]) c = 1;
				else if (s[i] == s[i + l - 1]) c = 0;
				else c = -1;
			}
			int d{dp[i + 2]};
			if (d == 0) {
				if (s[i] < s[i + 1]) d = 1;
				else if (s[i] == s[i + 1]) d = 0;
				else d = -1;
			}
			dp[i] = max(min(a, b), min(c, d));
		}
	}
	
	if (dp[0] == 1) cout << "Alice\n";
	else if (dp[0] == 0) cout << "Draw\n";
	else cout << "Bob\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
