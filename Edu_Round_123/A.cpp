//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <string>
#include <array>

using namespace std;

void solve() {
	string s;
	cin >> s;

	array<bool, 26> k{};
	for (auto& x : s)
		if (isupper(x)) {
			if (!k[x - 'A']) return cout << "NO\n", []{}();
		} else k[x - 'a'] = true;
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
