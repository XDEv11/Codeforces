//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int maxn{40000};
vector<int> primes{[](){
	vector<int> p{};
	vector<bool> c(maxn + 1);
	for (int i{2}; i * i <= maxn; ++i) {
		if (c[i]) continue;
		for (int j{i * i}; j <= maxn; j += i) c[j] = true;
	}
	for (int i{2}; i <= maxn; ++i) {
		if (c[i]) continue;
		p.push_back(i);
	}
	return p;
}()};

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	for (auto& p : primes) {
		int cnt{0};
		for (auto& x : v) {
			if (x % p) continue;
			while (x % p == 0) x /= p;
			++cnt;
			if (cnt >= 2) return cout << "YES\n", []{}();
		}
	}


	set<int> s{};
	for (auto& x : v) {
		if (x == 1) continue;
		if (s.count(x)) return cout << "YES\n", []{}();
		s.insert(x);
	}

	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
