#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int radix_sort(vector<int>& nums) {
	if (nums.empty() || nums.size() < 2)
		return 0;

	int maxVal = *max_element(nums.begin(), nums.end());

	int exp = 1;
	int radix = 10;

	vector<int> aux(nums.size());


	while (maxVal / exp > 0) {
		vector<int> count(radix, 0);

		for (int i = 0; i < nums.size(); i++)
			count[(nums[i] / exp) % 10]++;

		for (int i = 1; i < count.size(); i++)
			count[i] += count[i - 1];

		for (int i = nums.size() - 1; i >= 0; i--)
			aux[--count[(nums[i] / exp) % 10]] = nums[i];

		for (int i = 0; i < nums.size(); i++)
			nums[i] = aux[i];

		exp *= 10;
	}

}
//选择排序
//每次选择最小的数，与当前的数进行交换
void select_sort(vector<int>nums) {
	for (int i = 0; i < nums.size(); i++) {
		int min_index = i;
		for (int j = i + 1; j < nums.size(); j++) {
			if (nums[j] < nums[min_index])
				min_index = j;
			swap(nums[i], nums[min_index]);
		}
	}
	for (auto &one_num : nums)
		cout << one_num << "\t";
	cout << endl;
}

//插入排序
//不断的将当前元素向前插入，插入到合适的位置
void insert_sort(vector<int>nums) {
	for (int i = 1; i < nums.size(); i++) {
		for (int j = i; j > 0; j--) {
			if (nums[j] < nums[j - 1])
				swap(nums[j], nums[j - 1]);
			else
				break;
		}
	}
	for (auto &one_num : nums)
		cout << one_num << "\t";
	cout << endl;
}


//希尔排序
//以步长h调用插入排序
//不断的将步长缩短为1
void shell_sort(vector<int>nums) {
	int h = 1;
	int N = nums.size();
	while (h < N / 3)
		h = 3 * h + 1;
	while (h >= 1) {
		for (int i = h; i < N; i++) {
			for (int j = i; j >= h; j = j - h) {
				if (nums[j] < nums[j - h]) {
					swap(nums[j], nums[j - h]);
				}
				else
					break;
			}
		}
		h = h / 3;
	}
	for (auto &one_num : nums)
		cout << one_num << "\t";
	cout << endl;
}


//a[lo...mid]
//a[mid+1...lo]
void merge(vector<int>&nums,int lo,int mid,int hi) {
	int N = nums.size();
	vector<int>aux(N, 0);
	for (int i = lo; i <= hi; i++) {
		aux[i] = nums[i];
	}
	int i = lo;//第一个数组起点
	int j = mid + 1;//第二个数组起点
	int k = lo;
	while (i <= mid&&j <= hi) {
		if (aux[i] < aux[j])
			nums[k++] = aux[i++];
		else
			nums[k++] = aux[j++];
	}
	while (i <= mid) {
		nums[k++] = aux[i++];
	}
	while (j <= hi) {
		nums[k++] = aux[j++];
	}
}

void merge_sort_help(vector<int>&nums,int lo,int hi) {
	if (hi <= lo)
		return;
	int mid = (lo + hi) / 2;
	merge_sort_help(nums, lo, mid);
	merge_sort_help(nums, mid+1, hi);
	merge(nums, lo, mid, hi);
}

void merge_sort(vector<int>nums) {
	merge_sort_help(nums, 0, nums.size() - 1);	
	for (auto &one_num : nums)
		cout << one_num << "\t";
	cout << endl;
}




int partition(vector<int>&nums,int lo,int hi) {
	int pivot = nums[hi];
	//nums[lo...i-1]<pivot
	//nums[i...hi] >=pivot
	//lo是第一个大于等于pivot的元素的索引
	for (int j = lo; j <= hi;j++) {
		if (nums[j] < pivot) {
			swap(nums[j], nums[lo]);
			lo++;
		}
	}
	swap(nums[lo] , nums[hi]);
	return lo;
}
void quick_sort_help(vector<int>&nums, int lo, int hi){
	if (hi <= lo)
		return;
	int j = partition(nums, lo, hi);
	quick_sort_help(nums, lo, j - 1);
	quick_sort_help(nums, j + 1, hi);
}

void quick_sort(vector<int>nums) {
	quick_sort_help(nums, 0, nums.size() - 1);
	for (auto &one_num : nums)
		cout << one_num << "\t";
	cout << endl;
}


//冒泡排序
void bubble_sort(vector<int>nums){
	int N = nums.size();
	for (int i = 0; i < N; i++) {
		for (int j = 1; j < N - i; j++) {
			if (nums[j - 1] > nums[j])
				swap(nums[j - 1], nums[j]);
		}
	}
	for (auto &one_num : nums)
		cout << one_num << "\t";
	cout << endl;
}

//int main() {
//	vector<int>nums{ 1,2,6,9,8,4,5,3,3,2,1,4,5,9,5};
//	select_sort(nums);
//	insert_sort(nums);
//	shell_sort(nums);	
//	merge_sort(nums);
//	quick_sort(nums);
//	bubble_sort(nums);
//}