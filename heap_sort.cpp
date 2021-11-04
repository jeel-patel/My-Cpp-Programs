#include<iostream>
#include<time.h>
#include<vector>

using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {

        nums = make_heapify(nums);

        std::vector<int> ans;
        ans.reserve(nums.size());

        for(int i=0 ;nums.size()!=0 ; i++)
        {
            ans.push_back(nums[0]);
//            std::cout << nums[0];
            nums[0] = nums[nums.size()-1];
            nums.pop_back();
            if(nums.size()==0){break;}

            heapify(nums);

        }
        return ans;

    }

private:
    void heapify(std::vector<int> &a)
    {
        int i=0;
        for( ; ; )
        {
            if( (i*2+1)>(a.size()-1) && (i*2+2)>(a.size()-1) )
            {
                return;
            }

            if( (i*2+1)==(a.size()-1) )
            {
                if( a[i] > a[i*2+1] )
                {
                    int t = a[i];
                    a[i] = a[i*2+1];
                    a[i*2+1] = t;
                }
                else
                {
                    return;
                }
            }
            if( a[i] <= std::min(a[i*2+1], a[i*2+2]) )
            {
                return;
            }
            else{

                int s = std::min(a[i*2+1], a[i*2+2]);

                if( s==a[i*2+1] )
                {
                    a[i*2+1] = a[i];
                    a[i] = s;

                    i=i*2+1;
                }
                else
                {

                    a[i*2+2] = a[i];
                    a[i] = s;

                    i=i*2+2;
                }
            }

        }
    }


    std::vector<int> make_heapify(std::vector<int> a){

        for(int i=1; i<a.size(); i++)
        {
            for(int j=i; j>0; )
            {
                if( a[(j-1)/2] <=a[j] )
                {
                    break;
                }
                else
                {
                    int tem = a[(j-1)/2];
                    a[(j-1)/2] = a[j];
                    a[j] = tem;

                    j = (j-1)/2;
                }
            }
        }

        return a;
    }

};

int main()
{
    Solution *s = (Solution *)malloc(sizeof(Solution));

    int n,b;
    std::cout << "Enter the number of element you want in the array :- ";
    std::cin >> n;

    std::cout << "Enter from which you want to have less than :- ";
    std::cin >> b;

    std::vector<int> arr;
    arr.reserve(n);

    srand(time(NULL));
    for(int i=0; i<n; i++)
    {
        arr.push_back(rand()%b);
//        arr[i] = rand()%b;
    }


    arr = s->sortArray(arr);

    for(int i:arr)
    {
        std::cout << i << " ";
    }
}