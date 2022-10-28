#include<stdio.h>
void main()
{int ar[20],n,item,flg=0,i=0,j,temp,first,last,mid;
 clrscr();
 printf("\nEnter the number of elements\n");
 scanf("%d",&n);
 printf("\nEnter the elements!\n");
 for(i=0;i<n;i++)
 {scanf("%d",&ar[i]); }
 printf("\nEnter the element to be searched for:- \n");
 scanf("%d",&item);

 for(i=0;i<n;i++)
 {for(j=0;j<(n-1)-i;j++)
  {if(ar[j]>ar[j+1])
   {temp=ar[j];
    ar[j]=ar[j+1];
    ar[j+1]=temp; }
  }}
 
 first=0;
 last=n-1;
 while(first<=last)
 {mid=(first+last)/2;
  if(item==ar[mid])
   {flg=1;
    break; }
  else if(item>ar[mid])
   {first=mid+1; }
  else
   {last=mid-1; }
 }

if(flg==1)
{printf("\n Element found!!\n"); }
else
{printf("\n Element not found!!\n"); }

}
