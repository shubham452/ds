#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,k=0;
    stack<int> s1,s2;
    int ar1[]={1,2,3};
    int ar2[]={3,1,2};
    //arr1[] = [ 1, 2, 3 ] , arr2[] = [ 3, 1, 2 ]
    n=sizeof(ar1)/sizeof(int);
    for(i=0;i<n;i++)
    {
        //if(s1.empty() && i!=n)
        //{
           // cout<<i<<endl;
            s1.push(ar1[i]);
        
        //}
        if(!s1.empty() && s1.top()==ar2[k] )
        {
            while(!s1.empty() && s1.top()==ar2[k] )
            {
               // cout<<i<<i<<endl;
                s2.push(s1.top());
                s1.pop();
                k++;
            }
           // cout<<k<<endl;
        }
    }
    if(s1.empty())
    {
        cout<<"stack permutation"<<endl;
    }
    else
    {
        cout<<"not stack permutation"<<endl;
    }
    return 0;
}