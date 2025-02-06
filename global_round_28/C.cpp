//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>

using namespace std;

namespace {
	void solve() {
		string s{};
		cin >> s;
		int n{s.size()};

		cout << "1 " << n << ' ';

		int i{0};
		while (i < n && s[i] == '1') ++i;
		if (i == n) return cout << "1 1\n", []{}();

		int j{i};
		while (j < n && s[j] == '0') ++j;

		++i, ++j;

		if (j - i >= i - 1) cout << "1 " << (n - (i - 1)) << '\n';
		else cout << (i - (j - i)) << ' ' << (n - (j - i)) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
