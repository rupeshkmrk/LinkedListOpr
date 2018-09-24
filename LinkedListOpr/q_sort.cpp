// qsort_implementation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
struct Employee {
	Employee() {}

	void setDetails(int emp_no, char dept_id, long mob_no)
	{
		this->emp_no = emp_no;
		this->dept_id = dept_id;
		this->mob_no = mob_no;
	}
	int emp_no;
	char dept_id;
	long mob_no;
	void printEmp()
	{
		cout << "Emp no. " << emp_no << " Dept ID " << dept_id << " Mobile " << mob_no << endl;
	}
}emp1, emp2;

int funEmpNo(const void *x, const void *y)
{
	Employee *x1 = (Employee*)x;
	Employee *y1 = (Employee*)y;
	return (x1->emp_no) - (y1->emp_no);



}
int funDept(const void *x, const void *y)
{
	Employee *x1 = (Employee*)x;
	Employee *y1 = (Employee*)y;
	return (x1->dept_id) - (y1->dept_id);



}

int funMob(const void *x, const void *y)
{
	Employee *x1 = (Employee*)x;
	Employee *y1 = (Employee*)y;
	return (x1->mob_no) - (y1->mob_no);



}


int main()
{

	Employee emp[3];
	emp[0].setDetails(191, 'E', 1235467824);
	emp[1].setDetails(201, 'D', 1223245452);
	emp[2].setDetails(402, 'C', 1234235354);
	/*emp[0].emp_no = 201;
	emp[0].dept_id = 'A';
	emp[0].mob_no = 1235467890;
	emp[1].emp_no = 101;
	emp[1].dept_id = 'D';
	emp[1].mob_no = 9876546543;
*/
	qsort(emp, 3, sizeof(Employee), funEmpNo);

	for (int i = 0; i < 3; i++)
	{
		emp[i].printEmp();
	}
	cout << "-----------" << endl;
	qsort(emp, 3, sizeof(Employee), funDept);
	for (int i = 0; i < 3; i++)
	{
		emp[i].printEmp();
	}
	cout << "-----------" << endl;
	qsort(emp, 3, sizeof(Employee), funMob);
	for (int i = 0; i < 3; i++)
	{
		emp[i].printEmp();
	}

	return 0;
}

