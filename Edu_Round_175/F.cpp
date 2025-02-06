//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<string> b(m);
		for (auto& x : b) cin >> x;
		vector<int> a(n);
		for (auto& x : a) cin >> x;

	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
