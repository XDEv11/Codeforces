//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>

using namespace std;

namespace {
	void solve() {
		string s{};
		cin >> s;
		int n{s.size()};

		for (int i{0}; ; ++i) {
			if (i + 1 == n || s[i] == s[i + 1]) {
				for (int j{0}; j <= i; ++j) cout << s[j];
				cout << (s[i] == 'z' ? 'y' : 'z');
				for (int j{i + 1}; j < n; ++j) cout << s[j];
				cout << '\n';
				break;
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
