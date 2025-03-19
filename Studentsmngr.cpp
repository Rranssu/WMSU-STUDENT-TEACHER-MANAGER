#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;
using std::string;
using std::system;

struct stdnt
{
    int id;
    float gpa;
    string fn;
    string ln;
    string crs;
};

const int mxstdnts = 100;
stdnt student[mxstdnts];
int mnid = 0;

void clearscreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void sortbyname(stdnt arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j].ln > arr[j + 1].ln)
            {
                stdnt temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sortbygpas(stdnt arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j].gpa < arr[j + 1].gpa)
            {
                stdnt temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void enrollstudent()
{
    clearscreen();

    if (mnid >= mxstdnts)
    {
        cout << "student limit reached cannot add more students\n";
        return;
    }

    int inputid;
    string mnfn, mnln, mncrs;
    float mngpa;

    cout << "enroll student\n\n";
    cout << "enter id: ";
    cin >> inputid;

    for (int i = 0; i < mnid; i++)
    {
        if (student[i].id == inputid)
        {
            cout << "cannot add an existing student\n";
            return;
        }
    }

    student[mnid].id = inputid;
    cout << "enter first name: ";
    cin >> mnfn;
    student[mnid].fn = mnfn;

    cout << "enter last name: ";
    cin >> mnln;
    student[mnid].ln = mnln;

    cout << "enter course: ";
    cin >> mncrs;
    student[mnid].crs = mncrs;

    cout << "enter gpa: ";
    cin >> mngpa;
    student[mnid].gpa = mngpa;

    cout << "student enrolled successfully\n";
    mnid++;
}

void removestudent()
{
    clearscreen();
    int removeid;
    cout << "enter the id to remove: ";
    cin >> removeid;

    for (int i = 0; i < mnid; i++)
    {
        if (student[i].id == removeid)
        {
            student[i] = student[mnid - 1];
            mnid--;
            cout << "student removed successfully\n";
            return;
        }
    }

    cout << "student not found\n";
}

void editstudent()
{
    clearscreen();
    int editid;
    cout << "enter id to edit: ";
    cin >> editid;

    for (int i = 0; i < mnid; i++)
    {
        if (student[i].id == editid)
        {
            cout << "edit student information\n";
            cout << "enter new first name: ";
            cin >> student[i].fn;
            cout << "enter new last name: ";
            cin >> student[i].ln;
            cout << "enter new course: ";
            cin >> student[i].crs;
            cout << "enter new gpa: ";
            cin >> student[i].gpa;
            cout << "student information updated successfully\n";
            return;
        }
    }

    cout << "student not found\n";
}

void viewsortedstudents(bool srtdbygpa)
{
    clearscreen();

    if (mnid == 0)
    {
        cout << "no students enrolled yet\n";
        return;
    }

    stdnt sortedstudents[mnid];
    for (int i = 0; i < mnid; i++)
    {
        sortedstudents[i] = student[i];
    }

    if (srtdbygpa)
    {
        sortbygpas(sortedstudents, mnid);
    }
    else
    {
        sortbyname(sortedstudents, mnid);
    }

    cout << "\nstudent list:\n";
    for (int i = 0; i < mnid; i++)
    {
        cout << "\nstudent information\n";
        cout << "id: " << sortedstudents[i].id << "\n";
        cout << "name: " << sortedstudents[i].fn << " " << sortedstudents[i].ln << "\n";
        cout << "course: " << sortedstudents[i].crs << "\n";
        cout << "gpa: " << sortedstudents[i].gpa << "\n";
    }
}

void viewstudent()
{
    clearscreen();
    int srtdchoice;
    cout << "view students by:\n";
    cout << "[1] alphabetically by last name\n";
    cout << "[2] highest to lowest gpa\n";
    cout << "choice: ";
    cin >> srtdchoice;

    if (srtdchoice == 1)
    {
        viewsortedstudents(false);
    }
    else if (srtdchoice == 2)
    {
        viewsortedstudents(true);
    }
    else
    {
        cout << "invalid choice returning to main menu\n";
    }
}

int main()
{
    bool end = false;
    int choice;

    do
    {
        clearscreen();
        cout << "\nwmsu student teacher manager\n";
        cout << "[1] enroll student\n";
        cout << "[2] remove student\n";
        cout << "[3] edit student information\n";
        cout << "[4] view student information\n";
        cout << "[5] exit program\n";
        cout << "choice: ";
        cin >> choice;

        if (choice == 1)
        {
            enrollstudent();
        }
        else if (choice == 2)
        {
            removestudent();
        }
        else if (choice == 3)
        {
            editstudent();
        }
        else if (choice == 4)
        {
            viewstudent();
        }
        else if (choice == 5)
        {
            end = true;
        }
        else
        {
            cout << "invalid choice please try again\n";
        }

        if (!end)
        {
            cout << "\npress enter to continue";
            cin.ignore();
            cin.get();
        }
    } while (!end);

    return 0;
}