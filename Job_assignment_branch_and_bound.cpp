#include <iostream>
#include<bits/stdc++.h>
class node
{
    public:
        int value;
        int index;

        node(int v, int i)
        {
            this->value = v;
            this->index = i;
        }
};

bool cmp_function(node *a, node *b)
{
    if(a->value < b->value)
    {
        return true;
    }
    else
    {
        return false;
    }
}

class Solution
{
    int n;
    int **ptr;
    bool *occupied_bits_final;
    node ***min_array;

public:
    int final_ans;
    Solution(int n)
    {
        this->n = n;
        occupied_bits_final = new bool[n];
        for(int i = 0; i < n; i++)
        {
            occupied_bits_final[i]=false;
        }

        ptr = new int *[n];
        final_ans = 0;
        min_array = (node***)malloc(sizeof(node **) * n);

        for (int i = 0; i < n; i++)
        {
            ptr[i] = new int[n];
            min_array[i] = (node **)malloc(sizeof(node*)*n);

            std::cout << "Enter the details for person : " << i + 1 << "\n";
            for (int j = 0; j < n; j++)
            {
                
                std::cout << "\tEnter the time for " << j + 1 << " job :- ";
                std::cin >> ptr[i][j];
                
                min_array[i][j] = new node(ptr[i][j],j);
            }
            std::sort(min_array[i],min_array[i]+n,cmp_function);
        }

        // for(int i=0; i < n; i++)
        // {
        //     for(int j=0; j < n; j++)
        //     {
        //         std::cout << min_array[i][j]->value << "," << min_array[i][j]->index << " "; 
        //     }
        //     std::cout << "\n";
        // }
    }

    void find_the_ans()
    {
        // std::cout << "Hello";
        int lower_bound=0;
        int prev_index=-1;

        for(int i = 0; i< n; i++)
        {
            // std::cout << i;
            lower_bound = lower_bound + min_array[i][0]->value;
        }

        bool *occupied_bits;
        int *bound_values;
        int *bound_index;
        int temp_sum=0;
        int counter=0;

        
        for(int i = 0; i < n; i++)
        {
            counter = 0;
            bound_values = new int[n-i];
            bound_index = new int[n-i];

            for(int j=0; j < n; j++)
            {
                if(occupied_bits_final[j])
                {
                    // std::cout << occupied_bits[j] << " ";
                    continue;
                }

                occupied_bits = new bool[n];
                temp_sum = ptr[i][j]+final_ans;

                for(int i = 0; i < n; i++)
                {
                    *(occupied_bits+i) = *(occupied_bits_final+i);
                }
                *(occupied_bits+j) = true;

                for(int l = i+1; l < n; l++)
                {
                    for(int m= 0; m < n; m++)
                    {
                        if(occupied_bits[min_array[l][m]->index]==false)
                        {
                            // std::cout << min_array[l][m]->value << " ";
                            temp_sum = temp_sum + min_array[l][m]->value;
                            *(occupied_bits+min_array[l][m]->index) = true;
                            break;
                        }
                    }
                }
                
                bound_values[counter] = temp_sum;
                // std::cout << temp_sum << " ";
                bound_index[counter] = j;
                counter++;
            }

            int *p1 = std::min_element(bound_values,bound_values+n-i);
            final_ans = final_ans+ ptr[i][bound_index[p1-bound_values]];
            occupied_bits_final[bound_index[p1-bound_values]] = true;
            prev_index = bound_index[p1-bound_values];
        }  
    }
};

int main()
{
    int n;
    std::cout << "Enter the number of jobs and persons :- ";
    std::cin >> n;

    Solution *s = new Solution(n);
    s->find_the_ans();

    std::cout << s->final_ans;
}
