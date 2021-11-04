#include<iostream>

class Solution
{   
private:
    bool completed;

public:
    int *arr;
    int size;
    int current_index;
    Solution(int n)
    {
        completed = false;
        size = n;
        arr = new int[size];

        for(int i = 0; i < size; i++)
        {
            *(arr+i) = -1;
        }
    }

    void find_ans(int current_level)
    {   
        // std::cout << current_level << "\n";
        for(int i = 0; i < size; i++)
        {
            if(completed){break; }

            current_index = current_level;
            arr[current_level] = i;


            if(!validity_checker())
            {
                if(completed){break;}

                arr[current_level] = -1;
                continue;
            }

            find_ans(current_level+1);

            if(completed){return; }

            arr[current_level] = -1;
        }
    }

private:
    bool validity_checker()
    {

        bool return_flag = false;


        // to check if nothing is there in that column
        for(int i=0; i<current_index; i++)
        {
            if(arr[i]==arr[current_index])
            {
                return false;
            }
        }

        // to check if nothing is there in top right diagonal
        
        int current_temp_level = current_index;
        int current_pos = arr[current_index];

        for( ; ; )
        {
            current_temp_level--;
            current_pos++;

            if(current_temp_level==-1||current_pos==size)
            {
                break;
            }

            if(arr[current_temp_level]==current_pos)
            {
                return false;
            }

        }

        current_temp_level = current_index;
        current_pos = arr[current_index];

        for( ; ; )
        {
            current_temp_level--;
            current_pos--;

            if(current_temp_level==-1 || current_pos==-1)
            {
                break;
            }

            if(arr[current_temp_level]==current_pos)
            {
                return false;
            }
        }

        // for(int i = 0; i< size; i++)
        // {
        //     // if(*(arr+i) == -1)
        //     // {
        //     //     return_flag = true;
        //     // }
        //     std::cout << *(arr+i) << " ";
        // }
        // std::cout << "\n";

        for(int i=0; i<size; i++)
        {
            if(arr[i]==-1)
            {
                return_flag = true;
            }
        }
        if(!return_flag)
        {
            completed = true;
            return false;
        }

        return true;
        
    }
};

int main()
{

    int n;
    std::cout << "Enter the number of queens :- ";
    std::cin >> n;

    Solution *s = new Solution(n);

    s->find_ans(0);
    for(int i = 0; i < s->size; i++)
    {
        std::cout << *(s->arr+i) << " ";
    }

}