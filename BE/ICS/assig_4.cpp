#include<iostream>
#include<math.h>
using namespace std;

long int power(long int a,long int b,long int p);

int main()
{
long int P,Q,a,b,k1,k2,ka,kb;

cout<<"\nEnter public key P:";
cin>>P;

cout<<"\nEnter public key G:";
cin>>Q;

cout<<"\nEnter private key for A:";
cin>>a;

cout<<"\nEnter private key for B:";
cin>>b;

k1=power(Q,a,P);		
k2=power(Q,b,P);

cout<<"\nk1:"<<k1;
cout<<"\nk2:"<<k2;

ka=power(k2,a,P);				
kb=power(k1,b,P);

cout<<"\nSecret key for A:"<<ka;
cout<<"\nSecret key for B:"<<kb;
cout<<"\n";
if(ka==kb)
{cout<<"Proceed\n";
}else cout<<"\nCommunication rejected";
return 0;
}




long int power(long int a,long int b,long int p)
{
if(b==1)
return a;
 
else
return (((long int)pow(a, b)) % p);

}

/* Output:
106@comp6:~/Desktop$ g++ dhellman.cpp
a106@comp6:~/Desktop$ ./a.out

Enter public key P:23

Enter public key G:9

Enter private key for A:4

Enter private key for B:3

k1:6
k2:16
Secret key for A:9
Secret key for B:9
Proceed
*/
