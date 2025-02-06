//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> v(n + 1);
	for (int i{1}; i <= n; ++i) cin >> v[i];

	vector<int> cnt(n + 1), ck(n + 1);
	ck[1] = 1, cnt[1] = 1;
	for (int i{2}; i <= n; ++i) {
		ck[i] = (i == 2 || (v[i - 1] < v[i] || v[i - 2] < v[i - 1]));
		cnt[i] = cnt[i - 1] + ck[i];
	}

	while (q--) {
		int l, r;
		cin >> l >> r;

		cout << cnt[r] - cnt[l - 1] + (!ck[l]) + (l + 1 <= r && !ck[l + 1]) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
