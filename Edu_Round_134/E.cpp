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

	reverse(s.begin(), s.end());
	vector<int> lps(s.size());
	for (int i = 1, len = 0; i < s.size(); i++) {
		if (s[len] == s[i])
			lps[i] = ++len;
		else if (len) {
			--i;  // process same `i` again
			len = lps[len - 1];
		}
	}for (int i = 1, len = 0; i < s.size(); i++) {
		if (s[len] == s[i])
			lps[i] = ++len;
		else if (len) {
			--i;  // process same `i` again
			len = lps[len - 1];
		}
	}
	reverse(s.begin(), s.end());
	reverse(lps.begin(), lps.end());

	int q;
	cin >> q;
	while (q--) {
		string t{};
		cin >> t;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
