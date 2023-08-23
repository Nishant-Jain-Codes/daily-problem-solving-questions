class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        if(!isValid(croakOfFrogs))
            return -1;
        int maxFrogs=0;
        int frogReq=0;
        for(int i=0;i<croakOfFrogs.length();i++){
            char curChar = croakOfFrogs[i];
            if(curChar == 'c'){
                frogReq++;
                maxFrogs = max(maxFrogs,frogReq);
            }
            else if(curChar == 'k'){
                frogReq--;
            }

        }
        return maxFrogs;
    }
private: 
    bool isValid(string str){
        int c=0,r=0,o=0,a=0,k=0;
        for(int i=0;i<str.length();i++){
            if(str[i]=='c')
                c++;
            else if(str[i]=='r')
                r++;
            else if(str[i]=='o')
                o++;
            else if(str[i]=='a')
                a++;
            else if(str[i]=='k')
                k++;
            else 
                return false;
            if(c<r || r<o || o<a || a<k)
                return false;
        }
        return c==r && r==o && o==a && a==k;
    }
};