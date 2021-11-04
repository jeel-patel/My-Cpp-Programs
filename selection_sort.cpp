#include<iostream>
#include<time.h>

int main()
{
    int n;
    std::cout << "Enter the number of elements to enter :- ";
    std::cin >> n;
    
    int arr[n];

    //this will generate random numbers between 0 to 32000
    srand(time(0));
    for(int i = 0; i < n;i++){

        arr[i] = rand();
    }

    int temp_max=-1, index=0;

    for(int i = 0; i < n; i++){

        for(int j = i; j <n; j++)  // loop to find the maximum number from the remaining array
        {
            if( arr[j] > temp_max)
            {
                index = j;
                temp_max = arr[j];
            }
        }

        std::swap(arr[i], arr[index]); // this will insert the maximum number with the number at current index
        temp_max =-1;
        index= -1;
    }

    for(int i = 0; i < n; i++) {

        std::cout << arr[i] << " ";
    }
}