#include <stdio.h>
#include <stdlib.h>
int myCeil(float f_nm)
{
	int i = 0;
	while(1)
	{
		f_nm--;
		i++;
		if(f_nm <= 0)
			return i;
	}
}

int main()
{
	int N;
	scanf("%d",&N);
	int a[10000];
	for (int i =0 ;i<N;i++)
	{
		scanf("%d",&a[i]);
	}

	float f_nm = (float)N/2;


	for(int upperbound = myCeil(f_nm); upperbound >= 1; upperbound--)
	{
		//	printf("upperbound:%d\n",upperbound);

		int candidate[1000][1000];
		int candidate_ct = 1;
		int ct[1000] = {0};
		//find the first candidate
		for(int k = 0; k < upperbound; k++)
		{
			candidate[0][k] = a[k];
		}

		candidate_ct++;

		//start from 1
		for(int start = 1;start < N; start++)
		{
			//find the candidate in the sequence
			for(int k = 0; k < upperbound; k++)
			{
				if( start + k >= N)
					break;
				for(int z = 0; z < candidate_ct - 1; z++)
				{
					if(a[start + k] == candidate[z][k])
					{
						ct[z]++;
						if(ct[z] == upperbound)
						{
							printf("%d",upperbound);
							exit(0);
						}
					}
				}
				//if the program does not terminate, it means that there is a new candidate.
				candidate[candidate_ct][k] = a[start + k];
			}
		}
	}
}
