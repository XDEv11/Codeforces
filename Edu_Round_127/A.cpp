//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <string>

using namespace std;

void solve() {
	string s;
	cin >> s;

	for (int i{0}; i < s.size(); ) {
		int j{i + 1};
		while (j < s.size() && s[j] == s[i]) ++j;
		if (j - i == 1) return cout << "NO\n", []{}();
		i = j;
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
