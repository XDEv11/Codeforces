//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <string>

using namespace std;

void solve() {
	string s{};
	cin >> s;
	int n{s.size()};

	if (s[0] == s[1]) {
		cout << s[0] << ' ' << s[1] << ' ';
		for (int i{2}; i < n; ++i) cout << s[i];
		cout << '\n';
	} else if (s[n - 2] == s[n - 1]) {
		for (int i{0}; i < n - 2; ++i) cout << s[i];
		cout << ' ' << s[n - 2] << ' ' << s[n - 1] << '\n';
	} else if (s[0] == s[n - 1]) {
		cout << s[0] << ' ';
		for (int i{1}; i < n - 1; ++i) cout << s[i];
		cout << ' ' << s[n - 1] << '\n';
	} else {
		cout << s[0] << ' ';
		for (int i{1}; i < n - 2; ++i) cout << s[i];
		cout << ' ' << s[n - 2] << s[n - 1] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
