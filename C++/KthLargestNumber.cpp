#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the size of array :- ";
    int n;
    cin>>n;

    cout<<"Enter the values in array :- ";
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];

    int k;
    cout<<"Enter the value of Kth position :- ";
    cin>>k;

    priority_queue<int> pq;
    for(int i=0;i<n;i++)pq.push(arr[i]);

    k-=1;
    while(k--)
    {
        pq.pop();
    }

    cout<<pq.top()<<endl;

    return 0;

}
