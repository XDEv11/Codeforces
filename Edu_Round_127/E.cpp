//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long mod{998244353};

void solve() {
	int n;
	cin >> n;
	vector<char> v((1 << n) - 1);
	for (auto& x : v) cin >> x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
