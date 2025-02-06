//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <array>
#include <utility>
#define fi first
#define se second
#include <algorithm>
#include <cstdlib>

using namespace std;

char Ask1(int i) { // no more than 26 times
	cout << "? 1 " << i + 1 << endl;
	char ret;
	if (!(cin >> ret) || ret == '0') exit(EXIT_FAILURE);
	return ret;
}

int Ask2(int l, int r) { // no more than 6000 times
	if (l == r) return 1;
	cout << "? 2 " << l + 1 << ' ' << r + 1 << endl;
	int ret;
	if (!(cin >> ret) || ret == 0) exit(EXIT_FAILURE);
	return ret;
}

void Ans(const vector<char>& s) {
	cout << "! ";
	for (auto& x : s) cout << x;
	cout << endl;
}

void solve() {
	int n;
	cin >> n;
	vector<char> s(n);

	array<int, 26> fi; fi.fill(-1);
	char c{Ask1(0)};
	s[0] = c;
	fi[c - 'a'] = 0;
	int cnt{1};
	for (int i{1}; i < n; ++i) {
		int cnt2{Ask2(0, i)};
		if (cnt2 > cnt) {
			cnt = cnt2;
			c = Ask1(i);
			s[i] = c;
			fi[c - 'a'] = i;
		}
		if (cnt == 26) break;
	}

	array<int, 26> la; la.fill(-1);
	for (int i{0}; i < n; ++i) {
		if (s[i]) {
			la[s[i] - 'a'] = i;
			continue;
		}

		vector<pair<int, char>> v{};
		for (int k{0}; k < 26; ++k) {
			if (la[k] == -1) continue;
			v.emplace_back(la[k], k + 'a');
		}
		sort(v.begin(), v.end());
		int l{0}, r{v.size() - 1};
		while (r > l) {
			int m{(l + r) / 2};
			array<bool, 26> vis{};
			int c1{0};
			for (int j{v[m].fi + 1}; j <= i - 1; ++j) {
				if (vis[s[j] - 'a']) continue;
				vis[s[j] - 'a'] = true;
				++c1;
			}
			int c2{Ask2(v[m].fi + 1, i)};
			if (c2 == c1) l = m + 1;
			else r = m;
		}
		s[i] = v[l].se;
		la[v[l].se - 'a'] = i;
	}

	Ans(s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
