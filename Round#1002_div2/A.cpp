//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;

		sort(a.begin(), a.end()), a.erase(unique(a.begin(), a.end()), a.end());
		sort(b.begin(), b.end()), b.erase(unique(b.begin(), b.end()), b.end());

		if (a.size() >= 3 || b.size() >= 3 || (a.size() == 2 && b.size() == 2)) cout << "YES\n";
		else cout << "NO\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
