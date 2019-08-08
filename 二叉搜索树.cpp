#include<iostream>
using namespace std;
#include<vector>
bool VerifySquenceOfBST(vector<int> s) {
        int len=s.size();
        // cout<<"len:"<<len;
        if(len==0)
            return false;
        int i=0;
        int root=s[len-1];
        for(i=0;i<len-1;i++)
        {
            cout<<"s[i]"<<s[i];
            if (s[i]>s[len-1])
            {
               
                break; 
            }        
        }
        int j=i;
        for(j=i;j<len-1;j++)
        {  cout<<"s[j]"<<s[j];
            if(s[j]<s[len-1])
                return false;
        }
        bool left=true;
        bool right=true;
        //初始值必须为true
        if (i>0)
        {    
            vector <int> s2 (s.begin(),s.begin()+i);
            cout<<"left";
            left=VerifySquenceOfBST(s2);
        }
        if(i<len-1)
        {
            
            vector <int>s3 (s.begin()+i,s.begin()+len-1);
            
            right=VerifySquenceOfBST(s3);
        }
        return (left&&right);
            
    }
int main ()
{
   
    vector<int> v={4,8,6,12,16,14,10};
    // vector <int> v2 (v.begin(),v.begin()+2);
    // // for(int i =0;i<v2.size();i++)
    // //     cout<<v2[i];
    cout<<VerifySquenceOfBST(v);
    return 0;
}