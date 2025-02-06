//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>

using namespace std;

namespace {
	void solve() {
		string s{};
		cin >> s;
		int n{s.size()};

		for (int i{0}; i + 1 < n; ++i) {
			if (s[i] == s[i + 1]) return cout << s.substr(i, 2) << '\n', []{}();
		}
		for (int i{0}; i + 2 < n; ++i) {
			if (s[i] != s[i + 2]) return cout << s.substr(i, 3) << '\n', []{}();
		}
		cout << "-1\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
