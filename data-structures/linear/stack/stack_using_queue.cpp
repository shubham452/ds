#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> q1,q2;
    int i;
    int ar[]={1,2,3,4,5};
    int n=sizeof(ar)/sizeof(int);
    for(i=0;i<n;i++)
    {
        q2.push(ar[i]);
        if(!q1.empty())
        {
            while(!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
        }
        q1.swap(q2);
    }
    while(!q1.empty())
    {
        cout<<q1.front()<<endl;
        q1.pop();
    }
    return 0;
}
