#include<iostream>
#include<vector>
#include<time.h>


class Solution {
public:
    int coinChange(int *coins, int s, int amount) {
        
        int coins_array_size = s;

        int arr[coins_array_size+1][amount+1];
        
        for( int i=1; i<=amount; i++ )
        {
            arr[0][i] = INT_MAX;
        }
        for( int i=0; i<=coins_array_size; i++ )
        {
            arr[i][0] = 0;
        }
        
        
        for( int i=1; i<=coins_array_size; i++ )
        {
            for(int j=1; j<=amount; j++)
            {
                
                if( j>=coins[i-1] )
                {
                    
                    if( arr[i][j-coins[i-1]]==INT_MAX )
                    {
                        arr[i][j] = arr[i-1][j];
                    }
                    else
                    {
                        arr[i][j]=std::min(arr[i-1][j],1+arr[i][j-coins[i-1]]);
                    }
                    
                }
                else
                {
                    arr[i][j] = arr[i-1][j];
                }
            }
        }   
        
        // return arr[coins_array_size][amount];
        if( arr[coins_array_size][amount]==INT_MAX )
        {
            return -1;
        }
        else
        {
            return arr[coins_array_size][amount];
        }
    }
};

int main(){

    Solution *sol_ptr = new Solution();

    int a;
    std::cout << "Enter how many coins you wan to keep :- ";
    std::cin >> a;

    int arr[a];

    srand(time(NULL));
    for(int i=0; i<a; i++)
    {
        arr[i] = rand()%1000;
        std::cout << " " << arr[i] << " ";
    }

    int amt;
    std::cout << "Enter the amount to be calculate :- ";
    std::cin >> amt;

    std::cout << "The minimum number of coins required is :- " << sol_ptr->coinChange(arr, a, amt);
}