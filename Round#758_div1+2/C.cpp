//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> sa(n), sb(n);
	for (auto& x : sa) cin >> x;
	for (auto& x : sb) cin >> x;

	vector<pair<int, int>> a(n), b(n);
	for (int i{0}; i < n; ++i) {
		a[i] = {sa[i], i};
		b[i] = {sb[i], i};
	}
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());

	vector<int> pa(n), pb(n);
	for (int i{0}; i < n; ++i) {
		pa[a[i].se] = i;
		pb[b[i].se] = i;
	}

	int ia{0}, ib{0}, la{0}, lb{0};
	while (true) {
		if (ia <= la) lb = max(lb, pb[a[ia].se]), ++ia;
		else if (ib <= lb) la = max(la, pa[b[ib].se]), ++ib;
		else break;
	}

	for (int i{0}; i < n; ++i) {
		if (pa[i] <= la || pb[i] <= lb) cout << '1';
		else cout << '0';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
