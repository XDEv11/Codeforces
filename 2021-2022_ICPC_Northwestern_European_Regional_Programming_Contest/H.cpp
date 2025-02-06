//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

bool solve() {
	using ll = long long;
	const ll maxval{10000000000000ll};

	int n;
	if (!(cin >> n)) return false;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	ll l{-1}, r{maxval};
	while (r - l > 1) {
		ll m{(l + r) / 2};
		list<ll> lst{};
		for (int i{0}; i < n; ++i) lst.push_back(v[i]);
		for (auto it{lst.begin()}; it != lst.end(); ++it) {
			if (*it > m) continue;
			while (lst.size() > 1) {
				auto nx{next(it)};
				if (nx == lst.end()) nx = lst.begin();
				auto pv{it == lst.begin() ? prev(lst.end()) : prev(it)};
				if (*nx <= m + *it) *it += *nx, lst.erase(nx);
				else if (*pv <= m + *it) *it += *pv, lst.erase(pv);
				else break;
			}
		}
		(lst.size() == 1 ? r : l) = m;
	}

	return cout << r << '\n', true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
