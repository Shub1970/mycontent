<<<<<<< HEAD


#include <iostream>
#include <vector>

using namespace std;
// class Solution
// {
// public:
//    int climbStairs(int n)
//    {
//       // base condition
//       if (n == 0)
//       {
//          return 1;
//       }
//       else if (n < 0)
//       {
//          return 0;
//       }
//       return climbStairs(n - 1) + climbStairs(n - 2);
//    }
// };

// memorization

#include <vector>

// class Solution
// {
//    vector<int> memory;

// public:
//    Solution() : memory(46, -1) {}
//    int climbStairs(int n)
//    {
//       if (n == 0)
//       {
//          return 1;
//       }
//       else if (n < 0)
//       {
//          return 0;
//       }
//       else if (memory[n] != -1)
//       {
//          return memory[n];
//       }

//       memory[n] = climbStairs(n - 1) + climbStairs(n - 2);
//       return memory[n];
//    }
// };

// tabulation

class Solution
{
public:
   int climbStairs(int n)
   {
      int memory[45] = {-1};
      memory[0] = 1;
      memory[1] = 1;
      for (int x = 2; x <= n; ++x)
      {
         memory[x] = memory[x - 1] + memory[x - 2];
         cout << memory[x] << endl;
      }
      return memory[n];
   }
};

int main()
{
   Solution obj;
   cout << obj.climbStairs(3);
}
=======
// You are given an m x n integer matrix matrix with the following two properties:

//     Each row is sorted in non-decreasing order.
//     The first integer of each row is greater than the last integer of the previous row.

// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.


#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int y=matrix.size();
        int x=matrix[0].size();
        int initial=0;
        int final=x*y-1;
        while(initial<=final){
         int mid=(initial+final)/2;
         int row=mid/x;
         int col=mid%x;
         if(matrix[row][col]==target){
            return true;
         }
         else if(matrix[row][col]<target){
            initial=mid+1;
         }
         else{
            final=mid-1;
         }
        }
        return false;
    }
};
>>>>>>> 7291062253fdb93586200b8010d4f53f5d6abd41
