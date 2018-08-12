/*
Write a program to prepare the salary of an employee. The person works on a contractual basis and
is paid based hourly. The working hours of the company are 9:00 AM to 6:00 PM. The employee is
also paid for overtime. The remuneration for his work is 1200 per hour and 1500 per hour for
overtime. Write the code to enter the number of days the person works and number of overtime
hours. Calculate the total number of working hours and the amount to be paid to that person.
*/

#include<iostream>
#include<conio.h>

using namespace std;

//The Remuneration
const int h_remuneration = 1200; // per hour
const int ot_remuneration = 1500; // over time per hour

int main()
{
	system("cls"); //clearing the screen just in case

	int nd,n_ot;

	cout << "Enter The No. Of Days worked : ";
	cin >> nd;

	cout << "\nEnter The No. Of Over time Hours : ";
	cin >> n_ot;

	// Converting No. Of Days into hours
	int nh = nd * 24;

	//Total No. Of Working Hours including Over times
	int twh = nh + n_ot;

	//calculating Salary
	int salary = ( (h_remuneration*nh) + (ot_remuneration*n_ot) );

	//output
	cout << "\nOver Time Hours : " << n_ot << endl;
	cout << "Working hours : " << nh << endl;
	cout << "Total Number of Hours Worked : " << twh << endl;;
	cout << "Salary Generated : Rs." << salary << "/-\n\n" << endl;

	//pausing the screen to view the output
	system("pause");
	return 0;
}