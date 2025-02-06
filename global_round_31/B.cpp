//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<string> v(n);
		for (auto& x : v) cin >> x;

		string a{};
		for (auto& x : v) {
			string t1{a + x}, t2{x + a};
			a = (t1 < t2 ? t1 : t2);
		}

		cout << a << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
