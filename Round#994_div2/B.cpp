//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<char> v(n);
		for (auto& x : v) cin >> x;

		int cs{count(v.begin(), v.end(), 's')}, cp{count(v.begin(), v.end(), 'p')};

		cout << (cs == 0 || (cs == 1 && v[0] == 's') || cp == 0 || (cp == 1 && v[n - 1] == 'p') ? "YES\n" : "NO\n");
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
