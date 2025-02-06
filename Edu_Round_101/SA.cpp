#include <iostream>
#include <string>

using namespace std;

void solve() {
	string s;
	cin >> s;
	const size_t& n{s.size()};

	if (n & 1) {
		cout << "NO\n";
		return ;
	}
	{
		int cnt{0}, q{0};
		for (int i{0}; i < n; ++i) {
			if (s[i] == '?') ++q;
			else if (s[i] == '(') ++cnt;
			else if (s[i] == ')') {
				if (cnt) --cnt;
				else if (q) --q;
				else {
					cout << "NO\n";
					return ;
				}
			}
		}
	}
	{
		int cnt{0}, q{0};
		for (int i{n - 1}; i >= 0; --i) {
			if (s[i] == '?') ++q;
			else if (s[i] == ')') ++cnt;
			else if (s[i] == '(') {
				if (cnt) --cnt;
				else if (q) --q;
				else {
					cout << "NO\n";
					return ;
				}
			}
		}
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
