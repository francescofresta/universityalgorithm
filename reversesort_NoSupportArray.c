//Algorithm for the inversion of the array elements using a support array

#include <stdio.h>
#include <stdlib.h>

int main() 
{
int n; //size of A array
printf("Please write here the array size: \n");
scanf("%d", &n); //determines the array size

printf("The dimension of the array is %d\n", n);
int a[n]; //array declaration
printf("Please type the %d elements one by one and push ENTER\n", n);
int i;
for (i=0; i<n; i++)
scanf("%d", &a[i]);
//array filled
printf("Loading... \n\n");
ReverseSort (a, n);

printf("Loading... \n\n");
printf("The array is reversed \n");
for (i=0; i<n; i++)
printf("%d ", a[i]);
printf("\n");

return 0;
}

int ReverseSort (int a[], int n)
{
	int i, j, m;
	m=n; //array b[] dimension should be equal to array a[] dimension 

	int b[m]; //b[m] is a static support array of the same size of array a[]

	for (i=0; i<m; i++)
		b[i]=a[i]; //copy the elements of a into b

	//b[] and a[] now have the same length and same elements
	//copy again the elements in a[] inverting them

	j=n-1;
	for (i=0; i<n; i++)
	{
		a[i]=b[j];
		j--;
	}

	return a[n];
}
