#include<iostream>
#include<time.h>

void merge_sort(int *, int, int);
void merge_array(int *, int, int, int, int);

int main()
{
    int n;
    std::cout << "Enter the number of elements you want :- ";
    std::cin >> n;

    int a;
    std::cout << "Enter the value to be less than :- ";
    std::cin >> a;

    int *arr = (int*)malloc(sizeof(int)*n);

    std::srand(time(0));
    for(int i=0; i<n; i++){

//        std::cout << "Enter the " << (i+1) << " element :- ";
//        std::cin >> *(arr+i);
        *(arr+i) = rand()%a;
    }

    merge_sort(arr, 0, n-1);

    for(int i=0; i<n; i++){

        std::cout << *(arr+i) << " ";
    }
}

void merge_sort(int *ptr, int s, int e)
{
    if( s<e )
    {
        merge_sort(ptr, s, s+(e-s)/2);
        merge_sort(ptr, s+(e-s)/2+1, e);

        merge_array(ptr, s,s+(e-s)/2, s+(e-s)/2+1, e);
    }
}

void merge_array(int *ptr, int s1, int e1, int s2, int e2)
{
    int new_temp_array[(e1-s1)+1+(e2-s2)+1];

    int first_ptr = s1, second_ptr = s2;

    for(int i=0; i<((e1-s1)+1+(e2-s2)+1); i++){

        if( first_ptr<=e1 && second_ptr<=e2 ) {

            if (*(ptr + first_ptr) < *(ptr + second_ptr)) {
                new_temp_array[i] = *(ptr + first_ptr);
                first_ptr++;
            } else {

                new_temp_array[i] = *(ptr + second_ptr);
                second_ptr++;
            }
        }
        else{

            if( first_ptr > e1 )
            {
                for(int j=second_ptr; j<=e2; j++){
                    new_temp_array[i] = *(ptr+j);
                    i++;
                }
                break;
            }
            else{

                for(int j=first_ptr; j<=e1; j++){
                    new_temp_array[i] = *(ptr+j);
                    i++;
                }
                break;
            }
        }
    }

    for(int i=s1; i<=e2; i++){
        *(ptr+i) = new_temp_array[i-s1];
    }
}
