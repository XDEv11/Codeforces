//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
	string s{};
	cin >> s;
	int n{s.length()};

	vector<int> c1(n + 1);
	for (int i{0}; i < n; ++i) c1[i + 1] = c1[i] + (s[i] == '1');

	int l{-1}, r{n};
	while (r - l > 1) {
		int m{(l + r) / 2};

		bool f{false};
		int c{0}, i{0}, j{0};
		while (j < n && c < m) c += (s[j++] == '0');
		while (j < n && s[j] != '0') ++j;
		while (true) {
			if (c1[i] + c1[n] - c1[j] <= m) {
				f = true;
				break;
			}
			if (j == n) break;
			++j;
			while (j < n && s[j] != '0') ++j;
			while (i < j && s[i] != '0') ++i;
			++i;
		}

		if (f) r = m;
		else l = m;
	}

	cout << r << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
