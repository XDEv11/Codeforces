#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	vector<int> cnt0(k, 0), cnt1(k, 0);
	for (int i{0}; i < n; ++i) {
		for (int j{0}; j < k && i - j >= 0; ++j)
			if (v[i] == '0') ++cnt0[j];
			else ++cnt1[j];
	}
	for (auto& x : cnt0) cout << x << ' ';
	cout << endl;
	for (auto& x : cnt1) cout << x << ' ';
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
