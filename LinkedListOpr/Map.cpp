// Vector Assignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<iostream>
#include<map>
#include<string>
#include<string.h>
using namespace std;

int main()
{




	map<string, int> my_map;
	map<string, int> ::iterator itr;
	int choice;
	while (1)
	{
		cout << "Enter your choice\n 1. Add item to cart\n 2. Remove item\b\n 3. View all items \n 4. Update Qty\n 5. exit" << endl;
		int choice;
		cin >> choice;

		string item;
		int qty, total = 0;
		switch (choice)
		{

		case 1:
			cout << "Enter Item Name" << endl;
			cin >> item;
			cout << "Enter Quantity" << endl;
			cin >> qty;

			itr = my_map.find(item);
			if (itr != my_map.end())
			{
				//cout <<itr->first << endl;
				cout << "Item Already Available... " << endl;
				//itr->second = qty;
				/*cout << "Do you want to update...?? (Y/N)" << endl;
				char choice;
				cin >> choice;

				if (choice == 'Y' || choice == 'y')
				{
					itr = my_map.find(item);
					itr->second = qty;
				}*/

			}
			/*if (my_map.find(item) == my_map.end()) {

				my_map.insert(pair<string, int>(item, qty));
			}*/
			else
			{
				my_map.insert(pair<string, int>(item, qty));
			}
			break;
		case 2:
			cout << "Enter item you want to remove" << endl;
			cin >> item;
			if (my_map.erase(item))
			{
				cout << "Item removed successfully" << endl;
				break;
			}
			cout << "Item Not Found..!!" << endl;
			break;
		case 3:
			for (itr = my_map.begin(); itr != my_map.end(); ++itr)
			{
				cout << '\t' << itr->first
					<< '\t' << itr->second << '\n';
			}
			break;
		case 4:
			cout << "Enter Item quantity you want to update ? " << endl;
			cin >> item;
			itr = my_map.find(item);
			if (itr != my_map.end())
			{
				//cout <<itr->first << endl;
				itr->second = qty;
			}
			/*if (my_map.find(item) == my_map.end()) {

			my_map.insert(pair<string, int>(item, qty));
			}*/
			else
			{
				cout << "Item Not Found" << endl;
			}
			break;

		case 5:
			for (itr = my_map.begin(); itr != my_map.end(); itr++)
			{
				cout << '\t' << itr->first
					<< '\t' << itr->second << '\n';

				total = total + itr->second;
			}
			cout << '\t' << "Total" << '\t' << total;
			//exit(0);
		default:
			exit(0);
		}

		/*cout << "Enter your choice\n 1. Add item to cart\n 2. Remove item\b\n 3. View all items \n 4. Update Qty\n 5. exit" << endl;
		choice;
		cin >> choice;*/

	}
	return 0;
}

