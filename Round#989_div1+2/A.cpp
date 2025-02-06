//#pragma GCC optimize ("O3")

#include <iostream>
#include <numeric>

using namespace std;

namespace {
	void solve() {
		int a, b;
		cin >> a >> b;

		cout << lcm(a, b) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
