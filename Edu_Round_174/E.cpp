//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		string s{};
		cin >> s;
		int n{s.size()};
		int a, b, ab, ba;
		cin >> a >> b >> ab >> ba;

		int sab{}, sa{}, sb{};
		vector<int> va{}, vb{};
		char f{s[0]}; int c{1};
		for (int i{1}; i <= n; ++i) {
			if (i == n || (c % 2 && s[i] == f) || (c % 2 == 0 && s[i] != f)) {
				if (f == 'A') {
					if (c & 1) --a, sab += c / 2;
					else sa += c /= 2, va.push_back(c);
				} else {
					if (c & 1) --b, sab += c / 2;
					else sb += c /= 2, vb.push_back(c);
				}
				f = s[i], c = 1;
			} else ++c;
		}

		if (sa >= ab && sb >= ba) {
			int t{(sa - ab) + (sb - ba)};
			a -= t, b -= t, sa = ab, sb = ba;
		} else if (sa >= ab) {
			sort(va.rbegin(), va.rend());
			for (auto& x : va) {
				if (sa <= ab) break;
				int t{min(sa - ab, x)};
				sa -= t, --a, --b, sab += t - 1;
			}
		} else if (sb >= ba) {
			sort(vb.rbegin(), vb.rend());
			for (auto& x : vb) {
				if (sb <= ba) break;
				int t{min(sb - ba, x)};
				sb -= t, --a, --b, sab += t - 1;
			}
		}

		cout << (a >= 0 && b >= 0 && ab >= sa && ba >= sb && ab + ba + min(a, b) >= sa + sb + sab ? "YES\n" : "NO\n");
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
