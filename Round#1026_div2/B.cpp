//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>

using namespace std;

namespace {
	void solve() {
		string s{};
		cin >> s;
		int n{s.size()};

		int c{};
		for (int i{0}; i < n - 1; ++i) {
			if (s[i] == '(') ++c;
			else --c;
			if (c == 0) return cout << "YES\n", []{}();
		}
		cout << "NO\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
