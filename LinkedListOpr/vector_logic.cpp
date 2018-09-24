
#include "pch.h"
#include <iostream>
#include<vector>
#include<iterator>
#include<time.h>
using namespace std;

int count(vector<int> v, int num)
{
	vector<int> ::iterator itr;
	int count = 0;


	for (itr = v.begin(); itr != v.end(); itr++)
	{
		if (*itr == num)
			count++;
	}

	return count;
}

bool check(vector<int> v, int num)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i) == num)
			return true;
	}
	return false;
}

int main()
{
	vector<int> ::iterator itr;
	vector<int> vect;
	vector<int> temp;
	srand(time(NULL));
	int lower = 1;
	int upper = 50;

	for (int i = 0; i < 100; i++)
	{
		int num = (rand() %
			(upper - lower + 1)) + lower;
		vect.push_back(num);
	}

	/*vect.push_back(10);
	vect.push_back(20);
	vect.push_back(30);
	vect.push_back(40);
	vect.push_back(20);

	int c = count(vect, 20);
	cout << "count " << c << endl;*/
	/*if (check(vect, 20))
	{
		cout << "Found" << endl;
	}*/
	copy(vect.begin(), vect.end(), ostream_iterator<int>(cout, " "));
	/*for (int i = 0; i < vect.size(); i++)
	{
		cout << vect.at(i) << endl;
	}
*/
	for (int i = 0; i < 100; i++)
	{

		//int count = 0;
		int num = vect.at(i);
		//temp.push_back(num);
		//cout << "NUM " << num << endl;
		if (!temp.empty())
		{

			itr = find(temp.begin(), temp.end(), num);

			if (itr == temp.end())
			{
				temp.push_back(num);
				int c = count(vect, num);

				if (c > 5)
				{

					cout << "\nNumbers more than 5 times in Vector" << endl;
					cout << num << endl;
				}
				if (c > 2 && c < 5)
				{

					cout << "\nNumbers 2 - 5 times in Vector" << endl;
					cout << num << endl;
				}
				if (c == 1)
				{

					cout << "\nUnique Numbers in Vector" << endl;
					cout << num << endl;
				}
				if (c == 3 || c == 4)
				{

					cout << "\nNumbers 3 or 4 times in Vector" << endl;
					cout << num << endl;
				}

			}
		}
		else
		{
			temp.push_back(num);
			int c = count(vect, num);
			if (c > 5)
				cout << num << endl;
		}


	}


	return 0;
}