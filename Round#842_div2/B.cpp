//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> p(n);
	for (auto& x : p) cin >> x, --x;

	vector<int> idx(n);
	for (int i{0}; i < n; ++i) idx[p[i]] = i;

	int cnt{n - 1};
	for (int i{1}; i < n; ++i) {
		if (idx[i] > idx[i - 1]) --cnt;
		else break;
	}
	cout << (cnt + k - 1) / k << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
