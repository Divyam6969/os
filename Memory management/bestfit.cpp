#include <bits/stdc++.h>
using namespace std;

int main(){
	int P_s[5] = {220,439,234,554,160};//i
	int B_s[5] = {700,400,500,200,150};//j
	int aloc[5];
	for (int i = 0; i < 5; i++)
	{
		aloc[i] = -1;
	}

	int indx;
	for (int i = 0; i < 5; i++)//P_s
	{
		indx = -1;
		for (int j = 0; j < 5; j++)//B_s
		{
			if (B_s[j] >= P_s[i])
			{
				if (indx == -1)
				{
					indx = j;
				}
				else if (B_s[j] < B_s[indx])
				{
					indx = j;
				}
			}
		}
		if (indx != -1)
		{
			aloc[i] = indx;
			B_s[indx] -= P_s[i];
		}
	}
	int BLOCK_s[5] = {700,400,500,200,150};//j
	cout<<"P no:\t\tP SIZE\t\tBlock no\n";
	for (int i = 0; i < 5; i++){
		cout<<"  P"<<i+1<<"\t\t"<<P_s[i]<<"\t\t";
		if (aloc[i] != -1)
		{
			cout<<BLOCK_s[aloc[i]]<<"\n";
		}else{
			cout<<"Not Allocated\n";
		}
	}

	return 0;
}