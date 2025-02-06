//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	array<char, 4> a;
	for (auto& x : a) cin >> x;

	array<int, 10> cnt{};
	for (auto& x : a) ++cnt[x - '0'];

	vector<int> sz{};
	for (auto& x : cnt) {
		if (x) sz.push_back(x);
	}
	sort(sz.rbegin(), sz.rend());

	if (sz[0] == 4) cout << "-1\n";
	else if (sz[0] == 3) cout << "6\n";
	else cout << "4\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
