//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <string>

using namespace std;

void solve() {
	static auto is_palindrome = [](const string& s) {
		for (int i{0}; i < s.size() - 1 - i; ++i)
			if (s[i] != s[s.size() - 1 - i]) return false;
		return true;
	};

	int n, k;
	string s;
	cin >> n >> k >> s;

	cout << (!k || is_palindrome(s) ? 1 : 2) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
