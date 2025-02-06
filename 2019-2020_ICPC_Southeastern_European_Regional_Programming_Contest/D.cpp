//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

bool solve() {
	string s{};
	if (!(cin >> s)) return false;
	int n{s.size() / 2};

	array<int, 26> cnt{};
	for (auto& c : s) ++cnt[c - 'a'];

	vector<pair<int, char>> v{};
	for (int c{0}; c < 26; ++c) {
		if (!cnt[c]) continue;
		v.emplace_back(cnt[c], c + 'a');
	}
	sort(v.rbegin(), v.rend());

	if (v[0].fi <= n) {
		sort(s.begin(), s.end());
		cout << "YES\n" << s << '\n';
	} else if (v.size() >= 3) {
		cout << "YES\n";
		for (int i{0}; i < n; ++i) cout << v[0].se;
		v[0].fi -= n;
		while (v[1].fi--) cout << v[1].se;
		while (v[0].fi--) cout << v[0].se;
		for (int k{2}; k < v.size(); ++k) {
			while (v[k].fi--) cout << v[k].se;
		}
		cout << '\n';
	} else if (v.size() == 2 && v[1].fi >= 3) {
		cout << "YES\n";
		for (int i{0}; i < n; ++i) cout << v[0].se;
		v[0].fi -= n;
		--v[1].fi, cout << v[1].se;
		while (v[0].fi--) cout << v[0].se;
		while (v[1].fi--) cout << v[1].se;
		cout << '\n';
	} else cout << "NO\n";
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
