//Algorithm for the inversion of the array elements without using a support array
#include <stdio.h>
#include <stdlib.h>

int main () 
{
int n; //size of A array
int i;
printf("Please write here the array size \n");
scanf("%d", &n); //determines the array size

printf("The dimension of the array is %d\n", n);
int a[n]; //array declaration

if (n == 0)
	printf("An empty array has not elements. We can not reverse an empty array\n");
else 
{

printf("Please type the %d elements one by one and push ENTER\n", n);

for (i=0; i<n; i++)
scanf("%d", &a[i]);

if (n==1)
	printf("The reversed array is %d\n", a[0]);
else
{

//array filled
printf("Loading... \n");
ReverseSort (a, n);

printf("Loading... \n");
for (i=0; i<n; i++)
printf("%d ", a[i]);
printf("\n");

return 0;
}
}
}

int ReverseSort (int a[], int n)
{
	int i, j, tmp=0;
	j=n-1; //right limit
	
		for (i=0; i<n; i++)
		{
			if (j>i)
			{
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
			//swapping left value with right value
		j--;
		}

		return a[n];
}
