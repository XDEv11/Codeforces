#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

void solve() {
	string s;
	cin >> s;

	int n{s.size()};
	array<int, 26> cnt{};
	for (auto& x : s) ++cnt[x - 'a'];

	int x{-1}, c{n + 1};
	for (int i{0}; i < 26; ++i) {
		if (!cnt[i]) continue;
		if (cnt[i] < c) x = i, c = cnt[i];
	}

	if (c == n) cout << s;
	else if (c == 1) {
		cout << char('a' + x);
		for (int i{0}; i < 26; ++i) {
			if (i == x) continue;
			while (cnt[i]--) cout << char('a' + i);
		}
	} else {
		x = -1;
		int y, z;
		for (int i{25}; i >= 0; --i) {
			if (!cnt[i]) continue;
			z = y, y = x, x = i;
		}
		if (cnt[x] - 2 > n - cnt[x]) {
			if (z == -1) {
				cout << char('a' + x), --cnt[x];
				while (cnt[y]--) cout << char('a' + y);
				while (cnt[x]--) cout << char('a' + x);
			} else {
				cout << char('a' + x), --cnt[x];
				cout << char('a' + y), --cnt[y];
				while (cnt[x]--) cout << char('a' + x);
				cout << char('a' + z), --cnt[z];
				for (int i{0}; i < 26; ++i) {
					if (i == x) continue;
					while (cnt[i]--) cout << char('a' + i);
				}
			}
		} else {
			cout << char('a' + x), --cnt[x];
			cout << char('a' + x), --cnt[x];
			for (int i{0}; i < 26; ++i) {
				if (i == x) continue;
				while (cnt[i]--) {
					cout << char('a' + i);
					if (cnt[x]) cout << char('a' + x), --cnt[x];
				}
			}
		}
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
