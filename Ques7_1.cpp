/*
Create a structure student. Add three members: name, rollno, marks in five subjects. Create
constructor to initialize the values (non-parameterised and parameterised).Create functions
to getdata( ) to get the student details from the user, display() to display the results,
total_marks( )to display total marks scored by a student, max_marks ( ) and min_marks ( ) to
display the maximum and minimum marks secured by the student. Create another function
to display the marks secured by student in increasing order.
*/

#include<iostream>
#include<conio.h>

using namespace std;

class student 
{
	public:
		void getdata()
		{
			cout << "Enter name : " << endl;
			cin.getline(_name, 50);
			cout << "Enter Roll No. : " << endl;
			cin >> _rollno;
			cout << "Enter Marks of Maths,Science,SST,English,Hindi respectively : " << endl;
			for(int i=0;i<5;i++)
			cin >> _marks[i];
		}

		void display()
		{
			cout << "RESULT:" << endl;

			cout << "marks of all subs:" << endl;
			for (int i = 0; i < 5;i++)
				cout << _marks[i] << ",";

			cout << "\n\nTOTAL MARKS : " << total_marks() << endl;
			cout << "MIN MARKS : " << min_marks() << endl;
			cout << "MAX MARKS : " << max_marks() << endl;
				
			inc_marks();

			cout << "Marks in INC. order : " << endl;
			{
				for (int i = 0; i < 5; i++)
					cout << _marks[i] << ",";
			}


		}

	private:
		float total_marks()
		{
			return (_marks[0] + _marks[1] + _marks[2] + _marks[3] + _marks[4]);

		}
		float min_marks()
		{
			int max = 0, min = 100, sum = 0;

			for (int i = 0; i < 5; i++)
			{
				sum = sum + _marks[i];
				if (_marks[i] > max)
					max = _marks[i];
				if (_marks[i] < min)
					min = _marks[i];
			}

			return min;

		}

		float max_marks()
		{
			int max = 0, min = 100 , sum = 0;

			for (int i = 0; i < 5; i++)
			{
				sum = sum + _marks[i];
				if (_marks[i] > max)
					max = _marks[i];
				if (_marks[i] < min)
					min = _marks[i];
			}

			return max;

		}
		void inc_marks()
		{
			for (int i = 0; i <= 5; i++)
			{
				for (int j = 0; j <= 5 - i; j++)
				{
					if (_marks[j] > _marks[j + 1])
					{
						int temp = _marks[j];
						_marks[j] = _marks[j + 1];
						_marks[j + 1] = temp;
					}
				}

			}
		}
		char _name[50];
		int _rollno;
		int _marks[5];
};

int main()
{
	system("cls");

	student s;
	s.getdata();
	s.display();

	system("pause");
	return 0;
}