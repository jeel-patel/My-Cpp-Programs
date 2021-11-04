#include<iostream>
#include<bits/stdc++.h>

struct Job{

    public:

        int job_id;
        int deadline_for_job;
        int profit_for_job;

};

bool cmp(const Job &a,const Job &b){

    if(a.profit_for_job<b.profit_for_job){
        return false;
    }
    else{
        return true;
    }

}

int main()
{
    int n;
    std::cout << "Enter the number of jobs :- ";
    std::cin >> n;

    Job job_array[n];

    int max_deadline=-1;
                                                                                                                      
    for(register int i=0; i<n; i++)
    {
        std::cout << "Enter the deadline for job " << i+1 << " :- ";
        std::cin >> job_array[i].deadline_for_job;

        max_deadline = std::max(max_deadline, job_array[i].deadline_for_job);

        std::cout << "Enter profit for job " << i+1 <<" :- ";
        std::cin >> job_array[i].profit_for_job;

        job_array[i].job_id = i+1;
    }

    std::sort(job_array, job_array+n,cmp);

    int slots[max_deadline];

    for(int i=0; i<max_deadline; i++){
        slots[i]=-1;
    }

    int profit = 0;
    for(int i=0; i<n; i++){

        for(int k=job_array[i].deadline_for_job-1; k>=0; k--)
        {
            if(slots[k]==-1){
                slots[k]=job_array[i].job_id;
                profit = profit + job_array[i].profit_for_job;
                break;
            }
        }
    }

    std::cout << "The max profit can be achieved is :- " << profit << "\n";
    
    std::cout << "The following jobs will be completed : \n";
    for(int i=0; i<max_deadline; i++){
        std::cout << slots[i] << " ";
    }
}