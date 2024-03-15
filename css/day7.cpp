<<<<<<< HEAD
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
   int memory[101];

public:
   Solution()
   {
      fill(memory, memory + 101, -1);
   }
   int max_money(vector<int> &nums, int n)
   {
      // base case
      if (n == 0)
      {
         return nums[0];
      }
      else if (n < 0)
      {
         return 0;
      }
      if (memory[n] != -1)
      {
         return memory[n];
      }
      // choice case
      int if_select = nums[n] + max_money(nums, n - 2);
      int if_not_select = max_money(nums, n - 1);
      return memory[n] = max(if_select, if_not_select);
   }
   int rob(vector<int> &nums)
   {
      return max_money(nums, nums.size() - 1);
   }
};

int main()
{
   Solution obj;
   vector<int> ob = {2, 7, 9, 3, 1};
   obj.rob(ob);
}

// memorization
=======
// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

//     Integers in each row are sorted in ascending from left to right.
//     Integers in each column are sorted in ascending from top to bottom.

// matrix = 
// [
//    [ 1,4 ,7 ,11,15],
//    [ 2, 5, 8,12,19],
//    [ 3, 6, 9,16,22],
//    [10,13,14,17,24],
//    [18,21,23,26,30]
// ]


#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int y=matrix.size();
      int x=matrix[0].size();
      int i=0;
      int j=x-1;
      while(i<y&&j>=0){
         if(matrix[i][j]==target){
            return true;
         }
         else if(matrix[i][j]>target){
            j--;
         }
         else {
            i++;
         }
      }
      return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int y = matrix.size(), x = matrix[0].size();
        int i = 0, j = x - 1;
        while (i < y && j >= 0) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                j--;
            else
                i++;        
        }
        return false;
    }
};

>>>>>>> 7291062253fdb93586200b8010d4f53f5d6abd41
