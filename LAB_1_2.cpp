
#include <iostream>
#include <stdlib.h>
#include <cmath>
 
using namespace std;
 
int* func_s(int n,int r,int *a)
{
	string b[6]={"A","B","C","D","E","F"};
	string y;
	int x,flag=0;
	if (r==16)
	{
		for (int i=0;i<n;)
		{
			cin >> y;
			for (int q=0;q<6;q++)
				if (y==b[q])
				{
					x=q+10;
					flag=1;
					break;
				}
			if (flag==0) x=stoi(y);
			flag=0;
			
			for (int j=i+3;j>=i;j--)
			{
				a[j]=x%2;
				x=x/2;
			}
			i=i+4;
		}
	}
	if (r==2)
		for (int j=0;j<n;j++)
		{
			cin >> y;
			a[j]=stoi(y);
		}
		
	return a;
}
 
int main()
{
	string b[6]={"A","B","C","D","E","F"};
	string y;
	int n,p,t,r,sum_x=0,count_x=0;
	int *a;
	double sum_y=0;
	cout << "Введите кол-во бит:"; cin >> n;
	a = new int [n];
	if(n==32) {p=8;t=127;}
	else if(n==64) {p=11;t=1023;}
	else if(n==128) {p=15; t=16383;}
	cout << "Введите систему счисления:";
	cin >> r;
	
	cout << "Введите число:" << endl;
		
	func_s(n,r,a);
	for (int j=0;j<n;j++)
			cout << a[j] << " ";
		
	cout << endl;
	
	for (int i=p;i>=1;i--)
		if(a[i]==1)
			sum_x+=pow(2,abs(i-8));
	
	if (sum_x>t) 
	{
		count_x=sum_x-t;
		sum_x=pow(2,count_x);
		count_x+=p;
		for (int i=count_x;i>=p+1;i--)
			if(a[i]==1)
				sum_x+=pow(2,abs(i-15));
		cout << endl;
		
		for (int i=count_x+1;i<n;i++)
			if(a[i]==1)
				sum_y+=(1/(pow(2,abs(i-15))));
			
		if(a[0]==1) cout << (-1)*(sum_x+sum_y) << endl;
		else  cout << sum_x+sum_y << endl;
	}
	
	else 
	{
		count_x=t-sum_x;
		sum_y=1/(pow(2,count_x));
		for (int i=p+1;i<n;i++)
		{
			if(a[i]==1)
				sum_y+=(1/(pow(2,count_x+1)));
			count_x++;
		}
		if(a[0]==1) cout << (-1)*sum_y << endl;
		else  cout << sum_y << endl;
	}
	return 0;
}

