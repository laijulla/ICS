#include<stdio.h>
 
 int min,max,mid;
 
 void accept(int a[20], int nn)
 {
 int i;
 printf("Enter the array elements");
 for(i=0;i<nn;i++)
 scanf("%d",&a[i]);
 }
 
 void display(int a[20], int nn)
 {
 int i;
 for(i=0; i<nn; i++)
 printf("%d\t",a[i]);
 }
 
 int minarr(int a[20],int nn)
 {
  int i;
   min=a[0];
 
  for(i=0;i<nn;i++)
  {
    if(a[i]<min)
  {
    min=a[i];
  }
  
 }
    return min;
} 
 
 
 int maxarr(int b[20],int nn)
 { 
    int i;
    max=b[0];
    
    for(i=0;i<nn;i++)
    {
     
     if(b[i]>max)
     {
     
       max=b[i];
     
     }
  }
        return max;
}
 
 int main()
 {
 
 int arr[10],size,i,ch,m,n;
 printf("Enter the size of array:");
 scanf("%d", &size);
  
 do{
      printf("\n1.Accept\n2.Display\n3.Min Element\n4.Max Element\5.Exit");
      printf("\nEnter your choice:");
      scanf("%d",&ch);
      
      switch(ch)
      {
         case 1:accept(arr,size);
         break;
         
         case 2:display(arr,size);
         break;
         
         case 3:m=minarr(arr,size);
                printf("Min element is=%d\n",m);
         break;
         
         case 4:n=maxarr(arr,size);
                printf("Max element is=%d\n",n);
         break;  
         
    }
 
 
 } while(ch!=4);
 return 0;
 }
 
  
