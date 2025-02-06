//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <list>
#include <iterator>
#include <utility>
#define fi first
#define se second

using namespace std;
void solve() {
	int n, k;
	cin >> n >> k;
	list<pair<int, long long>> a(n);
	for (auto& [x, c] : a) cin >> x, c = 1;
	int m;
	cin >> m;
	list<pair<int, long long>> b(m);
	for (auto& [x, c] : b) cin >> x, c = 1;

	for (auto& [x, c] : a) {
		while (x % k == 0) x /= k, c *= k;
	}
	for (auto& [x, c] : b) {
		while (x % k == 0) x /= k, c *= k;
	}
	auto ita{a.begin()}, itb{b.begin()};
	while (next(ita) != a.end()) {
		if (next(ita)->fi == ita->fi) {
			ita->se += next(ita)->se;
			a.erase(next(ita));
		} else ita = next(ita);
	}
	while (next(itb) != b.end()) {
		if (next(itb)->fi == itb->fi) {
			itb->se += next(itb)->se;
			b.erase(next(itb));
		} else itb = next(itb);
	}

	if (a == b) cout << "Yes\n";
	else cout << "No\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
