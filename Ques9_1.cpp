/*
Create a class date.Add three data members : day, month and year.Create functions to read
and print date entered by the user.Create another function that adds number of days to the
date and displays the date
*/

#include<iostream>
#include<conio.h>

using namespace std;

// To Store The Number Of days In All 12 Months.
const int MonthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


class date 
{
public:

	void read() //takes the input from user
	{
		cout << "Enter Date :";
		cout << "\t Day : ";
		cin >> _day;
		cout << "\t Month : ";
		cin >> _month;
		cout << "\t year : ";
		cin >> _year;
	}

	void print()	//prints the date entered by the user
	{
		cout << "DATE :- " << _day << "/" << _month << "/" << _year << endl;
	}

	void iprint()	//increments the date and then print it
	{
		if (_month == 2)
		{
			if (_day == 28)
				_month++;
			else
				_day++;
		}
		else if ((_month == 1) || (_month == 3) || (_month == 5) || (_month == 7) || (_month == 8) || (_month == 10) || (_month == 12))
		{
			if (_month != 12)
			{
				if (_day == 31)
					_month++;
				else
					_day++;
			}
			else
			{
				if (_day == 31)
				{
					_month = 1;
					_day = 1;
					_year++;
				}
				else
					_day++;
			}
		}
		else if ((_month == 4) || (_month == 6) || (_month == 9) || (_month == 11))
		{
			if (_day == 30)
				_month++;
			else
				_day++;
		}

		cout << "Incremented DATE :- " << _day << "/" << _month << "/" << _year << endl;

	}


private:
	int _day;
	int _month;
	int _year;

};

int main()
{
	system("cls");

	//declearing class object
	date d;

	d.read();
	d.print();
	d.iprint();

	system("pause");
	return 0;
}