//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <string>

using namespace std;

void solve() {
	string s{};
	cin >> s;

	for (int i{1}; i < s.size(); ++i)
		for (int j{i + 1}; j < s.size(); ++j) {
			string a{s.begin(), s.begin() + i};
			string b{s.begin() + i, s.begin() + j};
			string c{s.begin() + j, s.end()};
			if ((b <= a && b <= c) || (b >= a && b >= c)) return cout << a << ' ' << b << ' ' << c << '\n', []{}();
		}
	cout << ":(\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
