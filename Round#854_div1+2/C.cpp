//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	string s{};
	cin >> s;
	int n{s.size()};

	sort(s.begin(), s.end());
 
	vector<char> ans(n);
	for (int i{0}; 2 * i < n; ++i) {
		ans[n - 1 - i] = s[2 * i];
		if (2 * i + 1 < n) ans[i] = s[2 * i + 1];
	}
 
	for (int i{0}; i < n - 1 - i; ++i) {
		if (ans[i] > ans[n - 1 - i]) {
			sort(ans.begin() + i + 1, ans.begin() + n - 1 - i);
			break;
		}
	}

	for (int i{0}; i + 1 < n - 1 - i; ++i) {
		if (ans[i] == ans[i + 1] && ans[i + 1] == ans[n - 1 - i - 1] && ans[i] > ans[n - 1 - i]) swap(ans[n - 1 - i - 1], ans[n - 1 - i]);
	}

	for (auto& x : ans) cout << x;
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
