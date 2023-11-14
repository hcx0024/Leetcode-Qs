#include <iostream>
#include <string>
#include<queue>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<deque>
#include<stack>
#include<algorithm>
#include<math.h>
using namespace std;


/*
Given a matrix(2d) that has integers [0,1] Where 0 represents water and 1 represents land. I would like you to find the number of islands that exist within this matrix

Assumptions:
           The "invisible" perimiter is water
           for now lets say NSEW are connections, diagnols are not
           
                
[0,0,0,0,1,0,0],
[0,1,0,0,1,0,0],
[0,0,0,0,1,0,0],
[0,1,0,0,0,1,0],
[0,1,1,0,1,0,0]

    [1,1,1]
    [1,1,1]
    [1,1,1]
    
    [0,  100,  0]  NSWE
    [100,100,100]
    [0,  100,  0] 
queue: [ ]
Output = 5


please write a function that returns an integer and takes in a 2d array as input for the number of islands
*/

int findIslands(std::vector<std::vector<int>>& Map){
  //function will return the number of island we found on the map
  int countIsland = 0;
  for(int i = 0; i < Map.size(); i++){
    std::vector<int> currVec = Map[i];
    for(int j = 0; j < currVec.size(); j++){
      if(Map[i][j] == 1){//find 1 check NSEW
        std::queue<std::vector<int>> q;
        //if i-1/+1 out of the grid
        std::vector<int> loc = {i,j};
        q.push(loc);
         while(!q.empty()){
           Map[q.front()[0]][q.front()[1]] = 100;
           int x = q.front()[0];
           int y = q.front()[1];
           q.pop();
          if(Map[x-1][y] == 1){//N
            std::vector<int> loc;
            loc.push_back(i-1);
            loc.push_back(j);
            q.push(loc);
          }
          if(Map[x+1][y] == 1){//S
            std::vector<int> loc;
            loc.push_back(i+1);
            loc.push_back(j);
            q.push(loc);
          }
          if(Map[x][y-1] == 1){//W
            std::vector<int> loc;
            loc.push_back(i);
            loc.push_back(j-1);
            q.push(loc);
          }
          if(Map[x][y+1] == 1){//E
            std::vector<int> loc;
            loc.push_back(i);
            loc.push_back(j+1);
            q.push(loc);
          }
        }
        countIsland++;
        
        
       
        
      }
    }
  }
  //find 1 check NSEW 
    //case 1: island with no connection
      //turn 1 into 100 indicating we have checked this point
    //case 2: move to next 1s check untill we found one surrounded by water
      //mark curr to 100, move to next 1, 
      //special case: if we have island 
  return countIsland;
}
int main() {
  std::cout << "Hello world" << std::endl;
  return 0;
}