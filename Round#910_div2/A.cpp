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

	int c{count(v.begin(), v.end(), 'B')};
	if (c != k) {
		cout << "1\n";
		if (c < k) {
			int i{0};
			while (c < k) c += (v[i++] == 'A');
			cout << i << " B\n";
		} else {
			int i{0};
			while (c > k) c -= (v[i++] == 'B');
			cout << i << " A\n";
		}
	} else cout << "0\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
