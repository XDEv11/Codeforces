//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	for (auto& e : v) cin >> e;

	vector<int> cnt(x + 1);
	for (auto& e : v) ++cnt[e];

	for (int i{1}; i < x; ++i) {
		if (cnt[i] % (i + 1) == 0) {
			cnt[i + 1] += cnt[i] / (i + 1);
		} else return cout << "No\n", []{}();
	}
	cout << "Yes\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
