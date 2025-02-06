#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
	int n, u, v;
	cin >> n >> u >> v;
	vector<int> vt(n);
	for (auto& x : vt) cin >> x;

	{
		bool flag{true};
		for (int i{1}; i < n; ++i) if (vt[i] != vt[0]) flag = false;
		if (flag) {
			cout << v + min(u, v) << '\n';
			return ;
		}
	}
	{
		bool flag{true};
		for (int i{1}; i < n; ++i) if (abs(vt[i] - vt[i - 1]) > 1) flag = false;
		if (flag) {
			cout << min(u, v) << '\n';
			return ;
		}
	}
	cout << "0\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
