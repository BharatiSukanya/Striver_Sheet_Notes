// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // Step 1 =  Find xor of all elements in the array 
        // Step 2 = Find xor of step1 ans with numbers from 1 to n 
        int xorr = 0;
        for(int i=0;i<n;i++)
        {
            xorr^=arr[i];
            xorr^=(i+1);
        }
        
        // Now to find the significant bit , perfrom the below operation 
        int rightSBit = xorr & (-xorr);
        int x = 0;
        int y = 0;
        
        // Now numbers with same significant bit in the given array, xor them together 
        for(int i=0;i<n;i++)
        {
            if((rightSBit & arr[i])==0)
                x^=arr[i];
            else
                y^=arr[i];
        }
        
        // Similarly numbers from 1 to n with the same significant bits, xor them together 
        for(int i=1;i<=n;i++)
        {
            if((rightSBit & i)==0)
                x^=i;
            else
                y^=i;
        }
        
        int *ans = new int(2);
        
        // Final step : If x is found in array means it is repeating and y is missing & vice versa 
        for(int i=0;i<n;i++)
        {
            if(arr[i]==x)
            {
                ans[0]=x;
                ans[1]=y;
            }
            
            if(arr[i]==y)
            {
                ans[0]=y;
                ans[1]=x;
            }
        }
        return ans;
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends
