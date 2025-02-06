//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
	int n;
	ll m;
	cin >> n >> m;
	vector<pair<ll, ll>> v(n);
	for (auto& [x, p] : v) cin >> x >> p;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
