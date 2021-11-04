#include<iostream>
#include <string>
#include<time.h>

//for generating random string
std::string  get_random_string(int len) {
    std::string s;
    static const char alphanum[] =
        "ABCDEFpqrstuvwGHIQijbcdeklmRSTUVWXYJKLMNOPxyzZafghno";

    for (int i = 0; i < len; ++i) {
        s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    for(int i=0; i<=100000; i++){

    }

    return s;
}

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
    
        int text1_length = text1.length();
        int text2_length = text2.length();
        
        int arr[text1_length+1][text2_length+1];
        
        for(int i=0; i<=text1_length; i++)
        {
            arr[i][0] = 0;
        }
        
        for(int i=0; i<=text2_length; i++)
        {
            arr[0][i] = 0;
        }
        
        
        for(int i=1; i<=text1_length; i++)
        {
            for(int j=1; j<=text2_length; j++)
            {
                
                if( text1[i-1]==text2[j-1] )
                {
                    arr[i][j] = arr[i-1][j-1] +1;
                    
                }
                else
                {
                    arr[i][j] = std::max(arr[i-1][j],arr[i][j-1]);  
                }
            }
        }
        
        return arr[text1_length][text2_length];
        
    }
};

int main()
{
    Solution *s = new Solution();

    srand(time(NULL));
    int a,b;
    std::cout << "Enter the size of first string :- ";
    std::cin >> a;

    std::cout << "Enter the size of second string :- ";
    std::cin >> b;

    std::string str1 = get_random_string(a);
    std::string str2 = get_random_string(b);

    std::cout << str1 << "\n";
    std::cout << str2 << "\n";

    std::cout << s->longestCommonSubsequence(str1, str2);

}