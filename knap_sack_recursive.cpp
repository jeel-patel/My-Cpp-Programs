#include<iostream>

int knap_sack(int *, int *, int, int,int=0, int=0);

int main()
{
    int number_of_obj;
    std::cout << "Enter the number of objects to be added :- ";
    std::cin >> number_of_obj;

    int arr[number_of_obj];

    for(int i=0; i<number_of_obj; i++)
    {
        std::cout << "Enter the " << i+1 << " element's weight :- ";
        std::cin >> arr[i];
    }

    int prices[number_of_obj];

    for(int i=0; i<number_of_obj; i++)
    {
        std::cout << "Enter the " << i+1 << " th object profit :- ";
        std::cin >> prices[i];
    }

    int weight_of_bag;
    std::cout << "Enter the weight of the bag :- ";
    std::cin >> weight_of_bag;


    std::cout << knap_sack(arr, prices, number_of_obj, weight_of_bag);
}

int knap_sack(int *weight, int *price, int n,int weight_of_bag,int current_weight, int ans)
{
    static int i=0;

    if( (current_weight+(*(weight+i)))<=weight_of_bag )
    {

    }
}
