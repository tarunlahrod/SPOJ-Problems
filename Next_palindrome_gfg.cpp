#include<iostream>
#include<vector>
using namespace std;

void generatePalindromeUtil(int arr[], int n)
{
	int mid = n/2;

	bool leftsmaller = false;

	int i = mid - 1;
	int j = (n%2) ? mid + 1 : mid;

	while(i >= 0 && arr[i] == arr[j])
		i--, j++;
	
	if( i < 0 || num[i] < num[j])
		leftsmaller = true;

	while( i >= 0 )
	{
		num[j] = num[i];
		i--, j++;
	}

	if (leftsmaller)
	{
		int carry = 1;
		mid = n/2;
	}
}

int main()
{

}	456789