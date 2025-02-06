//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		string s{};
		cin >> s;

		cout << count(s.begin(), s.end(), '1') << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
