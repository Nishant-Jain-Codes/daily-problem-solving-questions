// https://practice.geeksforgeeks.org/problems/search-in-a-matrix17201720/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=search-in-a-matrix

//User function template for C++
class Solution{
public: 
    int matSearch (vector <vector <int>> &mat, int N, int M, int X)
    {
        // your code here
        int si=0,ei=N-1;
        int targRow=-1;
        //finding lower bound of X in 1st column 
        int curCol=0;
        while(si<=ei){
            int mid = (si+(ei-si)/2);
            if(mat[mid][curCol]>X)
            {
                ei=mid-1;
            }else if(mat[mid][curCol]<X){
                //cout<<"targRowUpdate "<<targRow<<endl;
                targRow=mid;
                si=mid+1;
            }else{
                return true;//found X
            }
        }
        if(targRow==-1)
        {
            //cout<<"didnt found lower bound in col"<<endl;
            return false;

        }
        //cout<<"targRow"<<targRow<<endl;
        //applying binary search in TargRow
        si=0;
        ei=M-1;
        while(si<=ei){
            int mid = (si+(ei-si)/2);
            //cout<<"mid val "<<mat[targRow][mid]<<endl;
            if(mat[targRow][mid]>X){
                ei=mid-1;
            }else if(mat[targRow][mid]<X){
                si=mid+1;
            }
            else {
                return true;
            }
        }
        //cout<<"targRow->"<<targRow<<endl;
        if(targRow>0){
            //cout<<"ifRan";
            targRow--;
            si=0;
        ei=M-1;
            while(si<=ei){
            int mid = (si+(ei-si)/2);
            //cout<<"mid val "<<mat[targRow][mid]<<endl;
            if(mat[targRow][mid]>X){
                ei=mid-1;
            }else if(mat[targRow][mid]<X){
                si=mid+1;
            }
            else {
                return true;
            }
        }
        }
       // cout<<"didnt found lower bound in row"<<endl;
        return false; //if we got out of loop we didnt find X
    }
};