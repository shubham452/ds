#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,val,sum=0;
    cout<<"enter no. of inputs"<<endl;
    cin>>n;
    int ar[n],i,left[n],right[n];
    cout<<"enter the values"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
        if(i==0)
        {
            left[i]=ar[i];
        }
        else
        {
            if(left[i-1]<ar[i])
            {
                left[i]=ar[i];
            }
            else
            {
                left[i]=left[i-1];
            }    
        }   
    }
    for(i=n-1;i>=0;i--)
    {
        if(i==n-1)
        {
            right[i]=ar[i];
        }
        else
        {
            if(right[i+1]<ar[i])
            {
                right[i]=ar[i];
            }
            else
            {
                right[i]=right[i+1];
            }    
        } 
    }
    for(i=0;i<n;i++)
    {
        val=(left[i]<=right[i]?left[i]:right[i]);
        if(val>ar[i])
        {
            sum=sum+(val-ar[i]);
        }
    }
    cout<<"the value is "<<sum<<endl;
    return 0;
}