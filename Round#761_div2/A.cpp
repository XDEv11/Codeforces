//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <array>

using namespace std;

void solve() {
	string s{}, t{};
	cin >> s >> t;

	array<int, 26> cnt{};
	for (auto& x : s) ++cnt[x - 'a'];

	if (!cnt[0] || !cnt[1] || !cnt[2] || t != "abc"s) {
		while (cnt[0]--) cout << 'a';
		while (cnt[1]--) cout << 'b';
		while (cnt[2]--) cout << 'c';
	} else {
		while (cnt[0]--) cout << 'a';
		while (cnt[2]--) cout << 'c';
		while (cnt[1]--) cout << 'b';
	}
	for (int i{3}; i < 26; ++i) {
		while (cnt[i]--) cout << char('a' + i);
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
