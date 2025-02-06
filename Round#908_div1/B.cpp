//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	vector<int> l(n);
	vector<int> v{a[0]};
	l[0] = 1;
	for (int i{1}; i < n; ++i) {
		if (a[i] <= v.back()) {
			auto it{lower_bound(v.begin(), v.end(), a[i])};
			*it = a[i];
			l[i] = distance(v.begin(), it) + 1;
		} else v.push_back(a[i]), l[i] = v.size();
	}

	sort(b.rbegin(), b.rend());

	int j{0};
	for (int i{0}; i < n; ++i) {
		if (l[i] == v.size()) {
			for (; j < m && b[j] >= a[i]; ++j) cout << b[j] << ' ';
		}
		cout << a[i] << ' ';
	}
	for (; j < m; ++j) cout << b[j] << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
