//#pragma GCC optimize ("O3")

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	multiset<int> a{}, b{};
	for (int i{0}; i < n; ++i) {
		int x;
		cin >> x;
		a.insert(x);
	}
	for (int i{0}; i < m; ++i) {
		int x;
		cin >> x;
		b.insert(x);
	}

	if (k >= 2) k = 2 + (k & 1);
	for (int i{0}; i < k; ++i) {
		if (i & 1) {
			int bmn{*b.begin()}, amx{*a.rbegin()};
			if (bmn < amx) {
				b.erase(b.begin()), a.erase(prev(a.end()));
				b.insert(amx), a.insert(bmn);
			}
		} else {
			int amn{*a.begin()}, bmx{*b.rbegin()};
			if (amn < bmx) {
				a.erase(a.begin()), b.erase(prev(b.end()));
				a.insert(bmx), b.insert(amn);
			}
		} 
	}

	long long ans{};
	for (auto& x : a) ans += x;
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
