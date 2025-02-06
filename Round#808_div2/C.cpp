//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define fi first
#define se second

using namespace std;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	string s(n, '1');
	if (q < n) {


	}

	cout << s << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
