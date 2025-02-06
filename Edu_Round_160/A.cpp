//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>

using namespace std;

void solve() {
	int n;
	string s{};
	cin >> s;
	if (s[0] == '0') return cout << "-1\n", []{}();

	int i{1};
	while (i < s.size() && s[i] == '0') ++i;
	if (i == s.size()) return cout << "-1\n", []{}();

	int a{stoi(s.substr(0, i))}, b{stoi(s.substr(i, s.size() - i))};
	if (a >= b) return cout << "-1\n", []{}();

	cout << a << ' ' << b << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
