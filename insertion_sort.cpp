#include<iostream>
#include<time.h>

int main()
{
    int n;
    std::cout <<"Enter the number of elements to enter :- ";
    std::cin >> n;
    
    srand(time(0));

    int arr[n];

    for(int i=0; i<n; i++)
    {
        arr[i] = rand();
    }

    int key;

    for (int i = 1; i < n; i++)
    {
        /* code */

        key = arr[i];

        int j;
        for(j=i-1; j >= 0; j--)
        {
            if(arr[j]>key)
            {
                arr[j+1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j+1] = key;
    }

    for(int l=0; l<n; l++)
    {
        std::cout << arr[l] << " ";
    }
    
}