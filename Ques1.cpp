/*
The Program takes the BirthDate As Input and Calculates the Number Of weeks and Number Of
Days That a Person Has Lived As On the Current Date.
*/

#include<iostream>
#include<conio.h>

using namespace std;

struct Date		//Data Structure for Representing The Date.
{
	int d, y, m;	// A date has day 'd', month 'm' and year 'y'

};

// To Store The Number Of days In All 12 Months.
const int MonthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

//Prototypes of the Function Used.
void inputDate(Date &a);
int countLeapYears(Date d);
int getDifference(Date Bdate, Date Cdate);

int main() //main function starts here
{
	system("cls"); //Clearing The Screen just in case

	Date Bdate, Cdate; //Declaring The Objects of date Structure

	cout << "Please Enter Your Date Of Birth :-" << endl;
	inputDate(Bdate);
	cout << "\n Please Enter Today's Date :- " << endl;
	inputDate(Cdate);

	int nd = getDifference(Bdate, Cdate); //getting the Number of Days from getDifference function.
	float nw = nd / 7; //Calculatimg the Number of Weeks.
	cout << "Number Of Days Person Has Lived :  " << nd << " Days " << endl;
	cout << "Number Of Weeks Person Has Lived : " << nw << " Weeks " <<  endl;

	system("pause");
	return 0;
}

void inputDate(Date &a) //Universal Function For inputing The Values.
{
	cout << "Date : ";
	cin >> a.d;
	cout << "\nMonth : ";
	cin >> a.m;
	cout << "\nyear : ";
	cin >> a.y;
}

int countLeapYears(Date d) //This function counts The Number Of leap Years Before the Given Date 
{
	int years = d.y;

	//check if the current year needs to be considered for the count of leap year or not
	if (d.m <= 2)
		years--;

	//Calculating the Number of leap years 
	int nlpy = ( (years / 4) + (years / 400) - (years / 100) );

	return nlpy;
}

int getDifference(Date Bdate,Date Cdate)
{
	//count total Number Of Days Before Bdate
	long int n1 = ( (Bdate.y * 365) + Bdate.d );
	for (int i = 0; i < Bdate.m - 1; i++)
		n1 += MonthDays[i];

	//since every leap year is of 366 days add a day for every leap year
	n1 += countLeapYears(Bdate);

	//Similarly Count total Number Of Days For Cdate.


	long int n2 = Cdate.y * 365 + Cdate.d;
	for (int i = 0; i<Cdate.m - 1; i++)
		n2 += MonthDays[i];
	n2 += countLeapYears(Cdate);

	return (n2 - n1);
}