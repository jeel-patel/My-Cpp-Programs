#include<iostream>
#include<queue>

int main()
{
    int n,t;
    std::cout << "Enter the number of denominations :- ";
    std::cin >> n;

    std::priority_queue<int> queue;

    for(int i = 0; i < n; i++)
    {
        std::cout << "Enter the " << i+1 << " th coin denomination :- ";
        std::cin >> t;
        queue.push(t);
    }

    int change_of;

    std::cout << "Enter the amount of change :- ";
    std::cin >> change_of;

    int count = 0;

    for( ; change_of!=0; )
    {
        if(queue.empty())
        {
            count=-1;
            break;
        }

        if(queue.top()<=change_of)
        {
            count= count + change_of/queue.top();
            change_of = change_of%queue.top();
        }
        queue.pop();
        // std::cout << queue.size() << "\n";
    }

    std::cout << count;


}