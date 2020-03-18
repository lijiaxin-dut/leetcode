#include<vector>
#include<random>
#include<ctime>
using namespace std;
void Fisher_Yates_Shuffle(vector<int>& arr, vector<int>& res)
{
	srand((unsigned)time(NULL));
	int k;
	int M = arr.size();
	for (int i = 0; i < M; ++i)
	{
		k = rand() % arr.size();
		res.push_back(arr[k]);
		arr.erase(arr.begin() + k);
	}
}