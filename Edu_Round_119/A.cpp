//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
	string s{}, t{};
	cin >> s;
	
	cout << (count(s.begin(), s.end(), 'N') == 1 ? "NO\n"s : "YES\n"s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
