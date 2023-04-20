// https://leetcode.com/problems/reverse-words-in-a-string/description/

class Solution {
public:
    string reverseWords(string s) {
        vector<string> buff;
        string temp="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                if(!temp.empty())
                    buff.push_back(temp);
                temp="";
            }else{
                temp.push_back(s[i]);
            }
        }
        if(temp.length()!=0){
            buff.push_back(temp);
        }
        reverse(buff.begin(),buff.end());
        string ans;
        for(int i =0; i<buff.size();i++){
            ans+= (buff[i]);
            if(i+1!=buff.size())
                ans+=' ';
        }
        return ans;
    }
};