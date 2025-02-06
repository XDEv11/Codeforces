//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
	string s;
	cin >> s;
	sort(s.begin(), s.end());

	cout << s << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
