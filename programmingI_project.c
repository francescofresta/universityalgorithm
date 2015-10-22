/* This is one part of the project I made for the Programming I exam of January 2015. 
The assignment says we need two arrays of integer, different in size, called A and B. 
First of all we need to sort the A array in ascending order and the other one in descending order. 
After this, you have to write two functions in order to make the union of array  A and B in another array, called C. 
The C array should be ordered once in ascending order and another in descending order.
You can sort using SelectionSort or BubbleSort, the two only algorithms explained by the Programming I teacher.
*/

#include <stdio.h>
int main()
{
	int m_index=0; //array A generic index
	int n_index=0; //array B generic index
	//ask user m ed n input
	//we determine the array size
	//the two arrays must have different size
	do {
	printf("Please write here the array A size: \n");
	scanf("%d", &m_index);
	printf("Please write here the array B size: \n");
	scanf("%d", &n_index);
	} while (m_index==n_index || (m_index < 0 || n_index < 0));
	//we have now different m and n indexes

	int a[m_index]; //array A with index declaration
	int b[n_index]; //array B with index declaration

	//print the array size
	printf("Array A size is: %d\n", m_index);
	printf("Array B size is: %d\n", n_index);

	//fill them with integer numbers
	int i;
	for (i=0;i<m_index;i++) 
	{
		printf("Please write the elements for the array A one by one and push ENTER\n");
		scanf("%d", &a[i]);
	}

	int j; //counter var
	for (j=0; j<n_index; j++)
	{
		printf("Please write the elements for the array B one by one and push ENTER\n");
		scanf("%d", &b[j]);
	}

	printf("The elements in the array A are: \n");
	for (i=0; i<m_index; i++)
		printf("%d\n", a[i]);

	printf("The elements in the array B are \n");
	for (j=0; j<n_index; j++)
		printf("%d\n", b[j]);

	//A should be sorted in descending order
	//We can use different algorithms to sort
	//I use SelectionSort and I order them both
	int min=0;
	int min_index=0;
	ascendingselectionsort(a, m_index, i, j, min, min_index);

	printf("Now the array A is in ascending order.\n");
		printf("The elements in the array A are: \n");
		for (i=0; i<m_index; i++)
		printf("Element: %d\n", a[i]);

	descendingselectionsort(b, n_index, i, j, min, min_index);

	printf("Now the array B is in descending order.\n");
	printf("The elements in the array B are: \n");
	for (i=0; i<n_index; i++)
	printf("Element: %d\n", b[i]);

	//Let's solve the two exercises
	//We need two functions which sort in ascending and descending order respectively
	ascendingarrayunion(a, m_index, b, n_index, min, min_index);
	descendingarrayunion(a, m_index, b, n_index, min, min_index);
	}

	//Pass the array A, the index and variables to the function
	int ascendingselectionsort(int a[], int m_index, int i, int j, int min, int min_index)
	{
	//SelectionSort in ascending order on the array A
		for (i=0; i<m_index-1;i++)
		{
			min=a[i];
			min_index=i;

			for (j=i+1;j<m_index; j++)
			{
				if (a[j]<min) 
				{
					min=a[j];
					min_index=j;
				}
			}
			a[min_index]=a[i];
			a[i]=min;
		}
	//array sorted
		return a[m_index];
	}

	int descendingselectionsort(int b[], int n_index, int i, int j, int min, int min_index)
	{
		//SelectionSort in descending order on the B array
		for (i=0; i<n_index-1;i++)
		{
			min=b[i];
			min_index=i;

			for (j=i+1;j<n_index; j++)
			{
				if (b[j]>min) //descending order
				{
					min=b[j];
					min_index=j;
				}
			}
			b[min_index]=b[i];
			b[i]=min;
		}
	return b[n_index];
	//Here the B array is sorted in descending order
	}
	//union is made in the C array that will be sorted in descending order
	int ascendingarrayunion (int a[], int m_index, int b[], int n_index, int min, int min_index) 
	{
	    int i=0, j=0, found, lenc=0;
	    int c[m_index]; //array for the union - index is variable
	    for(i=0;i<m_index;i++)
	    {
	        found = 0; //found is used like a bool and shows if the element
	        //is already in the C array, if so i do not insert it again 
	        
	        for(j=0; j<i && !found;j++)
	            if(a[i]==c[j]) //If the i element is equal to the j element in the c array
	                found = 1; //set found = 1
	        if(!found) 
	            c[lenc++] = a[i];
	    }

	    for(i=0;i<n_index;i++)
	    {
	        found=0;
	        for(j=0;j<lenc && !found;j++)
	        	{
	            	if(b[i]==c[j])
	            	found = 1;
	        	}
	        if(!found)
	            c[lenc++] = b[i];
	    }
		//check if every element that I would like to add in A is not already inserted in C
		//finaly add the element in C only if is not already inserted
	    
	    //SelectionSort to sort in ascending order
		
		for (i=0; i<lenc-1;i++)
		{
			min=c[i];
			min_index=i;

			for (j=i+1;j<lenc; j++)
			{
				if (c[j]<min)
				{
					min=c[j];
					min_index=j;
				}
			}
			c[min_index]=c[i];
			c[i]=min;
		}
		//now print the sorted elements
	    printf("Array A and B union gives the C array\nIt is already sorted in ascending order\n");
	   for(i=0;i<lenc;i++)
	        printf("Element %d\n",c[i]);
	    return c[lenc];
	}

	//array C union sorted in descending order
	int descendingarrayunion(int a[], int m_index, int b[], int n_index)
	{
	 int i, j;
	    int found=0;
	    int lenc=0;
	    int c[m_index];
	    for(i=0;i<m_index;i++)
	    {
	    //scan array A
	        found = 0;
	        for(j=0; j<i && !found;j++)
	            if(a[i]==c[j])
	                found = 1;
	        if(!found)
	            c[lenc++] = a[i];
	    }
	    for(i=0;i<n_index;i++)
	    {
	        found=0;
	        for(j=0;j<lenc && !found;j++)
	            if(b[i]==c[j])
	                found = 1;
	        if(!found)
	            c[lenc++] = b[i];
	    }
	    //SelectionSort in descending order
	    int min_index=0;
		int min=0;
		for (i=0; i<lenc-1;i++)
		{
			min=c[i];
			min_index=i;

			for (j=i+1;j<lenc; j++)
			{
				if (c[j]>min)
				{
					min=c[j];
					min_index=j;
				}
			}
			c[min_index]=c[i];
			c[i]=min;
		}
		//Print the C array in descending order
	    printf("Array A and array B union gives the C array\nIt is already sorted in descending order\n");
	   for(i=0;i<lenc;i++)
	        printf("Element %d\n",c[i]);
	    printf("\nDone.\n");
	    return c[lenc];
	}		
