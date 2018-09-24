#include<iostream>
#include<vector>
#include<iterator>
#include<conio.h>
using namespace std;


int main()
{

	vector<int> vect;
	vector<int> ::iterator itr;
	int total = 0;
	while (1)
	{
		cout << "Enter your Choice" << endl;
		cout << "1. Add Item" << endl;
		cout << "2. Remove Item" << endl;
		cout << "3. Modify Item" << endl;
		cout << "4. View All Item" << endl;
		cout << "5. Sum Up" << endl;

		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter item you want to insert" << endl;
			cin >> choice;
			vect.push_back(choice);
			break;
		case 2:
			cout << "Enter item you want to remove" << endl;
			cin >> choice;
			itr = find(vect.begin(), vect.end(), choice);
			if (itr != vect.end())
			{
				vect.erase(itr);
			}
			else
			{
				cout << "Item does not exists..." << endl;
			}
			break;
		case 3:
			cout << "Enter Item you want to Modify" << endl;
			cin >> choice;
			itr = find(vect.begin(), vect.end(), choice);
			if (itr != vect.end())
			{
				cout << "Enter new value" << endl;
				cin >> choice;
				*itr = choice;
			}
			else
				cout << "Item doesn't exists" << endl;
		case 4:
			copy(vect.begin(), vect.end(), ostream_iterator<int>(cout, "\n"));
			break;
		case 5:
			for (itr = vect.begin(); itr != vect.end(); itr++)
			{
				total = total + *itr;
			}
			cout << "Total : " << total << endl;
			//exit(0);
			break;
		case 0:
			exit(0);
			break;
		default:
			cout << "Wrong Choice" << endl;
		}
	}
}