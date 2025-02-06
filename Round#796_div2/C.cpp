//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<string> v(2 * n);
	for (auto& x : v) cin >> x;
	string s;
	cin >> s;

	array<int, 26> cnt{};
	for (auto& x : v)
		for (auto& c : x) ++cnt[c - 'a'];
	for (auto& c : s) --cnt[c - 'a'];

	for (int i{0}; i < 26; ++i)
		if (cnt[i] & 1) cout << char(i + 'a') << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
