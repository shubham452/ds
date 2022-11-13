#include<bits/stdc++.h>
using namespace std;
struct interval
{
    int start,end;
};
bool sortinterval(interval i1, interval i2)
{
    return (i1.start<i2.start);
}
int main()
{
    interval ar[]={{1,3},{2,4},{6,8},{9,10}};
    int n,i;
    n=sizeof(ar)/sizeof(int);
    n=n/2;
   //cout<<n;
    stack<interval> st;
    sort(ar,ar+n,sortinterval);
    st.push(ar[0]);
    for(i=1;i<n;i++)
    {
       // cout<<i<<endl;
        interval k=st.top();
        if(ar[i].start>k.end)
        {
            st.push(ar[i]);
           // cout<<k.start<<"  "<<k.end<<endl;
        }
        else if(k.end>ar[i].start)
        {
            k.end=ar[i].end;
            st.pop();
            st.push(k);
         //   cout<<k.start<<"  "<<k.end<<endl;
        }
    }
    while(!st.empty())
    {
        interval h=st.top();
        cout<<h.start<<"  "<<h.end<<endl;
        st.pop();
    }

    return 0;
}