//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	multiset<int> ms{};
	for (auto& x : v) ms.insert(x);

	int m{0};
	while (ms.count(m)) ++m;

	if (m == 0) return cout << "Yes\n", []{}();
	else if (m == n) return cout << "No\n", []{}();

	int l{-1}, r{0};
	for (int i{0}; i < n; ++i) {
		if (v[i] != m + 1) continue;
		if (l == -1) l = i;
		r = i;
	}
	if (l == -1) return cout << "Yes\n", []{}();

	for (int i{l}; i <= r; ++i) ms.erase(ms.find(v[i]));
	int cnt{0};
	for (int i{0}; i <= m; ++i) cnt += !ms.count(i);
	cout << (cnt <= 1 ? "Yes\n" : "No\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
