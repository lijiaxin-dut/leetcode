#include<string>
#include<vector>
using namespace std; 

//A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules :
//
//For 1 - byte character, the first bit is a 0, followed by its unicode code.
//For n - bytes character, the first n - bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being 10.
//This is how the UTF - 8 encoding would work :
//
//Char.number range | UTF - 8 octet sequence
//(hexadecimal) | (binary)
//-------------------- + -------------------------------------------- -
//0000 0000 - 0000 007F | 0xxxxxxx
//0000 0080 - 0000 07FF | 110xxxxx 10xxxxxx
//0000 0800 - 0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
//0001 0000 - 0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx


//根据规则，判断
//注意越界
//判断时，根据


class Solution_393 {
public:
	bool validUtf8(vector<int>& data) {
		int current_index = 0;
		while (current_index<data.size()) {
			if (data[current_index]>255 || data[current_index]<0) {
				return false;
			}
			if ((data[current_index] >> 7) == 0) {
				current_index++;
				continue;
			}
			else if (
				(data[current_index] >> 5) == 0x00000006 &&
				current_index + 1<data.size() &&
				(data[current_index + 1] >> 6) == 0x00000002)
			{
				current_index = current_index + 2;
				continue;
			}
			else if (
				(data[current_index] >> 4) == 0x0000000e &&
				current_index + 2<data.size() &&
				(data[current_index + 1] >> 6) == 0x00000002 &&
				(data[current_index + 2] >> 6) == 0x00000002)
			{
				current_index = current_index + 3;
				continue;
			}
			else if (
				(data[current_index] >> 3) == 0x0000001e &&
				current_index + 3<data.size() &&
				(data[current_index + 1] >> 6) == 0x00000002 &&
				(data[current_index + 2] >> 6) == 0x00000002 &&
				(data[current_index + 3] >> 6) == 0x00000002)
			{
				current_index = current_index + 4;
				continue;
			}
			return false;
		}

		return true;

	}
};

//int main() {
//	Solution_393 s;
//	s.validUtf8(vector<int>{ 240, 162, 138, 147 });
//}