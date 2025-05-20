#include<iostream> 
#include<vector> 
#include<unordered_map> 
#include<climits> 
#include<algorithm> 

using namespace std; 

class Solution{
public: 
      string minWindow(string& s, string& t){
        int m = s.size(); 
        int n = t.size(); 
        if(n>m) return ""; 
        unordered_map<char, int> dictT , window; 
        int left = 0; 
        int right = 0; 
        int minLen= INT_MAX; 
        int start = 0; 
        int valid = 0; 
        
        for( char c:t) dictT[c]++; 
        while(right<m){
          char c = s[right]; 
          right++; 
          if(dictT.count(c)){
            window[c]++;
            if(window[c]==dictT[c]) valid++; 
          }  
          while(valid == dictT.size()){
            
            if(minLen> right-left){
              minLen = right-left; 
              start = left; 
            }
            char d = s[left]; 
            ++left; 
            if(dictT.count(d)){
              if(dictT[d]==window[d]) --valid; 
              --window[d]; 
            }
          }
        }
        return minLen==INT_MAX ? "" : s.substr(start, minLen); 
        
      }
};
int main(){
  string s = "ADOBECODEBANC"; 
  string t = "ABC"; 
  Solution sol; 
  string ans = sol.minWindow(s,t); 
  cout << ans << endl; 
  return 0; 

}
