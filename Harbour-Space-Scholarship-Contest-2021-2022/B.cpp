#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
	string s{}, t{};
	cin >> s >> t;

	for (int i{0}; i < t.length(); ++i) {
		{
			int l{i - 1}, r{i + 1};
			while (l >= 0 && r < t.size() && t[l] == t[r]) --l, ++r;
			if (l == -1) {
				string u{t.substr(i, t.length() - i)};
				reverse(u.begin(), u.end());

				if (search(s.begin(), s.end(), u.begin(), u.end()) != s.end()) return cout << "YES\n"s, []{}();
			} else if (r == t.size()) {
				string u{t.substr(0, i + 1)};
				
				if (search(s.begin(), s.end(), t.begin(), t.begin() + i + 1) != s.end()) return cout << "YES\n"s, []{}();
			}
		}
	}
	cout << "NO\n"s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
