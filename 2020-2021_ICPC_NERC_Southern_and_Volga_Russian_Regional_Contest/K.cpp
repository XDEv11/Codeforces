//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>

using namespace std;

void solve() {
	string s{};
	cin >> s;
	int n{s.size()};

	int x{0}, y{0};
	for (int i{0}; i < n; ++i) {
		switch (s[i]) {
			break; case 'L': --x;
			break; case 'R': ++x;
			break; case 'D': --y;
			break; case 'U': ++y;
		}
		if (!x && !y) continue;
		int xx{0}, yy{0};
		for (int j{0}; j < n; ++j) {
			if (s[j] == 'L') {
				if (xx - 1 != x || yy != y) --xx;
			} else if (s[j] == 'R') {
				if (xx + 1 != x || yy != y) ++xx;
			} else if (s[j] == 'D') {
				if (xx != x || yy - 1 != y) --yy;
			} else if (s[j] == 'U') {
				if (xx != x || yy + 1 != y) ++yy;
			}
		}
		if (!xx && !yy) return cout << x << ' ' << y << '\n', []{}();
	}
	cout << "0 0\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
