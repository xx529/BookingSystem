#include "../h/manager.h"
#include "../h/file.h"
#include "../h/student.h"
#include "../h/teacher.h"
#include <string>
#include <fstream>

Manager::Manager()
{
    
}

Manager::Manager(string name, string pwd)
{
    this->name = name;
    this->pwd = pwd;
    this->initVector();
}

void Manager::menu()
{
    cout << endl;
    cout << "****************** " << this->name << " *********************" << endl;
    cout << endl;
    cout << "         ### Select Your Choice ###           " << endl;
    cout << "         --------------------------           " << endl;
    cout << "         ##  1. Add Person       ##           " << endl;
    cout << "         ##  2. Show Person      ##           " << endl;
    cout << "         ##  3. Show Computer    ##           " << endl;
    cout << "         ##  4. Clean File       ##           " << endl;
    cout << "         ##                      ##           " << endl;
    cout << "         ##  Any Key To Quit     ##           " << endl;
    cout << "         --------------------------           " << endl;
    cout << "              select number: ";
}

void Manager::addPerson()
{
    cout << "select type" << endl;
    cout << "1. student" << endl;
    cout << "2. teacher" << endl;
    
    string filename;
    string tip;
    ofstream ofs;
    
    int select = 0;
    cin >> select;
    
    if (select == 1)
    {
        filename = DATA_PATH;
        filename += STUDENT_FILE;
        tip = "your stdent number: ";
    }
    
    else if (select == 2)
    {
        filename = DATA_PATH;
        filename += TEACHER_FILE;
        tip = "your teacher number: ";
    }
    
    ofs.open(filename, ios::out | ios::app);
    int id;
    string name;
    string pwd;
    
    cout << tip << endl;
    cin >> id;
    
    cout << "your name: " << endl;
    cin >> name;
    
    cout << "your password: " << endl;
    cin >> pwd;
    
    ofs << id << " " << name << " " << pwd << " " << endl;
    system("clear");
    cout << "add ok" << endl;
    
    ofs.close();
}

void Manager::showPerson()
{
    cout << "showP" << endl;
}

void Manager::showComputer()
{
    cout << "showC" << endl;
}

void Manager::cleanFile()
{
    cout << "clean" << endl;
}

void Manager::initVector()
{
    ifstream ifs;
    
    string student_file;
    student_file = DATA_PATH;
    student_file += STUDENT_FILE;
    ifs.open(student_file, ios::in);
    
    if (!ifs.is_open())
    {
        cout << "fail to load student file" << endl;
        return;
    }
    
    this->vStudent.clear();
    
    Student s;
    while (ifs >> s.m_Id && ifs >> s.name && ifs >> s.pwd)
    {
        this->vStudent.push_back(s);
    }
    
    cout << "num of student: " << this->vStudent.size() << endl;
    ifs.close();
    
    
    string teacher_file;
    teacher_file = DATA_PATH;
    teacher_file += TEACHER_FILE;
    ifs.open(teacher_file, ios::in);
    
    if (!ifs.is_open())
    {
        cout << "fail to load teacher file" << endl;
        return;
    }
    
    this->vTeacher.clear();
    
    Teacher t;
    while (ifs >> t.m_empId && ifs >> t.name && ifs >> t.pwd)
    {
        this->vTeacher.push_back(t);
    }
    
    cout << "num of teacher: " << this->vTeacher.size() << endl;
    ifs.close();
    
}