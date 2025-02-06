//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int sstol(const string& ss, int i, int j) { // short string to label
	int l{0}, m{1};
	for (int k{i}; k < j; ++k) {
		l += (ss[k] - '0') * m;
		m *= 26;
	}
	return l;
}

void solve() {
	int n;
	cin >> n;
	vector<string> v(n);
	for (auto& x : v) cin >> x;

	for (auto& x : v) {
		if (x.length() == 1) return cout << "YES\n"s, []{}();
		if (x.front() == x.back()) return cout << "YES\n"s, []{}();
	}

	set<pair<int, int>> s{};
	for (auto& x : v) {
		if (x.length() == 3) {
			if (s.count({sstol(x, 0, 3), 3}) || s.count({sstol(x, 1, 3), 2})) return cout << "YES\n"s, []{}();
		} else if (x.length() == 2) {
			if (s.count({sstol(x, 0, 2), 2}) || s.count({sstol(x, 0, 2), 3})) return cout << "YES\n"s, []{}();
		}

		reverse(x.begin(), x.end());
		s.emplace(sstol(x, 0, x.length()), x.length());
		if (x.length() == 3) s.emplace(sstol(x, 1, 3), 3);
	}
	cout << "NO\n"s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
