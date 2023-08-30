#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <regex>

using namespace std;

// Email Validation Pattern
bool Emailcheck(string email)
{
    //Regular expressions are a generalised way to match patterns with sequences of characters
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, pattern);
}

//Creating a class Student to store Student details
class student
{
    //Defining private variables of the class Student
    private:

        string comp_name, comp_id, name, enroll_no, course, address, email_id, comp_type, comp_address, comp_email;
        long long int contact_no;
        float cgpa, salary;


    //Forward Declaration of some important functions used ahead
    public:

        //This function displays the Main Menu of the TPCMS program. It allows user to choose from various services
        void menu();

        //This function is used to Add Student Details
        void insert();

        //This function Displays the data of the Students
        void display();

        //This function Modifies the details of the Students
        void modify();

        //This function searches for the Student Data from the Student Record
        void search();

        //This function deletes the Student Data from Record
        void deleted();

        //This function displays the login window which can be used to access the TPCMS Software using correct set of username and password.
        void login();

        //This function Adds Company Details to the Record
        void add_comp();

        //This Function Displays Company Details from the Record
        void dis_comp();

        //This Function Checks the Eligibility Criteria of the user
        void eligibility();

};


//Defining function login() which was already declared in class Student
//This function displays the login window which can be used to access the TPCMS Software using correct set of username and password.
void student::login()
{
    //Defining some variables that can be used further in the program
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];

    //By default we have kept the username as "user" and password as "pass"
    char user[10]="user";
    char pass[10]="pass";

    //Initiating the do-while loop
    do
    {

        //Taking Username and Password inputs from the user
        cout << "\n\n\n\t\tLOGIN WINDOW\t\t";
        cout << "\n\nEnter Username: ";
        cin>>uname;
        cout << "\nEnter Password: ";

        //Creating a small loop to hide the password characters being entered by the user for confidential reasons
        while(i<10)
        {
            pword[i]=getch();
            c=pword[i];

            if(c==13)
            {
                break;
            }

            else
            {
                cout << "*";
            }
            i++;
        }

        pword[i]='\0';

        i=0;

        //Checking if the username and password entered by the user matches the username and password in the database
        if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
        {

            //Displaying Project Title
            cout << "\n\n\nLogin was Successful!\n\n";
            cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
            cout<<"\n\t\t\tWelcome to Training and Placement Cell Management System!!\n";
            cout<<"\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
            cout << "\n\n\nPress any key to continue...";

            //Holding the screen to provide realism to the project
            getch();
            break;
        }

        else
        {
            cout << "\nSorry!! Login was Unsuccessful!\nPlease try again...";
            a++;

            //Holding the screen to provide realism to the project
            getch();

        }
    }
	while(a<=2);

    //Creating an if-else statement if usuccessful login attempts exceeds 2 times
    if (a>2)
	{

        //Creating a try-catch block to end the program if usuccessful login attempts exceeds 2 times
        try
        {
            cout << "\nSorry you have entered the wrong username and password for 3 times!!!";
            getch();

            //throwing int type
            throw 1;
        }

        //Creating a Catch block to retrieve int datatype thrown by try block
        catch(int i)
        {
            cout << "\n\n";
            cout << "Thank you for using our software!\n";
            cout << "Exiting the program...";
            cout << "\n\n";

            //Holding the screen to provide realism to the project
            getch();

            //exit() function terminates the program
            exit(0);
        }
	}

    //Clearing the screen for user to avoid confusion
	system("cls");
}


//Defining function menu() which was already declared in class Student
//This function displays the Main Menu of the TPCMS program. It allows user to choose from various services
void student::menu()
{

//Initialising Label 1
menustart:

    //Defining variables used further in the program
    int choice;
    char x;

    //Clearing the screen for user to avoid confusion
    system("cls");

    //Menu Options
    cout << "\t\t\t -----------------------------------------------";
    cout<<"\n";
    cout << "\t\t\t| TRAINING AND PLACEMENT CELL MANAGEMENT SYSTEM |";
    cout<<"\n";
    cout << "\t\t\t -----------------------------------------------";
    cout<<"\n";
    cout << "\t\t\t| 1. Enter Student Record                       |";
    cout<<"\n";
    cout << "\t\t\t| 2. Display Student Record                     |";
    cout<<"\n";
    cout << "\t\t\t| 3. Modify Student Record                      |";
    cout<<"\n";
    cout << "\t\t\t| 4. Search Student Record                      |";
    cout<<"\n";
    cout << "\t\t\t| 5. Delete Student Record                      |";
    cout<<"\n";
    cout << "\t\t\t| 6. Enter New Recruiters Details               |";
    cout<<"\n";
    cout << "\t\t\t| 7. Display Recruiters Record                  |";
    cout<<"\n";
    cout << "\t\t\t| 8. Recruiters for you                         |";
    cout<<"\n";
    cout << "\t\t\t| 9. Exit                                       |";
    cout<<"\n";

    //Input choice from the user 
    cout << "\t\t\t ...........................................................................";
    cout << "\n";
    cout << "\t\t\t|Choose Option from the Menu corresponding to the Service you want to access|";
    cout << "\n";
    cout << "\t\t\t ...........................................................................";
    cout << "\n\n";
    cout << " Enter Your Choice: ";
    cin >> choice;

    //Initiating SwitchCase command
    switch (choice)
    {
        case 1:

            //Initialising Do-While command to take inputs until the user denies
            do
            {
                insert();
                cout << "\n\n\t\t\t Add Another Student Record (Y, N) : ";
                cin >> x;
            } 
            while (x == 'y' || x == 'Y');
            break;


        case 2:

            display();
            break;


        case 3:

            modify();
            break;


        case 4:

            search();
            break;


        case 5:

            deleted();
            break;


        case 6:

            //Initialising Do-While command to take inputs until the user denies
            do
            {
                add_comp();
                cout << "\n\n\t\t\t Add Another Recruiter Record (Y, N) : ";
                    cin >> x;
                } 
                while (x == 'y' || x == 'Y');
                break;


        case 7:

            dis_comp();
            getchar();
            break;


        case 8:

            eligibility();
            break;


        case 9:

            cout << "\n\t\t\t Exiting the Program........";
            cout << "\n";
            cout << "\n\t\t\t Closing the Training and Placement Cell Management System.......";
            cout << "\n\t\t\t Thank you for Using our Software!";
            cout << "\n\t\t\t Have a great day! :D";
            cout << "\n\n";

            //exit() function terminates the program
            exit(0);

        //Default switchcase is enabled when the corresponding case is not found
        default:

            cout << "\n\n\t\t\t Invalid Choice... Please Try Again...";

    }

    //Holding the screen to provide realism to the project
    getch();

    //Takes the program back to Label 1
    goto menustart;
}


//Defining function insert() which was already declared in class Student
//This function is used to Add Student Details
void student::insert()
{
    //Clearing the screen for user to avoid confusion
    system("cls");
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Add Student Details ---------------------------------------------" << endl;
    cout << "\t\t\tEnter Name: ";
    cin >> name;
    cout << "\t\t\tEnter Enrollment No.: ";
    cin >> enroll_no;
    cout << "\t\t\tEnter Course: ";
    cin >> course;

//Initialising Label 2
email:
    cout << "\t\t\tEnter Email Id : (Example: name@gmail.com) : ";
    cin >> email_id;

    //Calling Emailcheck() Function to verify if the email ID is correct or not
    if (Emailcheck(email_id))
    {
        cout << "\t\t\t Your Email-Id is Valid" << endl;
    }

    else
    {
        cout << "\t\t\t Your Email-Id is InValid" << endl;

        //Takes the program back to Label 2
        goto email;
    }

//Initialising Label 3
contact:
    cout << "\t\t\tEnter Contact No: (Example: 9639xxxxxx) : ";
    cin >> contact_no;
    if (contact_no < 1000000000 || contact_no > 9999999999)
    {
        cout << "\t\t\t Please Enter Only 10 Digits..." << endl;

        //Takes the program back to Label 3
        goto contact;
    }

    cout << "\t\t\tEnter Address: ";
    cin >> address;

    //open() function opens the file to be read, write or appended
    file.open("studentRecord.txt", ios::app | ios::out);
    file << " " << name << " " << enroll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";

    //close() closes the file and flushes all the buffered data
    file.close();
}


//Defining function display() which was already declared in class Student
//This function Displays the data of the Students
void student::display() // Display data of student
{
    //Clearing the screen for user to avoid confusion
    system("cls");
    fstream file;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Record Table --------------------------------------------" << endl;

    //open() function opens the file to be read, write or appended
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tData Not Present!";

        //close() closes the file and flushes all the buffered data
        file.close();
    }

    else
    {
        file >> name >> enroll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            cout << "\n\n\t\t\tStudent No.: " << total++;
            cout << "\n";
            cout << "\t\t\tName: " << name;
            cout << "\n";
            cout << "\t\t\tEnrollment No.: " << enroll_no;
            cout << "\n";
            cout << "\t\t\tCourse: " << course;
            cout << "\n";
            cout << "\t\t\tEmail Id: " << email_id;
            cout << "\n";
            cout << "\t\t\tContact No.: " << contact_no;
            cout << "\n";
            cout << "\t\t\tAddress: " << address;
            cout << "\n";
            file >> name >> enroll_no >> course >> email_id >> contact_no >> address;
        }

        if (total == 0)
        {

            cout << "\n\t\t\tData Not Present!" << endl;
        }
    }

    //close() closes the file and flushes all the buffered data
    file.close();
}


//Defining function modify() which was already declared in class Student
//This function Modifies the details of the Students
void student::modify() 
{
    //Clearing the screen for user to avoid confusion
    system("cls");
    fstream file, file1;
    string enrollno;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Modify Details ------------------------------------------" << endl;

    //open() function opens the file to be read, write or appended
    file.open("studentRecord.txt", ios::in);

    if (!file)
    {
        cout << "\n\t\t\tData Not Present!";

        //close() closes the file and flushes all the buffered data
        file.close();
    }

    else
    {
        cout << "\nEnter Enrollment No. of Student which you want to Modify: ";
        cin >> enrollno;

        //open() function opens the file to be read, write or appended
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> enroll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {

            //Checking if the enrollment number entered by the user is same as the one in the file
            if (enrollno != enroll_no)
                file1 << " " << name << " " << enroll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            
            else
            {
                cout << "\n\t\t\tEnter Name: ";
                cin >> name;
                cout << "\t\t\tEnter Enrollment No.: ";
                cin >> enroll_no;
                cout << "\t\t\tEnter Course: ";
                cin >> course;

            //Initialising Label 4
            email:
                cout << "\t\t\tEnter Email Id(name@gmail.com): ";
                cin >> email_id;

                if (Emailcheck(email_id))
                {
                    cout << "\t\t\t Your Email-Id is Valid" << endl;
                }

                else
                {
                    cout << "\t\t\t Your Email-Id is InValid" << endl;

                    //Takes the program back to Label 4
                    goto email;
                }

            //Initialising Label 5
            contact:
                cout << "\t\t\tEnter Contact No(9639xxxxxx): ";
                cin >> contact_no;
                if (contact_no < 1000000000 || contact_no > 9999999999)
                {
                    cout << "\t\t\t Please Enter Only 10 Digits..." << endl;

                    //Takes the program back to Label 5
                    goto contact;
                }

                cout << "\t\t\tEnter Address: ";
                cin >> address;
                file1 << " " << name << " " << enroll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
                found++;
            }

            file >> name >> enroll_no >> course >> email_id >> contact_no >> address;
        }

        if (found == 0)
        {
            cout << "\n\n\t\t\t Student Enrollment No. Not Found....";
        }

        //close() closes the file and flushes all the buffered data
        file1.close();
        file.close();

        //remove() function deletes the file
        remove("studentRecord.txt");

        //rename() function renames the file
        rename("record.txt", "studentRecord.txt");
    }
}


//Defining function search() which was already declared in class Student
//This function searches for the Student Data from the Student Record
void student::search()
{
    //Clearing the screen for user to avoid confusion
    system("cls");
    fstream file;
    int found = 0;

    //open() function opens the file to be read, write or appended
    file.open("studentRecord.txt", ios::in);

    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data --------------------------------------------" << endl;
        cout << "\n\t\t\tData Not Present!" << endl;
    }

    else
    {
        string enrollno;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Table --------------------------------------------" << endl;
        cout << "\nEnter Enrollment No. of Student which you want to search: ";
        cin >> enrollno;
        file >> name >> enroll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (enrollno == enroll_no)
            {
                cout << "\n\n\t\t\tName: " << name << "\n";
                cout << "\t\t\tRoll No.: " << enroll_no << "\n";
                cout << "\t\t\tCourse: " << course << "\n";
                cout << "\t\t\tEmail Id: " << email_id << "\n";
                cout << "\t\t\tContact No.: " << contact_no << "\n";
                cout << "\t\t\tAddress: " << address << "\n";
                found++;
            }
            file >> name >> enroll_no >> course >> email_id >> contact_no >> address;
        }

        if (found == 0)
            {
                cout << "\n\t\t\t Student Enrollment No. Not Found....";
            }

        //close() closes the file and flushes all the buffered data
        file.close();
    }
}


//Defining function deleted() which was already declared in class Student
//This function deletes the Student Data from Record
void student::deleted()
{
    //Clearing the screen for user to avoid confusion
    system("cls");
    fstream file, file1;
    int found = 0;
    string roll;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Student Details ------------------------------------------" << endl;

    //open() function opens the file to be read, write or appended
    file.open("studentRecord.txt", ios::in);

    if (!file)
    {
        cout << "\n\t\t\tData Not Present!";

        //close() closes the file and flushes all the buffered data
        file.close();
    }

    else
    {
        cout << "\nEnter Enrollment No. of Student whose Data needs to be Deleted from the Record: ";
        cin >> roll;

        //open() function opens the file to be read, write or appended
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> enroll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (roll != enroll_no)
            {
                file1 << " " << name << " " << enroll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            }

            else
            {
                found++;
                cout << "\n\t\t\tData Deleted Successfully!";
            }
            file >> name >> enroll_no >> course >> email_id >> contact_no >> address;
        }

        if (found == 0)
        {
            cout << "\n\t\t\t Student Enrollment NO. Not Found....";
        }

        //close() closes the file and flushes all the buffered data
        file1.close();
        file.close();

        //remove() function deletes the file
        remove("studentRecord.txt");

        //rename() function renames the file
        rename("record.txt", "studentRecord.txt");
    }
}


//Defining function add_comp() which was already declared in class Student
//This function Adds Company Details to the Record
void student::add_comp()
{
    //Clearing the screen for user to avoid confusion
    system("cls");
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Add Company Details ---------------------------------------------" << endl;
    cout << "\t\t\tEnter Name: ";
    cin >> comp_name;
    cout << "\t\t\tEnter Company ID.: ";
    cin >> comp_id;
    cout << "\t\t\tEnter Company Type: ";
    cin >> comp_type;
    cout << "\t\t\tEnter CGPA requirement: ";
    cin >> cgpa;

//Initialising Label 6
email:
    cout << "\t\t\tEnter Email Id(name@gmail.com): ";
    cin >> comp_email;

    if (Emailcheck(comp_email))
    {
        cout << "\t\t\t Your Email-Id is Valid" << endl;
    }

    else
    {
        cout << "\t\t\t Your Email-Id is InValid" << endl;

        //Takes the program back to Label 6
        goto email;
    }

    /* cout << "\t\t\tEnter Address: ";
    cin >> comp_address; */

    //open() function opens the file to be read, write or appended
    file.open("CompanyRecord.txt", ios::app | ios::out);
    file << " " << comp_name << " " << comp_id << " " << comp_type << " " << cgpa << " " << comp_email << " " << /* comp_address << */ "\n";

    //close() closes the file and flushes all the buffered data
    file.close();
}

//Defining function dis_comp() which was already declared in class Student
//This Function Displays Company Details from the Record
void student::dis_comp()
{
    //Clearing the screen for user to avoid confusion
    system("cls");
    fstream file;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Company Record Table --------------------------------------------" << endl;

    //open() function opens the file to be read, write or appended
    file.open("CompanyRecord.txt", ios::in);

    if (!file)
    {
        cout << "\n\t\t\tData not Present!";

        //close() closes the file and flushes all the buffered data
        file.close();
    }

    else
    {
        file >> comp_name >> comp_id >> comp_type >> cgpa >> comp_email /* >> comp_address */;
        while (!file.eof())
        {
            cout << "\n\n\t\t\tCompanies No.: " << total++;
            cout<<endl;
            cout << "\t\t\tRecruiter's Name: " << comp_name;
            cout<<"\n";
            cout << "\t\t\tRecruiter ID.: " << comp_id;
            cout<<"\n";
            cout << "\t\t\tCourse Type: " << comp_type;
            cout<<"\n";
            cout << "\t\t\tCGPA Requirements: " << cgpa;
            cout<<"\n";
            cout << "\t\t\tEmail Id: " << comp_email;
            cout<<"\n";
            /* cout << "\t\t\tAddress: " << comp_address;
            cout<<"\n"; */
            file >> comp_name >> comp_id >> comp_type >> cgpa >> comp_email /* >> comp_address */;
            getchar();
        }

        if (total == 0)
        {

            cout << "\n\t\t\tData Not Present!" << endl;
        }
    }

    //close() closes the file and flushes all the buffered data
    file.close();
}


//Defining function eligibility() which was already declared in class Student
//This Function Checks the Eligibility Criteria of the user
void student::eligibility()
{
    //Clearing the screen for user to avoid confusion
    system("cls");
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Eligibility Criteria --------------------------------------------\n" << endl;
    cout << "\t\t\tEnter CGPA: ";
    cin >> cgpa;

    if (cgpa >= 6 && cgpa < 7)
    {
        fstream file;
        int total = 1;

        //open() function opens the file to be read, write or appended
        file.open("six_seven_cg.txt", ios::in);

        if (!file)
        {
            cout << "\n\t\t\tData Not Present!";

            //close() closes the file and flushes all the buffered data
            file.close();
        }

        else
        {
            file >> comp_name >> comp_type >> comp_email >> /* comp_address >> */ salary;
            while(!file.eof())
            {
                cout << "\n\n\t\t\tCompanies No.: " << total++;
                cout<<endl;
                cout << "\t\t\tRecruiter's Name: " << comp_name;
                cout<<"\n";
                cout << "\t\t\tJob Type: " << comp_type;
                cout<<"\n";
                cout << "\t\t\tEmail Id: " << comp_email;
                cout<<"\n";
                /* cout << "\t\t\tAddress: " << comp_address;
                cout<<"\n"; */
                cout << "\t\t\tSalary: " << salary;
                cout<<"\n";
                file >> comp_name >> comp_type >> comp_email >> /* comp_address >> */ salary;
                getchar();
            }
        }

        //close() closes the file and flushes all the buffered data
        file.close();
    }

    else if (cgpa >=7 && cgpa < 8)
    {
        fstream file;
        int total = 1;

        //open() function opens the file to be read, write or appended
        file.open("seven_eight_cg.txt", ios::in);

        if (!file)
        {
            cout << "\n\t\t\tData Not Present!";

            //close() closes the file and flushes all the buffered data
            file.close();
        }

        else
        {
            file >> comp_name >> comp_type >> comp_email >> /* comp_address >> */ salary;
            while(!file.eof())
            {
                cout << "\n\n\t\t\tCompanies No.: " << total++;
                cout<<endl;
                cout << "\t\t\tRecruiter's Name: " << comp_name;
                cout<<"\n";
                cout << "\t\t\tJob Type: " << comp_type;
                cout<<"\n";
                cout << "\t\t\tEmail Id: " << comp_email;
                cout<<"\n";
                /* cout << "\t\t\tAddress: " << comp_address;
                cout<<"\n"; */
                cout << "\t\t\tSalary: " << salary;
                cout<<"\n";
                file >> comp_name >> comp_type >> comp_email >> /* comp_address >> */ salary;
                getchar();
            }
        }

        //close() closes the file and flushes all the buffered data
        file.close();
    }

    else if (cgpa >= 8 && cgpa < 10)
    {
        fstream file;
        int total = 1;

        //open() function opens the file to be read, write or appended
        file.open("eightnmorecg.txt", ios::in);

        if (!file)
        {
            cout << "\n\t\t\tData Not Present!";

            //close() closes the file and flushes all the buffered data
            file.close();
        }

        else
        {
            file >> comp_name >> comp_type >> comp_email >> /* comp_address >> */ salary;
            while(!file.eof())
            {
                cout << "\n\n\t\t\tCompanies No.: " << total++;
                cout<<endl;
                cout << "\t\t\tRecruiter's Name: " << comp_name;
                cout<<"\n";
                cout << "\t\t\tJob Type: " << comp_type;
                cout<<"\n";
                cout << "\t\t\tEmail Id: " << comp_email;
                cout<<"\n";
                /* cout << "\t\t\tAddress: " << comp_address;
                cout<<"\n"; */
                cout << "\t\t\tSalary: " << salary;
                cout<<"\n";
                file >> comp_name >> comp_type >> comp_email >> /* comp_address >>  */salary;
                getchar();
            }
        }

        //close() closes the file and flushes all the buffered data
        file.close();
    }

    else
    {
        cout << "\t\t\tCotact TNP Sir.\n" << endl;
    }
}


//Main function
int main()
{
    //Adds colours to the Output Window to make it more appealing
    system("Color B5");

    //Creates an object named project of type class Student
    student project;

    //Calling login() function using object project
    project.login();

    //Calling men() function using object project
    project.menu();
    return 0;
}

