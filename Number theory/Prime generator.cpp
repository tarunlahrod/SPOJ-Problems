/*
Problem: 
Peter wants to generate some prime numbers for his cryptosystem. 
Help him! Your task is to generate all prime numbers between two given numbers!

Input:
The input begins with the number t of test cases in a single line (t<=10). 
In each of the next t lines there are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.

Output:
For every test case print all prime numbers p such that m <= p <= n, one number per line, test cases separated by an empty line.

------------------------------------------------------------------------------------------------------------------------------------
Example:
Input:
2
1 10
3 5

Output:
2
3
5
7

3
5
------------------------------------------------------------------------------------------------------------------------------------
*/


#include <iostream>
#include <math.h>
using namespace std;

bool checkprime(int n)		//	function to if a number 'n' is prime or not.
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
	int range = b-a;	//	range is the range of the boolean array to be declared
    bool arr[range];		/*	initializing a boolean array which store whether the element at that index
					is prime or not.	*/
    for(int i=0;i<range;i++)
        arr[i]=true;		//	assuming that all the numbers are prime initially.
    for(int i=0;i<range;i++)
        if(checkprime(a+i))	//	checking for prime-ness of each number from 'a' to 'a+i' i.e. a+b-a, i.e. b.
            cout<<a+i<<endl;
}

int main() {
	int t;
	cin>>t;		// 't' test cases
	while(t--)	
    {
        int a,b;	// two numbers
        cin>>a>>b;
        fun(a,b+1);	//	here in function call, it is b+1 because 'range = b-a+1'.
			//	so for ease of calculation, we put +1 here in the call statement.
        cout<<endl;
    }
}
