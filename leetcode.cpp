#include<iostream>
#include<vector>

void print_vector(std::vector<int> &);

int main()
{
    int n;
    std::cout << "Enter the number :- ";
    std::cin >> n;

    std::cout << "You have entered number " << n;

    std::vector<int> vec;

    int tem;
    for(int i=0; i<n; i++)
    {

        std::cout << "\nEnter the number to be entered :- ";
        std::cin >> tem;
        vec.insert(vec.begin()+i,tem);
    }

    print_vector(vec);
}

void print_vector(std::vector<int> &v)
{
    for(int i=0; i<v.size(); i++)
    {
        std::cout << v[i] <<" ";
    }
}
