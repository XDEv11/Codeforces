//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> s(n), t(n);
	for (auto& x : s) cin >> x;
	for (auto& x : t) cin >> x;

	int pa{0}, pb{0}, pc{0};
	for (int i{0}; i < n; ++i) {
		if (pa == i) ++pa;
		while (pa < n && s[pa] != 'a') ++pa;
		if (pb == i) ++pb;
		while (pb < n && s[pb] != 'b') ++pb;
		if (pc == i) ++pc;
		while (pc < n && s[pc] != 'c') ++pc;

		if (s[i] == t[i]) continue;
		if (s[i] == 'a' && t[i] == 'b') {
			if (pb != n && pb < pc) {
				swap(s[i], s[pb]);
				while (pb < n && s[pb] != 'b') ++pb;
				continue;
			}
		} else if (s[i] == 'b' && t[i] == 'c') {
			if (pc != n && pc < pa) {
				swap(s[i], s[pc]);
				while (pc < n && s[pc] != 'c') ++pc;
				continue;
			}
		}
		return cout << "NO\n", []{}();
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
