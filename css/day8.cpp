<<<<<<< HEAD
// Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?

// You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.

// For Example
// If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
   vector<vector<int>> points;
   vector<vector<int>> memory;

public:
   Solution(vector<vector<int>> &po) : points(po)
   {
      memory.resize(points.size(), vector<int>(4, -1));
   }
   int max_points(int days, int last_activities)
   {
      if (days == 0)
      {
         int max_ = 0;
         for (int x = 0; x < 3; x++)
         {
            if (x != last_activities)
            {
               max_ = max(max_, points[0][x]);
            }
         }
         return memory[days][last_activities] = max_;
      }
      if (memory[days][last_activities] != -1)
      {
         return memory[days][last_activities];
      }
      int maxx = 0;
      for (int x = 0; x < 3; x++)
      {
         if (x != last_activities)
         {
            int temp_max = points[days][x] + max_points(days - 1, x);
            maxx = max(maxx, temp_max);
         }
      }
      return memory[days][last_activities] = maxx;
   }
};

int ninjaTraining(int days, vector<vector<int>> points)
{
   Solution obj(points);
   return obj.max_points(days - 1, 3);
}
=======
// A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

// Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

// You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

// You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
      int x=mat[0].size();
      int y=mat.size();
      int i=0;
      int j=0;
      vector<int>colum_move={-1,0,1,0};
      vector<int>row_move={0,1,0,-1};
    }
};
>>>>>>> 7291062253fdb93586200b8010d4f53f5d6abd41
