#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
#include<time.h>
clock_t begin, end;
double time_;


void merge(long long dup[], long long lw, long long mid1,  
           long long mid2, long long h, long long arr[])  
{  
    long long i = lw, j = mid1, k = mid2, l = lw;  
  
    while ((i < mid1) && (j < mid2) && (k < h))  
    {  
        if(dup[i] < dup[j]) 
        { 
            if(dup[i] < dup[k]) 
            { 
                arr[l++] = dup[i++]; 
            } 
            else
            { 
                arr[l++] = dup[k++]; 
            } 
        } 
        else
        { 
            if(dup[j] < dup[k]) 
            { 
                arr[l++] = dup[j++]; 
            } 
            else
            { 
                arr[l++] = dup[k++]; 
            } 
        } 
    }  
  
    
    while ((i < mid1) && (j < mid2))  
    {  
        if(dup[i] < dup[j]) 
        { 
            arr[l++] =dup[i++]; 
        } 
        else
        { 
            arr[l++] = dup[j++]; 
        } 
    }  
  
    
    while ((j < mid2) && (k < h))  
    {  
        if(dup[j] < dup[k]) 
        { 
            arr[l++] =dup[j++]; 
        } 
        else
        { 
            arr[l++] = dup[k++]; 
        }  
    }  
  
     
    while ((i < mid1) && (k < h))  
    {  
        if(dup[i] < dup[k]) 
        { 
            arr[l++] = dup[i++]; 
        } 
        else
        { 
            arr[l++] = dup[k++]; 
        }  
    }  
  
    while (i < mid1)  
        arr[l++] = dup[i++];  
  
    while (j < mid2)  
        arr[l++] = dup[j++];  
  
    while (k < h)  
        arr[l++] = dup[k++];  
}  
  
void merge_sort_func(long long dup[], long long l, 
                      long long h, long long arr[])  
{  
    if (h - l < 2)  
        return;  
  
    long long mid1 = l + ((h - l) / 3);  	//1/3 part
    long long mid2 = l + 2 * ((h - l) / 3) + 1; 
  
    merge_sort_func(arr,l,mid1,dup)  ;
    merge_sort_func(arr,mid1,mid2,dup) ; 
    merge_sort_func(arr,mid2,h,dup)  ;
  
    merge(arr, l, mid1, mid2, h, dup);  
} 
  
void merge_sort(long long arr[], long long n)  
{  
    if (n == 0)  
        return;  
  
    long long *dup=(long long*)malloc(n*((long long)sizeof(long long))); 
	long long i; 
    for (i = 0; i < n; i++)  
        dup[i] = arr[i];  
  
    merge_sort_func(dup, 0, n, arr);  
  

    for (i = 0; i < n; i++)  
        arr[i] = dup[i];  
    free(dup);
}




void mergeD(long long dup[], long long lw, long long mid1,  
           long long mid2, long long h, long long arr[])  
{  
    long long i = lw, j = mid1, k = mid2, l = lw;  
  
    while ((i < mid1) && (j < mid2) && (k < h))  
    {  
        if(dup[i] > dup[j]) 
        { 
            if(dup[i] > dup[k]) 
            { 
                arr[l++] = dup[i++]; 
            } 
            else
            { 
                arr[l++] = dup[k++]; 
            } 
        } 
        else
        { 
            if(dup[j] > dup[k]) 
            { 
                arr[l++] = dup[j++]; 
            } 
            else
            { 
                arr[l++] = dup[k++]; 
            } 
        } 
    }  
  
    
    while ((i < mid1) && (j < mid2))  
    {  
        if(dup[i] > dup[j]) 
        { 
            arr[l++] =dup[i++]; 
        } 
        else
        { 
            arr[l++] = dup[j++]; 
        } 
    }  
  
    
    while ((j < mid2) && (k < h))  
    {  
        if(dup[j] > dup[k]) 
        { 
            arr[l++] =dup[j++]; 
        } 
        else
        { 
            arr[l++] = dup[k++]; 
        }  
    }  
  
     
    while ((i < mid1) && (k < h))  
    {  
        if(dup[i] > dup[k]) 
        { 
            arr[l++] = dup[i++]; 
        } 
        else
        { 
            arr[l++] = dup[k++]; 
        }  
    }  
  
    while (i < mid1)  
        arr[l++] = dup[i++];  
  
    while (j < mid2)  
        arr[l++] = dup[j++];  
  
    while (k < h)  
        arr[l++] = dup[k++];  
}  
    

  
void merge_sort_dfunc(long long dup[], long long l, 
                      long long h, long long arr[])  
{  
    if (h - l < 2)  
        return;  
  
    long long mid1 = l + ((h - l) / 3);  	//1/3 part
    long long mid2 = l + 2 * ((h - l) / 3) + 1; //2/3part 
  
    merge_sort_func(arr,l,mid1,dup)  ;
    merge_sort_func(arr,mid1,mid2,dup) ; 
    merge_sort_func(arr,mid2,h,dup)  ;
  
    mergeD(arr, l, mid1, mid2, h, dup);  
} 
  
void merge_sort_dec(long long arr[], long long n)  
{  
    if (n == 0)  
        return;  
  
    long long *dup=(long long*)malloc(n*((long long)sizeof(long long)));

  
 
	long long i; 
    for (i = 0; i < n; i++)  
        dup[i] = arr[i];  
  
    merge_sort_dfunc(dup, 0, n, arr);  
  

    for (i = 0; i < n; i++)  
        arr[i] = dup[i];  
}  
long long count(char file[])
{
	FILE *fp = fopen(file, "r");
	long long count = 0;
	char b[100];
		while(fscanf(fp, "%s\n", &b) == 1)
				count++;
	fclose(fp);
	return count;
}
  
int main()
{
	long long n;
	long long j;
	long long *arr;		//array to hold data
	int i;
	char filename[15];
	FILE *fp;
	printf("*******************TIME SUMMARY***************\n");
	for(i=0;i<10;i++)
	{
		sprintf(filename, "File %d.txt", i+1);		
		n = count(filename);
		printf("-------------------------File %d.txt-----------------------\n",i+1);
		printf("File %d has %lld elements\n",i+1,n);
		
		fp = fopen(filename, "r");
		arr=(long long*)malloc(n*((long long)sizeof(long long)));
		for(j=0; j<n; j++)
		{
			fscanf(fp, "%lld", &arr[j]);
		}
		begin= clock();
		merge_sort(arr,n-1);
		end = clock();
		fclose(fp);
		time_ = ((double)(end-begin)) / CLOCKS_PER_SEC;
		printf("AVERAGE case : %0.10lf\n", time_);
		
		sprintf(filename, "File %d_asc.txt", i+1);
		fp = fopen(filename, "r");
		for(j=0; j<n; j++)
		{
			fscanf(fp, "%lld", &arr[j]);
		}
		begin = clock();
		merge_sort(arr,n-1);
		end = clock();
		fclose(fp);
		time_= ((double)(end-begin)) / CLOCKS_PER_SEC;
		printf("Best case  : %0.10lf\n",time_);
	    	
 
		begin = clock();
		merge_sort_dec(arr,n-1);
		end = clock();
		fclose(fp);
		time_ = ((double)(end-begin)) / CLOCKS_PER_SEC;
		printf("Worst case  %0.10lf\n\n", time_);
	
		free(arr);
	}
}

