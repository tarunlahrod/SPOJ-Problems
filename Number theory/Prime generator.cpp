#include <iostream>
#include <math.h>
using namespace std;

bool checkprime(int n)
{
    if(n<2)
        return false;
    for(int i=2;i<=sqrt(n);i++)
        if(n%i==0)
            return false;
    return true;
}

void fun(int a, int b)
{
    bool arr[b-a];
    for(int i=0;i<(b-a);i++)
        arr[i]=true;
    for(int i=0;i<(b-a);i++)
        if(checkprime(a+i))
            cout<<a+i<<endl;
}

int main() {
	int t;
	cin>>t;
	while(t--)
    {
        int a,b;
        cin>>a>>b;
        fun(a,b+1);
        cout<<endl;
    }
}
