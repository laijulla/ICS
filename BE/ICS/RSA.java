import java.util.*;
import java.lang.*;
public class test{
	static int mod(int a,int b,int n)
{
	

	int a1,p=1;
	a1=a;
	for(int i=0;i<b;i++)
	{
		p=p*a;
		p=p%n;
	}
	return p;

}
	static int gcd(int a, int h) 
{ 
    int temp; 
    while (true) 
    { 
        temp = a%h; 
        if (temp == 0) 
          return h; 
        a = h; 
        h = temp; 
    } 
} 
	public static void main(String Args[])
	{
		Scanner sc=new Scanner(System.in);
	int p,q,n,fi,e,d_;
	int a[],b[],d[],k[];
	int plain,cipher;
	int i;

	a=new int[10];
	b=new int[10];
	d=new int[10];
	k=new int[10];
	System.out.println("enter p and q");
	p=sc.nextInt();
	q=sc.nextInt();
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
	a[0]=1;b[0]=0;d[0]=fi;k[0]=0; 
	a[1]=0;b[1]=1;d[1]=e;k[1]=d[0]/d[1];
	//cout<<k[1];

	i=2;
	System.out.println("eucladian theorem");
	while(true)
	{
		a[i]=a[i-2]-(a[i-1]*k[i-1]);
		b[i]=b[i-2]-(b[i-1]*k[i-1]);
		d[i]=d[i-2]-(d[i-1]*k[i-1]);
		k[i]=d[i-1]/d[i];

		System.out.println(a[i]+"\t"+b[i]+"\t"+d[i]+"\t"+k[i]);
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

	System.out.println("here is our calculated d");
	System.out.println(d_);

	System.out.println("enter plain integer");
	plain=sc.nextInt();
	cipher=mod(plain,e,n);
	System.out.println("after encryption");
	System.out.println(cipher);
	System.out.println("after decryption");
	plain=mod(cipher,d_,n);
	System.out.println(plain);

	}
}