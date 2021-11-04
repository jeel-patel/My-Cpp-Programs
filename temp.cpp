#include<iostream>
#include<map>

class cmp
{
    public:
       bool operator() (int a,int b){

           if( a>b )
           {
               return 1;
           }
           else
           {
               return 0;
           }

       } 
};

int main()
{
    std::map<int, int, cmp> hm;

    hm[1] = 3;
    hm[2] = 44;
    hm[33] = 123;

    std::cout << hm.size() << "\n";

    for(auto it = hm.begin(); it!=hm.end(); it++)
    { 
        std::cout << it->first << " " << it->second << "\n";
    }
}
