#include "common.h"

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {

		int n = (int)nums.size();
		int l = 0, r = n - 1;
		int find = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (nums[mid] == target) {
				find = mid;
				break;
			}
			if (nums[mid] > target) {
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		if (find == -1) {
			return vector<int>{-1, -1};
		} 
		l = r = find;
		while (l > 0 && nums[l - 1] == target) l--;
		while (r < n - 1 && nums[r + 1] == target) r++;
		return vector<int>{l, r};
	}
};
//
//int main() {
//
//	Solution obj;
//	vector<int> nums{ 5,7,7,8,8,10};
//	auto ans = obj.searchRange(nums, 8);
//	cout << ans[0] << ' ' << ans[1] << endl;
//	system("pause");
//}