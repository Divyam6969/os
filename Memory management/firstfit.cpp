#include <bits/stdc++.h>
using namespace std;

int main(){
	int processSize[5] = {100,300,120,400,600};//i
	int blockSize[5] = {500,100,200,320,400};//j
	int allocation[5];
	for (int i = 0; i < 5; i++){
		allocation[i] = -1;
	}


	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (blockSize[j] >= processSize[i])
			{
				allocation[i] = j;
				blockSize[j] -= processSize[i];
				break;
			}
		}
	}
	int B_S[5] = {500,100,200,320,400};//j

	cout<<"P no\t\tP size\t\tBlock no\n";
	for (int i = 0; i < 5; i++)
	{
		cout<<"  P"<<i+1<<"\t\t"<<processSize[i]<<"\t\t";
		if (allocation[i] != -1)
		{
			cout<<B_S[allocation[i]]<<"\n";
		}else{
			cout<<"Not Allocated\n";
		}
	}
	return 0;
}