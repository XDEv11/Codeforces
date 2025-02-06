#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class forest {
	
	
};

void solve() {
	int n;
	cin >> n;

	vector<int> fib{1, 0};
	for (int i{2}; ; ++i) {
		fib.push_back(fib[i] + fib[i - 1]);
		if (fib[i + 1] > n) return cout << "NO\n"s, []{}();
		if (fib[i + 1] == n) break;
	}

	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
