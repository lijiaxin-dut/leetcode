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


//ͳ����λ��ʱ�����������
//������λ�����ֵ�λ�ü���
//��������ż���ֿ�����


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
		//�ڶ���ɨ�裬�ҵ�ǡ��>total_count/2��λ��
		for (int i = 0; i<count.size(); i++) {
			half_count += count[i];
			//һ�������������֣��ҵ�ǡ��>total/2��λ�ü���
			if (total_count % 2 == 1 && half_count>total_count / 2)
			{
				median = i;
				break;
			}
			//��ż�������֣���Ҫ���������
			else if (total_count % 2 == 0 && half_count >= total_count / 2)
			{
				//��ǰλ�õ������ظ���β����м�λ�þ�Ϊi
				if (half_count>total_count / 2)
				{
					median = i;
				}
				//��ǰiΪ��λ����˵ĵ㣬��Ҫ�ҵ���һ������
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
		//������λ��
		return vector<double>{ min_v,max_v,sum / total_count,median,max_count_index };
	}
};

//int main() {
//	Solution_1093 s;
//	vector<int>A{ 0,1,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
//
//	s.sampleStats(A);
//}