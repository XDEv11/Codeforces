//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int h{1 + (v[0] == 1)};
	for (int i{1}; i < n; ++i) {
		if (v[i]) h += (v[i - 1] ? 5 : 1);
		else if (!v[i - 1]) return cout << "-1\n"s, []{}();
	}
	cout << h << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
