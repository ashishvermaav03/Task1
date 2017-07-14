/*Dynamic programming  problem which when carefully observed reduces to fibonacci
  so the final code is to find the fibonacci of (n+2)*/
#include<stdio.h>
#include<math.h>
long long int mod;
long long int fibo(long long int n)
{
	long long int k;
	long long int x;
	if (n == 0)
	{
		return 0;
	}
	if(n == 1 || n == 2)
	{
		return 1;
	}
	k=(n & 1)? (n+1)/2 : n/2;
	long long int y=fibo(k);
	long long int z=fibo(k-1);
	y=y%mod;
	z=z%mod;
	x = (n & 1)? ((y*y)%mod+(z*z)%mod)%mod
		: (((2*z)%mod + (y)%mod)%mod*y)%mod;
	return x;
}

int main()
{
	int test;
	mod=pow(10,9)+7;
	scanf("%d",&test);
	while(test--)
	{
		long long int num;
		scanf("%lld",&num);
		printf("%lld\n",fibo(num+2));
	}
	return 0;
}
