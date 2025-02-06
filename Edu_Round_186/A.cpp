//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		string s(n, 'a');
		for (auto& x : s) cin >> x;

		cout << (s.find("2026") != s.npos || s.find("2025") == s.npos ? "0\n" : "1\n");
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
