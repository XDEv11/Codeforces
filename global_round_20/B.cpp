//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <string>

using namespace std;

void solve() {
	string s;
	cin >> s;

	int c{0};
	for (int i{0}; i < s.size(); ++i) {
		if (s[i] == 'A') ++c;
		else --c;
		if (c < 0) return cout << "NO\n", []{}();
	}
	if (s.back() != 'B') cout << "NO\n";
	else cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
