//#pragma GCC optimize ("O3")

#include <iostream>
#include <set>
#include <array>

using namespace std;

void solve() {
	int n;
	cin >> n;
	multiset<int> s{};
	for (int i{0}; i < n; ++i) {
		int x;
		cin >> x;
		s.insert(x);
	}

	array<bool, 3> r{};
	for (auto& x : s) r[x % 3] = true;
	int mx{*s.rbegin()};

	if (!r[1] && !r[2]) cout << mx / 3 << '\n';
	else if (mx % 3 == 1 && (!r[2] || (!s.count(1) && !s.count(mx - 1)))) cout << (mx + 2) / 3 << '\n';
	else if (mx % 3 == 2 && !r[1]) cout << (mx + 2) / 3 << '\n';
	else cout << (mx + 2) / 3 + 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
