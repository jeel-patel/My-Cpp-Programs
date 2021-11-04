#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>

class Solution{

    private:
        int n;
        int **arr;
        bool *checked;
        int index;

    public:
        bool ansFound=false;
        int *ans;

        Solution(int n)
        {
            checked = new bool[n];
            checked[0] = true;
            ans = new int[n];
            ans[0] = 0;
            index=n-1;

            for(int i = 1; i < n; i++)
            {
                checked[i] = false;
            }

            arr = new int*[n];
            this->n = n;

            for(int i = 0; i < n; i++)
            {
                arr[i] = new int[n];
                for(int j = i; j < n; j++)
                {
                    std::cout << "Is " << i << " and " << (j) << " connected : (1/0)";
                    std::cin >> arr[i][j];
                }
            }

            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j<i; j++)
                {
                    arr[i][j] = arr[j][i];
                }
            }

            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    std::cout << arr[i][j] << " ";
                }
                std::cout << "\n";
            }
            std::cout << "\n\n";
            // std::cout << "Hello";
            callForAns(0);
        }

        void callForAns(int start)
        {
            int i = start;

            // std::cout << start << " ";

            for(int j = 0; j<n; j++)
            {
                // if(j==0 && arr[i][j]==1)
                // {
                //     for(int k = 0; k<n; k++)
                //     {
                //         if(checked[k]==false){
                //             // std::cout << "H";
                //             return;
                //         }
                //     }
                //     std::cout << "Found ";
                // }
                // else if(arr[i][j]==1 && checked[j]==false)
                // {
                //     checked[j] = true;

                //     // for(int l = 0; l < n; l++)
                //     // {
                //     //     std::cout << checked[l] << " ";
                //     // }
                //     std::cout << arr[i][j] << " " << checked[j] << " " << j << "\n";
                //     callForAns(j);
                //     checked[j] = false;
                // }

                if(arr[i][j]==1)
                {
                    if(j==0)
                    {
                        for(int l = 0; l < n; l++)
                        {
                            if(checked[l]==false)
                            {
                                goto abc;
                            }
                        }   
                        // std::cout << "Success!";   
                        ansFound = true;
                        return;                 
                    }
                    if(checked[j]==false)
                    {
                        checked[j] = true;
                        callForAns(j);
                        if(ansFound)
                        {
                            ans[index] = j;
                            index--;
                            return;
                        }

                        checked[j] = false;
                    }
                }
                abc:
                std::cout << "";
                if(ansFound)
                {
                    return;
                }
            }
        }
};

int main()
{

    int n;
    std::cout << "Enter the number : ";
    std::cin >> n;

    Solution s(n);

    if(s.ansFound)
    {
        std::cout << "Success we found hamilton circuit : "; 
        for(int i=0; i < n; i++)
        {
            std::cout << s.ans[i] << " ";
        }
    }
    else
    {
        std::cout << "No paths found";
    }
}

// Input 1
/*(0)--(1)--(2) 
    | / \ |
    | / \ |
    | / \ |
    (3) (4) */

//Input 2 
/*(0)--(1)--(2)
        | / \ |
        | / \ |
        | / \ |
        (3)-------(4) */
