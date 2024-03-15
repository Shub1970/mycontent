<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;

// dijsktra algo.
class Graph
{
   int vertex;
   vector<vector<pair<int, int>>> Edge;
   vector<int> answer;
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queu;

public:
   Graph(int v) : vertex(v)
   {
      Edge.resize(vertex);
      answer.resize(vertex, INF);
   }
   void addEdge(int initial, int final, int weight)
   {
      Edge[initial].push_back({weight, final});
      Edge[final].push_back({weight, initial});
   }
   void shortestPath(int initial_point, int initial_point_weight = 0)
   {
      int initial_weight = initial_point_weight;
      queu.push({0, initial_point});
      answer[initial_point] = initial_weight;

      while (!queu.empty())
      {
         int min_weight = queu.top().first;
         int current_point = queu.top().second;
         queu.pop();

         for (auto final_node : Edge[current_point])
         {
            if (final_node.first + min_weight < answer[final_node.second])
            {
               answer[final_node.second] = final_node.first + min_weight;
               queu.push({answer[final_node.second], final_node.second});
            }
         }
      }
      for (auto x : answer)
      {
         cout << x << " ";
      }
   }
};

int main()
{
   // create the graph given in above figure
   int V = 9;
   Graph g(V);

   // making above shown graph
   g.addEdge(0, 1, 4);
   g.addEdge(0, 7, 8);
   g.addEdge(1, 2, 8);
   g.addEdge(1, 7, 11);
   g.addEdge(2, 3, 7);
   g.addEdge(2, 8, 2);
   g.addEdge(2, 5, 4);
   g.addEdge(3, 4, 9);
   g.addEdge(3, 5, 14);
   g.addEdge(4, 5, 10);
   g.addEdge(5, 6, 2);
   g.addEdge(6, 7, 1);
   g.addEdge(6, 8, 6);
   g.addEdge(7, 8, 7);

   // Function call
   g.shortestPath(0);

   return 0;
}
=======
// Given a string s, find the length of the longest 
// substring
//  without repeating characters.

#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//       int max_len = 0;
//       for(int i=0;i<s.length();i++){
//           unordered_set<char> st;
//           for(int j=i;j<s.length();j++){
//             if(st.find(s[j])!=st.end()){
//                max_len = max(max_len,j-i);
//                break;
//             }
//             st.insert(s[j]);
//           }
//       }
//       return max_len;
//     }
// };

//sliding window 

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//       int max_len = 0;
//       int initial=0;
//       int final=0;
//       unordered_set<char> st;
//       for(final;final<s.length();final++){
//         if(st.find(s[final])!=st.end()){
//           while(initial<final && st.find(s[final])!=st.end()){
//             st.erase(s[initial]);
//             initial++;
//           }
//         }
//         st.insert(s[final]);
//         max_len = max(max_len,final-initial+1);
//       }
//       return max_len;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int max_len=0;
      int initial=0;
      int final=0;
      int len=0;
      unordered_map<char,int> mp;
      while(final<s.length()){
        if(mp.find(s[final])!=mp.end()){
          initial=max(initial,mp[s[final]]+1);
        }
        mp[s[final]]=final;
        len=max(len,final-initial+1);
        final++;
      }
      return len;
    }
};


int main() {
  string str = "takeaUforward";
  Solution obj;
  cout << "The length of the longest substring without repeating characters is " << 
  obj.lengthOfLongestSubstring(str);
  return 0;
}
>>>>>>> 7291062253fdb93586200b8010d4f53f5d6abd41
