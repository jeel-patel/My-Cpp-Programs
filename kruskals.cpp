#include<iostream>

int i,j,k,a,b,u,v,n,node=1;
int min,minimum_cost=0,parent[100];

int find(int i)
{
	while(parent[i])
	i=parent[i];
	return i;
}
int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}

void kruskal_algo(int n , int cost[100][100])
{
	std::cout << "The edges of Minimum Cost Spanning Tree are\n";
	while(node < n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j <= n;j++)
			{
				if(cost[i][j] < min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
			std::cout << node++ << " edge " <<  a << " "  << b << " " << min << "\n";
			minimum_cost +=min;
		}
		cost[a][b]=cost[b][a]=999;
	}
	std::cout << "\nMinimum cost = " << minimum_cost << "\n";
}

int main()
{
	int cost[100][100];
	std::cout << "\nEnter the no. of vertices:";
	std::cin >> n;
	std::cout << "\nAdjacency matrix:\n";

	for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            cost[i][j] = rand()%10;
            if(cost[i][j]==0)
                cost[i][j]=999;
            if(i==j)
                cost[i][j] = 0;
        }
    }

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            std::cout << cost[i][j] << " ";
        }
        printf("\n");
    }

	kruskal_algo(n,cost);
}

