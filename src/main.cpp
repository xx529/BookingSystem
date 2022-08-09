#include <iostream>
#include "../h/identity.h"
#include "../h/student.h"
#include "../h/teacher.h"
#include "../h/manager.h"
#include "../h/file.h"
#include <fstream>

using namespace std;

int welcome()
{
    cout << endl;
    cout << "******** Welcome To Booking System ********" << endl;
    cout << endl;
    cout << "         ### Select Your Choice ###           " << endl;
    cout << "         --------------------------           " << endl;
    cout << "         ##  1. Login As Student ##           " << endl;
    cout << "         ##  2. Login As Teacher ##           " << endl;
    cout << "         ##  3. Login As Admin   ##           " << endl;
    cout << "         ##  0. Quit             ##           " << endl;
    cout << "         --------------------------           " << endl;
    cout << "              select number: ";
    
    int select;
    cin >> select;
    cout << endl;
    system("clear");
    return select;
}

void printErr()
{
    cout << endl;
    cout << "     ----------------------------------" << endl;
    cout << "     ## bad imput, please try again! ##" << endl;
    cout << "     ----------------------------------" << endl;
}

void printBye()
{
    cout << endl;
    cout << "     ----------------------------------" << endl;
    cout << "     ##         Thanks, bye!         ##" << endl;
    cout << "     ----------------------------------" << endl;
}

void managerMenu(Indentity * &manager)
{
    while (true)
    {
        manager->menu();
        
        Manager * man = (Manager*) manager;
        
        int select = 0;
        
        cin >> select;
        system("clear");
        
        if (select == 1)
        {
            cout << "add person" << endl;
            man->addPerson();
        }
        
        else if (select == 2)
        {
            cout << "show person" << endl;
            man->showPerson();
        }
        
        else if (select == 3)
        {
            cout << "show computer" << endl;
            man->showComputerRoom();
        }
        
        else if (select == 4)
        {
            cout << "clean file" << endl;
            man->cleanFile();
        }
        
        else
        {
            delete manager;
            cout << "delete manager" << endl;
            return;
        }
    }
}

void studentMenu(Indentity * &student)
{
    while (true)
    {
        student->menu();
    
        Student * stu = (Student*) student;

        int select = 0;

        cin >> select;
        system("clear");

        if (select == 1)
        {
            cout << "apply order" << endl;
            stu->applyOrder();
        }

        else if (select == 2)
        {
            cout << "show my order" << endl;
            stu->showMyOrder();
        }

        else if (select == 3)
        {
            cout << "show all order" << endl;
            stu->showAllOrder();
        }

        else if (select == 4)
        {
            cout << "cancel order" << endl;
            stu->cancelOrder();
        }

        else
        {
            delete student;
            cout << "delete student" << endl;
            return;
        }
    }
    
    
}

void teacherMenu(Indentity * &teacher)
{
    while (true)
    {
        teacher->menu();
        
        Teacher * tea = (Teacher*) teacher;
        
        int select = 0;
        
        cin >> select;
        system("clear");
        
        if (select == 1)
        {
            cout << "show all order" << endl;
            tea->showAllOrder();
        }
        
        else if (select == 2)
        {
            cout << "valid order" << endl;
            tea->validOrder();
        }
        
        else
        {
            delete teacher;
            cout << "delete teacher" << endl;
            return;
        }
    }
}

void loginIn(string fileName, int type)
{
    Indentity *person = NULL;
    
    ifstream ifs;
    
    ifs.open(DATA_PATH + fileName, ios::in);
    
    if (!ifs.is_open())
    {
        cout << "file not exist !" << endl;
        ifs.close();
        return;
    }
    
    int id = 0;
    string name;
    string pwd;

    if (type == 1)
    {
        cout << "student login" << endl;
        cout << "your student number: ";
        cin >> id;
    }
    
    else if (type == 2)
    {
        cout << "teacher login" << endl;
        cout << "your teacher number: ";
        cin >> id;
    }
    
    else if (type == 3)
    {
        cout << "admin login" << endl;
    }
    
    cout << "your name: ";
    cin >> name;
    
    cout << "your password: ";
    cin >> pwd;
    
    if (type == 1)
    {
        int fid;
        string fname;
        string fpwd;
        
        while (ifs >> fid && ifs >> fname && ifs >> fpwd)
        {
            
            if (fid == id && fname == name && fpwd == pwd)
            {
                cout << "welcome comeback " << fname << endl;
                person = new Student(id, name, pwd);
                studentMenu(person);
                return;
            }
        }
        
        cout << "do not match any student" << endl;
    }
    
    else if (type == 2)
    {
       
        int fid;
        string fname;
        string fpwd;
        
        while (ifs >> fid && ifs >> fname && ifs >> fpwd)
        {
            
            if (fid == id && fname == name && fpwd == pwd)
            {
                cout << "welcome comeback " << fname << endl;
                person = new Teacher(id, name, pwd);
                teacherMenu(person);
                return;
            }
        }
        
        cout << "do not match any teacher" << endl;
    }
    
    else if (type == 3)
    {
        string fname;
        string fpwd;
        
        
        while (ifs >> fname && ifs >> fpwd)
        {
            
            if (fname == name && fpwd == pwd)
            {
                cout << "welcome comeback " << fname << endl;
                person = new Manager(name, pwd);
                managerMenu(person);
                return;
            }
        }
        
        cout << "do not match any manager" << endl;
    }
    
    cout << "fail to login" << endl;
    return;
}


int main()
{
    
    while (true)
    {

        int select = welcome();
        switch (select)
        {
            case 1:
                loginIn(STUDENT_FILE, 1);
                break;

            case 2:
                loginIn(TEACHER_FILE, 2);
                break;

            case 3:
                loginIn(ADMIN_FILE, 3);
                break;

            case 0:
                printBye();
                return 0;

            default:
                printErr();
                break;
        }
    }
    

    return 0;
}