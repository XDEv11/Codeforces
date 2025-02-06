//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

namespace {
	template<typename T>
	using matrix = vector<vector<T>>;
	template<typename T>
	using tensor = vector<matrix<T>>;

	void solve() {
		int n, m;
		cin >> n >> m;
		matrix<int> a(n, vector<int>(m)), b{a};
		for (auto& v : a)
			for (auto& x : v) cin >> x;
		for (auto& v : b)
			for (auto& x : v) cin >> x;


	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
