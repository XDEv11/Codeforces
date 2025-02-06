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
	for (auto& c : s) ++cnt[c - 'a'];

	bool f{false};
	for (auto& c : s) {
		--cnt[c - 'a'];
		if (!cnt[c - 'a']) f = true;
		if (f) cout << c;
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
