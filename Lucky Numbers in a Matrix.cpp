class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int>arr1(n,0),arr2(m,0),ans;
        for(int i=0;i<n;i++){
            int minm=matrix[i][0];
            for(int j=1;j<m;j++)
                minm=min(minm,matrix[i][j]);
            arr1[i]=minm;
        }
        
        for(int i=0;i<m;i++){
            int maxm=matrix[0][i];
            for(int j=1;j<n;j++)
                maxm=max(maxm,matrix[j][i]);
            arr2[i]=maxm;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==arr1[i] && matrix[i][j]==arr2[j])
                    ans.push_back(matrix[i][j]);
            }
        }
        return ans;
    }
};

/*
    Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.    
    A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.
        
    Example 1:
    Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
    Output: [15]
    Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.
    
    Example 2:
    Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
    Output: [12]
    Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
    
    Example 3:
    Input: matrix = [[7,8],[1,2]]
    Output: [7]
    Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.
    
    T.C : O(n*m)
    S.C : O(n)
*/
