ll binomialCoeff(int n , int r)
{
	if(r > n/2)
		r = n - r;

	ll ans = 1;

	for(int i=0;i<r;i++)
	{
		ans = ans*n;
		n--;

		ans = ans/(i+1);
	}

	return ans;
}


int EulerTotient(int n)
{
	float ans = n;

	int p = 2;

	for(p ; p*p <= n;p++)
	{	if(n==3)
			cout<<"kkkk"<<endl;
			if(n%p == 0)
			{
				ans = ans*(1.0 - 1.0/(float)(p));

				while(n%p == 0)
					n = n/p;
			}
	}

	if(n > 1)
	{
		ans = ans*(1.0 - 1.0/(float)(n));
	}

	return ans;
}