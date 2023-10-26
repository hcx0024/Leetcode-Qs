#include <iostream>
#include <string>
#include<queue>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<deque>
using namespace std;

/*TAKE AWAY
    1. string can be traversed by s[i]
    2. string size = s.length
    */
   
class Solution {
public:
    int romanToInt(string s) {
        //loop through string, string[i] works
        //s.length() returns string length
        //PROBLEM HERE is that there are 6 cases where substraction is used
        //IV = 5 - 1
        //IX = 10 -1
        //XL = 40 || XC = 90
        //CD = 400 || CM = 900
        int total = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'I'){
                if(s[i+1] == 'V'){
                    total += 4;
                    i++;
                }else if(s[i+1] == 'X'){
                    total += 9;
                    i++;
                }else{
                    total = total + 1;
                }
                
            }else if(s[i] == 'V'){
                total = total + 5;
            }else if(s[i] == 'X'){
                if(s[i+1] == 'L'){
                    total += 40;
                    i++;
                }else if(s[i+1] == 'C'){
                    total += 90;
                    i++;
                }else{
                    total = total + 10;
                }
            }else if(s[i] == 'L'){
                total = total + 50;
            }else if(s[i] == 'C'){
                 if(s[i+1] == 'D'){
                    total += 400;
                    i++;
                }else if(s[i+1] == 'M'){
                    total += 900;
                    i++;
                }else{
                    total = total + 100;
                }
               
            }else if(s[i] == 'D'){
                total = total + 500;
            }else{
                total = total + 1000;
            }
        }

        return total;
    }
};