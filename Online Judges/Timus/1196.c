#include <stdio.h>
#include <stdlib.h>
void merge(int* arr, int l, int m, int r) { 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
	/* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else{ 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) { 
    if (l < r) { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
int main(){ //1196
	int n,m,i,j,count;
	count=0;
	scanf("%d",&n);
	int teacher[n];

	for(i=0;i<n;++i)
		scanf("%d",teacher+i);
	scanf("%d",&m);
    teacher[n]=1000000001;
	int student[m];
	for(i=0;i<m;++i){
		scanf("%d",student+i);
	}

	mergeSort(student,0,m-1);

	for(i=0;i<n;++i){
		for(j=0;j<m;++j){
			if(teacher[i]<student[j]){
				++i;
				--j;
			}
			else if(teacher[i]==student[j])
				++count;
		}
	}
	printf("%d",count);
	return 0;
}