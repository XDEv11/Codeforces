#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;
	string s{};
	cin >> s;

	vector<char> ans(n - 1, '?');
	if (s.size() == 1) {
		for (auto& c : ans) c = s[0];
	} else if (!count(s.begin(), s.end(), '*')) { // +-
		for (auto& c : ans) c = '+';
	} else if (!count(s.begin(), s.end(), '+')) { // -*
		for (int i{1}; i < n; ++i) ans[i - 1] = (v[i] == 0 ? '-' : '*');
	} else { // +*
		for (int i{0}, j; i < n; i = j + 1) {
			j = i;
			while (j < n && v[j]) ++j;
			if (j < n) {
				if (j + 1 < n) ans[j] = '+';
				if (j) ans[j - 1] = '+';
				else continue;
			}

			while (i < n && v[i] == 1) ans[i++] = '+';
			if (i == j) continue;
			int k{j - 1};
			while (v[k] == 1) ans[--k] = '+';

			vector<int> g1{};
			for (int p{i}; p <= k; ++p) {
				if (v[p] > 1) g1.push_back(p);
			}

			bool f{false};
			ll x{1};
			for (auto& p : g1) {
				x *= v[p];
				if (x >= 4 * (k - i + 1)) {
					f = true;
					break;
				}
			}
			if (f) {
				for (int p{i}; p < k; ++p) ans[p] = '*';
			} else {
				g1.insert(g1.begin(), i - 1);
				vector<ll> pm(g1.size());
				pm[0] = 1;
				for (int it{1}; it < g1.size(); ++it) pm[it] = pm[it - 1] * v[g1[it]];

				vector<ll> dp(g1.size());
				dp[0] = 0;
				for (int jt{1}; jt < g1.size(); ++jt)
					for (int it{1}; it <= jt; ++it) {
						dp[jt] = max(dp[jt], dp[it - 1] + g1[it] - (g1[it - 1] + 1) + pm[jt] / pm[it - 1]);
					}
				for (int jt{g1.size() - 1}, it; jt >= 1; jt = it - 1) {
					it = 1;
					while (dp[it - 1] + g1[it] - (g1[it - 1] + 1) + pm[jt] / pm[it - 1] != dp[jt]) ++it;
					for (int p{g1[it]}; p < g1[jt]; ++p) ans[p] = '*';
					if (it > 1) {
						for (int p{g1[it - 1]}; p < g1[it]; ++p) ans[p] = '+';
					}
				}
			}
		}
	}

	for (int i{0}; i < n; ++i) cout << v[i] << (i == n - 1 ? '\n' : ans[i]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
