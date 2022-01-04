/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
string
###End banned keyword*/

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

struct DATE
{
    int day, month, year;
};
typedef struct STUDENT
{
    char id[11];
    char name[35];
    DATE dob;
    float math, phy, chem, aver;

} SV;

//###INSERT CODE HERE -
void inputArrayStudents(SV a[], int &n)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].id;
		cin.ignore();
		cin.getline(a[i].name, 35);
		cin >> a[i].dob.day >> a[i].dob.month >> a[i].dob.year;
		cin >> a[i].math >> a[i].phy >> a[i].chem;
		a[i].aver = (a[i].math + a[i].phy + a[i].chem) / 3;
	}
}

void outputStudent(SV a)
{
	cout << a.id << "\t|" << a.name << "\t|";
	cout << a.dob.day << "/" << a.dob.month << "/" << a.dob.year << "\t|";
	cout << a.math << "\t|" << a.phy << "\t|" << a.chem << "\t|" << a.aver << '\n';
}

int findStudent(SV a[], int n, char name[])
{
	for (int i = 0; i < n; i++)
		if (strcmp(a[i].name, name) == 0)
			return i;
	return -1;
}

int main()
{
    STUDENT a[100];
    int n,i;
    char name[35];

    inputArrayStudents(a,n);

    cout<<"\nFind a student with name: ";
    cin.ignore();
    cin.getline(name,35);
    i = findStudent(a,n,name);
   if(i==-1) cout<<"\nNo Found.";
   else
   {
        cout<<"\nID\t|Fullname\t|Date of birth\t|Maths\t|Phys\t|Chemis\t|Average score\n";
        outputStudent(a[i]);
    }

    return 0;
}

