//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
	string s{};
	cin >> s;

	int c0{count(s.begin(), s.end(), '0')};
	if (c0 == s.size() - c0) cout << c0 - 1 << '\n';
	else cout << min(c0, int(s.size() - c0)) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
