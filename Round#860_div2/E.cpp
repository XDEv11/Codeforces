//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<int> cnt(n + 1, -1); cnt[n] = 0;
	for (int i{n - 1}; i >= 0; --i) {
		if (i + v[i] < n && cnt[i + v[i] + 1] != -1) cnt[i] = cnt[i + v[i] + 1] + 1;
	}
	vector<int> cnt2(n + 1);
	int mx{0};
	for (int i{n - 1}; i >= 0; --i) {
		cnt2[i] = mx + 1;
		if (i + v[i] < n) cnt2[i] = max(cnt2[i], cnt2[i + v[i] + 1] + 1);
		mx = max(mx, cnt[i]);
	}

	for (int i{0}; i + 1 < n; ++i) {
		if (v[i] == cnt[i + 1]) cout << "0 ";
		else if (cnt[i + 1] != -1 || v[i] <= cnt2[i + 1]) cout << "1 ";
		else cout << "2 ";
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
