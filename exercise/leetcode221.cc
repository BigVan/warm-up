#include "common.h"

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {

		n = matrix.size();
		if (n == 0) return 0;
		m = matrix[0].size();
		if (m == 0) return 0;
		sum.resize(n);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			sum[i].resize(m);
			// cout<< i << endl;
			for (int j = 0; j < m; j++) {
				sum[i][j] = Sum(i - 1, j) + Sum(i, j - 1) - Sum(i - 1, j - 1) + (matrix[i][j] == '1');
				int l = 1, r = min(i, j) + 1;
				while (l <= r) {
					int mid = (l + r) >> 1;
					int count = mid*mid;
					int st_i = i - mid, st_j = j - mid;
					int delta = Sum(i, j) - Sum(i, st_j) - Sum(st_i, j) + Sum(st_i, st_j);
					if (delta == count) {
						ans = (ans > count ? ans : count);
						l = mid + 1;
					}
					else {
						r = mid - 1;
					}

				}
			}
		}
		return ans;
	}


private:
	int n, m;
	vector<vector<int>> sum;
	int Sum(int x, int y) {
		if (x < 0 || y < 0) return 0;
		return sum[x][y];
	}
};
//
//int main() {
//
//	Solution obj;
////	vector<vector<char>> matrix{ {"1", "0", "1", "0", "0"}, { "1", "0", "1", "1", "1"}, { "1", "1", "1", "1", "1" }, { "1", "0", "0", "1", "0" } };
//
//}