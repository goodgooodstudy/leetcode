/**
* @Author: lcy
* @Date:   2016-10-27T16:32:15-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//still cannot understand... 
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = 0;
        int j = 0;
        int sum = 0;
        for(int i = 0; i < sentence.size(); i++){
             if (sentence[i].size() > cols) {
                return 0;
            }
            sum += sentence[i].size()+1;
        }

        for(int i = 0; i < rows; i++){
            int location = cols+1;
            n += location/sum;
            location = location%sum;
            while(location >= sentence[j].size() +1){
                location -= sentence[j].size()+1;
                if(j+1 == sentence.size()) {
                    // cout << n<<endl;
                    n++;
                }
                j= (j+1)% sentence.size();
            }
        }
        return n;
    }

};
