#include <iostream>
#include <vector>
using namespace std;
const int N=40;
inline void sum(int &p,int n, vector<int> &d)
{       
	
	for(int i=0;i<n;++i)
		p+=d[i];
}
int main()
{
	int accum=0;
	vector<int>data(N);
	for(int i=0;i<N;i++)
	{
		data[i]=i;
	}
	sum(accum,N,data);
	cout<<"sum is "<<accum<<endl;
}


	
	

