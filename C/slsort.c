#include<stdio.h>
void main()
{int ar[20],n,i=0,j,temp,loc,lowest;
 
 printf("\nEnter the number of elements\n");
 scanf("%d",&n);
 printf("\nEnter the elements!\n");
 for(i=0;i<n;i++)
 {scanf("%d",&ar[i]); }

 for(i=0;i<(n-1);i++)
 {lowest=ar[i];
  loc=i;
  for(j=(i+1);j<n;j++)
  {if(lowest>ar[j])
    {lowest=ar[j];
      loc=j; }
  } temp=ar[i];
    ar[i]=ar[loc];
    ar[loc]=temp;
 }

 printf("\n Sorted elements are :-\n");
 for(i=0;i<n;i++)
 {printf("%d",ar[i]); }
}

