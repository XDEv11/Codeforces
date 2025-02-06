//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	if (k & 1) {
		vector<char> v0{}, v1{};
		for (int i{0}; i < n; ++i) (i & 1 ? v1 : v0).push_back(v[i]);
		sort(v0.begin(), v0.end());
		sort(v1.begin(), v1.end());
		for (int i{0}; i < v0.size(); ++i) {
			cout << v0[i];
			if (i < v1.size()) cout << v1[i];
		}
		cout << '\n';
	} else {
		sort(v.begin(), v.end());
		for (auto& x : v) cout << x;
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
