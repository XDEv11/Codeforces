//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>

using namespace std;

void solve() {
	string s{};
	cin >> s;

	for (int i{1}; i < s.size() - 1 - i; ++i)
		if (s[i] != s[0]) return cout << "YES\n", []{}();
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
