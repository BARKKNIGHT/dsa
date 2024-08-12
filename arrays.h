#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    int frequency;
}node;

void print_arr(int *arr,int size){
    for(int i=0;i<size;i++){
        printf("%d->",arr[i]);
    }
    printf("NULL\n");
}
void reverse_print_arr(int *arr,int size){
    for(int i=size-1;i>-1;i--){
        printf("%d->",arr[i]);
    }
    printf("NULL\n");
}

int sum_array(int *arr,int size){
    int sum = 0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    return sum;
}

int linear_search(int *arr,int size,int element){
    for(int i=0;i<size;i++){
        if (arr[i]==element){
            return i;
        }
    }
    return -1;
}

int binary_search(int *arr,int size,int element){
    int low = 0;
    int high = size;
    while(low<high){
        int mid = (high+low)/2;
        if(arr[mid]==element){
        return mid;
        }
        else if(arr[mid]<element){
            low =mid+1;
        }
        else if(arr[mid]>element){
            high = mid;
        }
    }
    return -1;
}

int* Odd_even(int *arr,int size){
    int *odd_even = (int *)calloc(sizeof(int),2);
    for(int i=0;i<size;i++){
        if(arr[i]%2==0){
            odd_even[0] = odd_even[0]+1;
        }
        else{
            odd_even[1] = odd_even[1]+1;
        }
    }
    return odd_even;
}

// int** subarray(int *arr, int size){
//     int** subarrays = NULL;
//     int num_subarrays = (size * (size + 1)) / 2;
    
//     subarrays = (int**)malloc(num_subarrays * sizeof(int*));
//     int index = 0;
//     for(int i = 0; i < size; i++){
//         for(int j = i; j < size; j++){
//             int subarray_size = j - i + 1;
//             subarrays[index] = (int*)malloc(subarray_size * sizeof(int));
//             for(int k = i; k <= j; k++){
//                 subarrays[index][k - i] = arr[k];
//             }
//             index++;
//         }
//     }
//     return subarrays;
// }

int* subarray(int *arr,int start,int end,int size){
    if(end<size && start > -1 && end >-1){
        int *ptr = (int*)malloc(sizeof(int)*(end-start+1));
        int j = 0;
        for(int i = start;i<=end;i++){
            ptr[j] = arr[i];
            j++;
        }
        return ptr;
    }
    return NULL;
}


int valid_subset(int* arr,int size,int* subset,int size2){
    int count = 0;
    for(int i=0;i<size2;i++){
        int j = linear_search(arr,size,subset[i]);
        if(j==-1){
            return 0;
            count++;
        }
    }
    return 1;
}

int frequency(int* arr,int size,int element){
    int count = 0;
    for(int i=0;i<size;i++){
        if(arr[i]==element){
            count++;
        }
    }
    return count;
}

int* unique_elements(int* arr,int size){
    int* unique = (int*)calloc(sizeof(int),size);
    int index= 0;
    for(int i=0;i<size;i++){
        int j = frequency(unique,size,arr[i]);
        if(j==0){
            unique[index] = arr[i];
            index++;
        }
    }
    return unique;
}

node* mode(int *arr,int size){
    int max_count = -1;
    int count = -1;
    int element = 0;
    for(int i = 0;i<size;i++){
        count = frequency(arr,size,arr[i]);
        if(count>max_count){
            max_count = count;
            element = arr[i];
        }
    }
    node *ptr = (node*)malloc(sizeof(node));
    ptr -> data = element;
    ptr ->frequency = max_count;
    return ptr;
}

node* majority_element(int *arr,int size){
    node *ptr = mode(arr,size);
    if (ptr->frequency>(size/2)){
        return ptr;
    }
    else{
        ptr->frequency = 0;
        return ptr;
    }
}