class Solution {
public:
        
    void findCombinationSum(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        if(target == 0)
        {
            ans.push_back(ds);
            return;
        }

        if(ind == arr.size() || target < 0)
            return;

        if(arr[ind] <= target)
        {
            ds.push_back(arr[ind]);
            findCombinationSum(ind, target-arr[ind], arr, ans, ds);
            ds.pop_back();
        }
        findCombinationSum(ind+1,target,arr,ans,ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
            
        sort(candidates.begin(), candidates.end());
        findCombinationSum(0,target,candidates,ans,ds);
        return ans;
    }
};


// void findCombinationSum(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
// {
//     if(target == 0)
//     {
//         ans.push_back(ds);
//         return;
//     }

//     if(ind == arr.size() || target < 0)
//         return;

//     if(arr[ind] <= target)
//     {
//         ds.push_back(arr[ind]);
//         findCombinationSum(ind, target-arr[ind], arr, ans, ds);
//         ds.pop_back();
//     }
//     findCombinationSum(ind+1,target,arr,ans,ds);
// }

// vector<vector<int>> combSum(vector<int> &ARR, int B)
// {
//     // Write your code here.
//     vector<vector<int>> ans;
//     vector<int> ds;
        
//     sort(ARR.begin(), ARR.end());
//     findCombinationSum(0,B,ARR,ans,ds);
//     return ans;
    
// }