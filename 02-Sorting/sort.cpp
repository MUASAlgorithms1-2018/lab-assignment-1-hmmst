#include <iostream>
#include <string.h>
void bubble_sort(int a[], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }
}
void insertion_sort(int a[], int n)
{
    for(int i = 0; i < n; i++) {
        int j = i;
        while(j > 0 && a[j] < a[j-1]) {
            std::swap(a[j], a[j-1]);
            j--;
        }
    }
}
void selection_sort(int a[], int n)
{
    for(int i = 0; i < n; i++) {
        int min = a[i];
        int minPosition = i;
        for(int j = i; j < n; j++) {
            if(a[j] <= min) {
                min = a[j];
                minPosition = j;
            }
        }
        std::swap(a[i], a[minPosition]);
    }
}
int* merge(int a[], int aLength, int b[], int bLength) {
    //std::cout << aLength << "|" << bLength << std::endl;
    if(aLength <= 0) {
        return b;
    }
    if(bLength <= 0) {
        return a;
    }
    int* c = new int[aLength+bLength];
    if(a[0] <= b[0]) {
        memcpy(c, a, sizeof(int));
        memcpy(&(c[1]), merge(&(a[1]), aLength-1, b, bLength), sizeof(int)*(aLength+bLength-1));
    } else {
        memcpy(c, b, sizeof(int));
        memcpy(&(c[1]), merge(a, aLength, &(b[1]), bLength-1), sizeof(int)*(aLength+bLength-1));
    }
    return c;
}
int* merge_sort(int a[], int n)
{
    //std::cout << n << std::endl;
    if(n <= 1) {
        return a;
    }
    return merge(
        merge_sort(a, n/2), n/2, 
        merge_sort(&(a[n/2]), n-n/2), n-n/2);
}
// print an array with length n to standard output
void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

#include "testcases.cpp"
int main(int argc, char *argv[])
{
    if(argc <= 2) {
        std::cout << "Please specify the sort type: bubble, insertion, selection, merge" << std::endl;
        exit(1);
    }
    std::string sort_type = std::string(argv[1]);
    int n = argc - 2;
    // do not count executable name or first argument
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = atoi(argv[i + 2]);
    }
    if(n == 1 && !std::isdigit(arr[0])) {
        
        if(strcmp(argv[2], "A") == 0) {
            n = sizeof(A)/sizeof(*A);
            arr = A;
        }
        else if(strcmp(argv[2], "B") == 0) {
            n = sizeof(B)/sizeof(*B);
            arr = B;
        }
        else if(strcmp(argv[2], "C") == 0) {
            n = sizeof(C)/sizeof(*C);
            arr = C;
        }
        else if(strcmp(argv[2], "D") == 0) {
            n = sizeof(D)/sizeof(*D);
            arr = D;
        }
        else {
            std::cout << "Wrong testcase." << std::endl;
        }
    }
    std::cout << "Original list: ";
    print_array(arr, n);
    if (sort_type == "bubble")
    {
        bubble_sort(arr, n);
        std::cout << "Sorted list: ";
        print_array(arr, n);
    }
    else if (sort_type == "insertion")
    {
        insertion_sort(arr, n);
        std::cout << "Sorted list: ";
        print_array(arr, n);
    }
    else if (sort_type == "selection")
    {
        selection_sort(arr, n);
        std::cout << "Sorted list: ";
        print_array(arr, n);
    }
    else if (sort_type == "merge")
    {
        arr = merge_sort(arr, n);
        std::cout << "Sorted list: ";
        print_array(arr, n);
    }
    else
    {
        std::cout << "Sorry, " << sort_type << " sort is not implemented!" << std::endl;
        exit(1);
    }
    //delete[] arr;
    exit(0);
}