//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <string>

using namespace std;

void solve() {
	string s{};
	cin >> s;

	int cl{0}, cr{0};
	for (auto& x : s) {
		if (x == '(') ++cl;
		else if (x == ')') ++cr;
	}

	int ql{s.size() / 2 - cl}, qr{s.size() / 2 - cr};
	if (!ql || !qr) return cout << "YES\n", []{}();
	int j, k{-1};
	for (int i{0}; i < s.size(); ++i)
		if (s[i] == '?') {
			if (ql) {
				s[i] = '(', --ql;
				j = i;
			} else {
				s[i] = ')', --qr;
				if (k == -1) k = i;
			}
		}

	cl = cr = 0;
	swap(s[j], s[k]);
	for (auto& x : s) {
		if (x == '(') ++cl;
		else if (x == ')') ++cr;
		if (cl < cr) return cout << "YES\n", []{}();
	}
	cout << "NO\n", []{}();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
