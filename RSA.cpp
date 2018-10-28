#include<iostream>
using namespace std;
#include<cmath>
#include<math.h>
int mod(int a,int b,int n)
{
	

	int a1,p=1;
	
	for(int i=0;i<b;i++)
	{
		p=p*a;
		p=p%n;
	}
	return p;

}
int gcd(int a, int h) 
{ 
    int temp; 
    while (1) 
    { 
        temp = a%h; 
        if (temp == 0) 
          return h; 
        a = h; 
        h = temp; 
    } 
} 
int main()
{
	int p,q,n,fi,e,d_;
	int a[10],b[10],d[10],k[10];
	int plain,cipher;
	int i;
	cout<<"enter p and q"<<endl;
	cin>>p>>q;
	e=2;

	n=p*q;

	fi=(p-1)*(q-1);
			//take e where e is not divided by fi or any number who divisible of fi in short take prime number which is not equal to p and q
				//next step find d where d has to be d*e mod fi=1
				// so here is one formula ax+by=gcd(a,b) so here a=fi,b=e
				//and if we get value of y then it will be our d


	while (e < fi) 
    { 
        // e must be co-prime to phi and 
        // smaller than phi. 
        if (gcd(e, fi)==1 && e!=p && e!=q) 
            break;  
        else
            e++; 
    } 

    cout<<e;
	a[0]=1;b[0]=0;d[0]=fi;k[0]=0; 
	a[1]=0;b[1]=1;d[1]=e;k[1]=d[0]/d[1];
	//cout<<k[1];

	i=2;
	cout<<"eucladian theorem"<<endl;
	while(1)
	{
		a[i]=a[i-2]-(a[i-1]*k[i-1]);
		b[i]=b[i-2]-(b[i-1]*k[i-1]);
		d[i]=d[i-2]-(d[i-1]*k[i-1]);
		k[i]=d[i-1]/d[i];

		cout<<a[i]<<"\t"<<b[i]<<"\t"<<d[i]<<"\t"<<k[i]<<endl;
		if(d[i]==1)
			break;
		i++;
	}

	d_=b[i];
	//cout<<d_;
	if(d_>fi)
	{
		d_=d_%fi;
	}
	else if(d_<0)
	{
		d_=d_+fi;
	}

	cout<<"here is our calculated d"<<endl;
	cout<<d_<<endl;

	cout<<"enter plain integer"<<endl;
	cin>>plain;
	//cout<<n;
	//cout<<pow(plain,e);
	cipher=mod(plain,e,n);
	cout<<"after encryption"<<endl;
	cout<<cipher<<endl;
	cout<<"after decryption"<<endl;
	//plain=(cipher^d_)%n;
	plain=mod(cipher,d_,n);
	cout<<plain<<endl;

	return 0;
}
