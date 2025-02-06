//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void solve() {
	string s;
	cin >> s;

	if (s.size() == 1) {
		cout << "Bob " << s[0] - 'a' + 1 << '\n';
	} else if (s.size() & 1) {
		int ans{0};
		for (int i{1}; i < s.size() - 1; ++i) ans += s[i] - 'a' + 1;
		ans += abs(s.front() - s.back());
		cout << "Alice " << ans << '\n';
	} else {
		int ans{0};
		for (int i{0}; i < s.size(); ++i) ans += s[i] - 'a' + 1;
		cout << "Alice " << ans << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
