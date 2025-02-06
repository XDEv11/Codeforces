//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <string>
#include <array>

using namespace std;

void solve() {
	string s;
	cin >> s;

	array<int, 26> cnt{};
	int i{1};
	while (i < s.size() && s[i] != s[0]) {
		if (++cnt[s[i++] - 'a'] == 2) return cout << "NO\n", []{}();
	}
	for (int j{i}, k{0}; j < s.size(); ++j, k = (k + 1) % i) {
		if (s[j] != s[k]) return cout << "NO\n", []{}();
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
