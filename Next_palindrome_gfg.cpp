#include<iostream>
#include<vector>
using namespace std;

int AreAll9s( int num[], int n ) 
{  
    for( int i = 0; i < n; i++ ) 
        if( num[i] != 9 ) 
            return 0; 
    return 1; 
} 

void generatePalindromeUtil(int num[], int n)
{
	int mid = n/2;

	bool leftsmaller = false;

	int i = mid - 1;
	int j = (n%2) ? mid + 1 : mid;

	while(i >= 0 && num[i] == num[j])
		i--, j++;
	
	if(i < 0 || num[i] < num[j])
		leftsmaller = true;

	while( i >= 0 )
	{
		num[j] = num[i];
		i--, j++;
	}

	if (leftsmaller)
	{
		int carry = 1;

		if(n%2)			// odd digits, mid
		{
			num[mid] += carry;
			carry = num[mid]/10;
			num[mid] %= 10;
			j = mid + 1;
		}
		else
			j = mid;

		i = mid - 1;
		// propagating the carry from rightmost digit of left side
		// and copying the mirror of the same
		while( i >= 0)
		{
			num[i] += carry;
			carry = num[i]/10;
			num[i] %= 10;
			num[j++] = num[i--]; 
		}
	}
}

void generatePalindrome(int num[], int n)
{
	if ( AreAll9s(num, n) )
	{
		cout<<"1";
		for(int i = 1; i<n ; i++ )
			cout<<"0";
		cout<<"1" << endl;
	}
	else
	{
		generatePalindromeUtil(num, n);
		// print the number array
		for(int i = 0; i<n; i++)
			cout << num[i];
		cout<<endl;
	}
}

void printNum(int num[], int len)
{
	for (int i = 0; i < len; i++)
		cout<<num[i];
	cout<<endl;
}

int removeInitialZeros(int num[], int n)
{
	int count = 0;
	while(!num[count++]);
	--count;

	for(int i = 0; i < n - count ; i++)
	{
		num[i] = num[i+count];
	}
	return n-count;
}

int getlength(char num[])
{
	int length = 0;
	for ( int i = 0; num[i] != '\0'; i++)
		length++;
	return length;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int len;
		char snum[10000];
		cin >> snum;
		len = getlength(snum);

		int num[len];
		for (int i = 0; i < len; i++)
			num[i] = snum[i] - 48;

		len = removeInitialZeros(num, len);
		generatePalindrome(num, len);
	}
}
