//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <set>
#include <queue>

using namespace std;

void solve() {
	int n;
	cin >> n;
	long long s{0};
	multiset<long long> ms{};
	for (int i{0}; i < n; ++i) {
		long long x;
		cin >> x;
		ms.insert(x);
		s += x;
	}

	priority_queue<long long> qu{};
	qu.push(s);
	while (!qu.empty()) {
		auto x{qu.top()}; qu.pop();
		if (x < *ms.rbegin()) break;
		auto it{ms.find(x)};
		if (it == ms.end()) {
			if (x > 1) qu.push((x + 1) / 2), qu.push(x / 2);
		} else ms.erase(it);
	}

	cout << (ms.empty() ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
