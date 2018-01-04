#include "common.h"

class Solution {
public:
	bool canJump(vector<int>& nums) {

		int n = nums.size();
		int max = nums[0];
		for (int i = 1; i < n; i++) {
			if (max < i) return false;
			max = (max > i + nums[i] ? max : i + nums[i]);
		}
		return true;
	}
};
//
//int main() {
//	Solution obj;
//	vector<int> nums{ 2,3,1,1,4 };
//	cout << obj.canJump(nums) << endl;
//	system("pause");
//
//}