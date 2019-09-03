#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//We sampled integers between 0 and 255, and stored the results in an array count:  
//count[k] is the number of integers we sampled equal to k.

//Return the minimum, maximum, mean, median, and mode of the sample respectively, 
//as an array of floating point numbers.The mode is guaranteed to be unique.


//统计中位数时，分情况讨论
//考虑中位数出现的位置即可
//将奇数和偶数分开讨论


class Solution_1093 {
public:
	vector<double> sampleStats(vector<int>& count) {
		double max_v = -1;
		double min_v = 256;
		double sum = 0;
		double max_count_index = 0;
		double max_count = 0;
		int total_count = 0;
		for (int i = 0; i<count.size(); i++) {
			if (count[i] != 0) {
				max_v = max(max_v, double(i));
				min_v = min(min_v, double(i));
				sum += count[i] * i;
				total_count += count[i];
				if (max_count<count[i]) {
					max_count_index = i;
					max_count = count[i];
				}
			}
		}
		double median = 0.0;
		int half_count = 0;
		//第二次扫描，找到恰好>total_count/2的位置
		for (int i = 0; i<count.size(); i++) {
			half_count += count[i];
			//一共有奇数个数字，找到恰好>total/2的位置即可
			if (total_count % 2 == 1 && half_count>total_count / 2)
			{
				median = i;
				break;
			}
			//有偶数个数字，需要分情况讨论
			else if (total_count % 2 == 0 && half_count >= total_count / 2)
			{
				//当前位置的数字重复多次并且中间位置均为i
				if (half_count>total_count / 2)
				{
					median = i;
				}
				//当前i为中位数左端的点，需要找到下一个数字
				else if (half_count == total_count / 2) {
					for (int j = i + 1; j<count.size(); j++) {
						if (count[j] != 0)
						{
							median = (i + j) / 2.0;
						}
					}
				}
				break;
			}
		}
		//计算中位数
		return vector<double>{ min_v,max_v,sum / total_count,median,max_count_index };
	}
};

//int main() {
//	Solution_1093 s;
//	vector<int>A{ 0,1,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
//
//	s.sampleStats(A);
//}