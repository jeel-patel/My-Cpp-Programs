#include<iostream>
#include<time.h>
void quick_sort(int *, int, int , int);
int partition(int *, int, int, int);

int main(){

    int n;
    std::cout << "Enter the number of elements you want :- ";
    std::cin >> n;

    int m;
    std::cout << "Enter the value to be less than :- ";
    std::cin >> m;

    int *a= (int*)malloc(sizeof(int)*n);

    std::srand(time(0));
    for(int i=0; i<n; i++){

//        std::cout << "Enter the " << (i+1) << " element :- ";
//        std::cin >> *(arr+i);
        *(a+i) = rand()%m;
    }

    quick_sort(a,0,n-1,n);

    for(int i=0; i<n; i++){

        std::cout << *(a+i) << " ";
    }
}

void quick_sort(int *ptr, int start, int end, int size){

    if( start< end ) {

        int pivot = partition(ptr, start, end, size);

        quick_sort(ptr, start, pivot - 1, size);
        quick_sort(ptr, pivot + 1, end, size);
    }
}

int partition(int * ptr, int s, int e, int size){

    int pivot = *(ptr + e);

    int i=s-1;
    int j=s;

    for( ; j<=e ; j++){

        if( *(ptr+j) <= pivot ){
            i++;

            int temp = *(ptr+i);
            *(ptr+i) = *(ptr+j);
            *(ptr+j) = temp;
        }
    }

    return i;
}