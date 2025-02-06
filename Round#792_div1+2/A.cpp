//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
	string s;
	cin >> s;

	if (s.size() == 2) cout << s[1] << '\n';
	else cout << *min_element(s.begin(), s.end()) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
