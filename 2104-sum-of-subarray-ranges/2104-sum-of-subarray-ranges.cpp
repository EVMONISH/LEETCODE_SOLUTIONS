class Solution {
public:

    vector<int> findNSE(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);

        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
    }

    vector<int> findPSEE(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }

    vector<int> findNGE(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);

        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && arr[st.top()] < arr[i]) { // ✅ FIXED
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
    }

    vector<int> findPGEE(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[st.top()] <= arr[i]) { // ✅ FIXED
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }

    long long SumSubArrayMins(vector<int> &arr) {
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        int n = arr.size();
        long long sum = 0;

        for(int i=0; i<n; i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;

            long long freq = left * right;
            sum += freq * arr[i];
        }
        return sum;
    }

    long long SumSubArrayMaxs(vector<int> &arr) {
        vector<int> nge = findNGE(arr);
        vector<int> pgee = findPGEE(arr);

        int n = arr.size();
        long long sum = 0;

        for(int i=0; i<n; i++) {
            long long left = i - pgee[i];
            long long right = nge[i] - i;

            long long freq = left * right;
            sum += freq * arr[i];
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        return SumSubArrayMaxs(nums) - SumSubArrayMins(nums);
    }
};