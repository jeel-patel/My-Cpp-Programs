#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>

//we will make an min heap and we will know the min edge every time we want

struct node_data{

public:
    int from;
    int to;
    int cost;

    node_data(int f, int t,int c){
        from = f;
        to = t;
        cost = c;

    }

};

struct cmp{

public:
    bool operator()(node_data* a,node_data* b){

        if(a->cost > b->cost){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){

    int n;

    std::cout << "Enter the number of vertices : ";
    std::cin >> n;

    std::priority_queue<node_data*,std::vector<node_data*>, cmp> queue;

    int arr[n][n];
    srand(time(NULL));

    std::cout << "Adjencetcy matrix\n";

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            arr[i][j] = rand()%1000;

            if( arr[i][j]>300){
                arr[i][j] = INT_MAX;
            }

            if(arr[i][j]!=INT_MAX){
                std::cout << arr[i][j] << " " ;
            }
            else{
                std::cout << -1 << " ";
            }
        }
        std::cout << "\n";
    }

    std::cout << "\n\n";

    std::cout << "From|To|cost\n";

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){

            if( arr[i][j]!=INT_MAX ){
                queue.push(new node_data(i,j,arr[i][j]));
            }
        }

        std::cout << queue.top()->from << " " << queue.top()->to << " " << queue.top()->cost << "\n";
        
        i = queue.top()->to-1;
        queue.pop();
    }
}