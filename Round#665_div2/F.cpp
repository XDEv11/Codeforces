#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, q;
	cin >> n;
	vector<int> vec(n);
	cin >> vec[0];
	for (int i = 1; i < n; ++i) {
		cin >> vec[i];
		vec[i] += vec[i - 1];
	}
	while (q--) {
		
		
	}
	return 0;
}
