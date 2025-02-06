#include <iostream>
#include <string>

using namespace std;

void solve() {
	string s, t;
	cin >> s >> t;

	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());

	int i{0}, j{0};
	while (i < s.size() && j < t.size()) {
		while (i < s.size() && s[i] != t[j]) i += 2;
		if (i >= s.size()) break;
		++i, ++j;
	}

	cout << (j == t.size() ? "YES\n"s : "NO\n"s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
