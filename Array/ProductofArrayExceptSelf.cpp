#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);

        vector<int> ltr(n,1);
        for(int i=1;i<n;i++){
            ltr[i]=nums[i-1]*ltr[i-1];
        }
        // ltr[0]=nums[0];

        vector<int> rtl(n,1);
        for(int i=n-2;i>=0;i--){
            rtl[i]=nums[i+1]*rtl[i+1];
        }
        // rtl[n-1]=nums[n-1];

        for(int i=0;i<n;i++){
            ans[i]=ltr[i]*rtl[i];
        }

        return ans;
    }
};