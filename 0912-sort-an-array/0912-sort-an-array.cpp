// class Solution {
// public:
//     vector<int> sortArray(vector<int>& nums) {
//         int n = nums.size();
//         int flag = 0;
//         for(int i=0;i<n-1;i++)
//         {
//             for(int j=0;j<n-i-1;j++)
//             {
//                 if(nums[j] > nums[j+1])
//                 {
//                     int temp = nums[j];
//                     nums[j] = nums[j+1];
//                     nums[j+1] = temp;
//                     flag = 1;
//                 }
//             }
//             if(flag == 0)
//             {
//                 break;
//             }
//         }
//         return nums;
//     }
// };


class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }

};