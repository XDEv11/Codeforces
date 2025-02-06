//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <string>

#define c2d(c) (c - '0')

using namespace std;

void solve() {
	string s;
	cin >> s;

	for (int i{s.size() - 1}; i - 1 >= 0; --i) {
		if (c2d(s[i]) + c2d(s[i - 1]) >= 10) {
			for (int j{0}; j < i - 1; ++j) cout << s[j];
			cout << c2d(s[i]) + c2d(s[i - 1]);
			for (int j{i + 1}; j < s.size(); ++j) cout << s[j];
			cout << '\n';
			return ;
		}
	}
	cout << c2d(s[0]) + c2d(s[1]);
	for (int j{2}; j < s.size(); ++j) cout << s[j];
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
