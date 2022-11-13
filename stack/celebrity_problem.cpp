#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    bool c[4][4]={{0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0},
                    {0, 0, 1, 0}};
    stack<int> st;
    for(int i=0;i<4;i++)
    {
        st.push(i);
        while(st.size()>1)
        {
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            if(c[b][a]==1 && c[a][b]==0)
            {
                st.push(a);
            }
            if(c[a][b]==1 && c[b][a]==0)
            {
                st.push(b);
            }
        }
    }
    cout<<st.top();
    return 0;
    
}