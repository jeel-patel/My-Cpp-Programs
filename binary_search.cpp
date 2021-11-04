#include<iostream>
#include<algorithm>
#include<time.h>

int main()
{
    int n, b;
    std::cout << "Enter the number of elements you want in the array :- ";
    std::cin >> n;

    std::cout << "Enter from which numbers must be less :- ";
    std::cin >> b;

    int arr[n];
    srand(time(NULL));
    for(int i=0; i<n; i++)
    {
//        std::cout << "Enter the " << i+1 << " element :- ";
//        std::cin >> arr[i];
        arr[i] = rand()%b;
    }

    std::sort(arr,arr+n);

    int search_number;
    std::cout << "Enter the number to be searched :- ";
    std::cin >> search_number;

    int start = 0;
    int end = n-1;
    bool flag=0;

    for( ;start <= end ; )
    {
        if( arr[(end-start)/2 +start] == search_number )
        {
            flag = 1;
            break;
        }
        else if( arr[(end-start)/2 +start] < search_number )
        {
            start = start + (end-start)/2 +1;
        }
        else{
            end = start + (end-start)/2-1;
        }
    }
    if (flag == 0)
        std::cout << "NUMBER NOT FOUND";
    else std::cout << "NUMBER FOUND";

}