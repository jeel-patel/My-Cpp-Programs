#include<iostream>
#include<stdio.h>
#include<string.h>

std::string generate_random_string(int length){
    
    const char ch[] = "abcdefghij";//klmnopqrstuvwxyz";

    std::string str="";

    for(int i=0;i<length;i++){

        str = str + ch[rand() % strlen(ch)];

    }

    return str;

}

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        
        int word1_length = word1.length();
        int word2_length = word2.length();
        
        int arr[word2_length+1][word1_length+1];
   
        for(int i=0; i<=word2_length; i++){
            arr[i][0] = i;
        }
        for(int i=0; i<=word1_length; i++){
            arr[0][i] = i;
        }
        
        for(int i=1; i<=word2_length; i++){
            for(int j=1; j<=word1_length; j++){
                
                if( word2[i-1] == word1[j-1] )
                {
                    // int temp = std::min( arr[i-1][j],arr[i][j-1] );
                    arr[i][j] = arr[i-1][j-1];
                    // arr[i][j] = std::min(temp, arr[i-1][j-1]);
                }
                else
                {
                    int temp = std::min( arr[i-1][j]+1,arr[i][j-1]+1 );
                    
                    arr[i][j] = std::min(temp, arr[i-1][j-1] +2);   
                }
                
            }
        }
        
        return arr[word2_length][word1_length];
    }
};

int main(){

    Solution *ptr = new Solution();

    int a,b;
    std::cout << "Enter the size of the first string :- ";
    std::cin >> a;

    std::cout << "Enter the size of the second string :-";
    std::cin >> b;

    std::string str1 = generate_random_string(a);
    std::string str2 = generate_random_string(b);

    std::cout << "String 1 : " << str1 << "\n";
    std::cout << "String 2 : " << str2 << "\n";
 
    std::cout << ptr->minDistance(str1,str2);

}