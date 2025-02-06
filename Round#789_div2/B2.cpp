//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	int ans1{0}, ans2{0};
	char flag{'2'};
	for (int i{0}; i < n; i += 2) {
		if (v[i] != v[i + 1]) ++ans1;
		else if (v[i] != flag) ++ans2, flag = v[i];
	}
	ans2 += (flag == '2');

	cout << ans1 << ' ' << ans2 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
