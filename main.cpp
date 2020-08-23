#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

class algorithm_Manaker
{
	std::string str;
	int* ansPal_uneven;
	int* ansPal_even;

public: algorithm_Manaker(std::string input_str) :str(input_str)
	{
		int len = input_str.length();
		ansPal_even = new int[len];
		ansPal_uneven = new int[len];
		memset(ansPal_even, 0, sizeof(int)*len);
		memset(ansPal_uneven, 0, sizeof(int)*len);
	};
	algorithm_Manaker() :str(0), ansPal_even(0), ansPal_uneven(0) {};

	
	//Find palindroms like 2*N+1
	void calculate_array_Palindrom_uneven()
	{
		int leftBorder = 0, rightBorder = -1, tempMirror;//start digits for algortihm
		for (int i = 0; i < str.length(); ++i)
		{
			tempMirror = (i > rightBorder ? 0 : std::min(ansPal_uneven[leftBorder + rightBorder - i],
				rightBorder - i)) + 1;//find mirror of current index
			while (i + tempMirror < str.length() && i - tempMirror >= 0 &&
				str[i - tempMirror] == str[i + tempMirror])//increase our index
			{
				++tempMirror;
			}
			ansPal_uneven[i] = --tempMirror;
			if (i + tempMirror > rightBorder)//try to increase our right border of palindrom
			{
				leftBorder = i - tempMirror;
				rightBorder = i + tempMirror;
			}
		}
	};

	void calculate_array_Palindrom_even()
	{
		int leftBorder = 0, rightBorder = -1, tempMirror;
		for (int i = 0; i < str.length(); ++i)
		{
			tempMirror = (i > rightBorder ? 0 : std::min(ansPal_even[leftBorder + rightBorder - i + 1],
				rightBorder - i + 1)) + 1;
			while (i + tempMirror - 1 < str.length() &&
				i - tempMirror >= 0 && str[i - tempMirror] == str[i + tempMirror - 1])
			{
				++tempMirror;
			}
			ansPal_even[i] = --tempMirror;
			if (i + tempMirror - 1 > rightBorder)
			{
				leftBorder = i - tempMirror;
				rightBorder = i + tempMirror - 1;
			}
		}
	};


	int find_count_palindrom ()
	{
		calculate_array_Palindrom_even();
		calculate_array_Palindrom_uneven();
		int len = str.length();
		int sum_palindrom = 0;
		for (int i = 0; i < len; ++i)
		{
			sum_palindrom += ansPal_even[i];
			sum_palindrom += ansPal_uneven[i];
		}
		sum_palindrom += len;
		return sum_palindrom;
	};
};


int main()
{
	std::string input;
	std::cin >> input;
	algorithm_Manaker a(input);
	std::cout << a.find_count_palindrom();
	return 1;
	

};
