#include "../h/manager.h"
#include "../h/file.h"
#include "../h/student.h"
#include "../h/teacher.h"
#include "../h/room.h"
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
    string errmsg;
    ofstream ofs;
    
    int select = 0;
    cin >> select;
    
    if (select == 1)
    {
        filename = DATA_PATH;
        filename += STUDENT_FILE;
        tip = "your stdent number: ";
        errmsg = "student number repeated!";
    }
    
    else if (select == 2)
    {
        filename = DATA_PATH;
        filename += TEACHER_FILE;
        tip = "your teacher number: ";
        errmsg = "teacher number repeated!";
    }
    
    ofs.open(filename, ios::out | ios::app);
    int id;
    string name;
    string pwd;
    
    cout << tip << endl;
    
    while (true)
    {
        cin >> id;
        bool ret = this->checkRepeat(id, select);
        
        if (ret)
        {
            cout << errmsg << endl;
        }
        
        else
        {
            break;
        }
    }
    
    cout << "your name: " << endl;
    cin >> name;
    
    cout << "your password: " << endl;
    cin >> pwd;
    
    ofs << id << " " << name << " " << pwd << " " << endl;
    system("clear");
    cout << "add ok" << endl;
    
    ofs.close();
    
    this->initVector();
}

void Manager::showPerson()
{
    cout << "what do you want to be showed" << endl;
    
    while (true)
    {
        cout << "1. student" << endl;
        cout << "2. tescher" << endl;
        
        int select = 0;
        cin >> select;
        
        if (select == 1)
        {
            cout << "all the students" << endl;
            for (vector<Student>::iterator it = this->vStudent.begin(); it != this->vStudent.end(); it++)
            {
               cout << it->m_Id << " " << it->name << " " << it->pwd << endl;
            }
            break;

        }
    
       else if (select == 2)
        {
            cout << "all the teachers" << endl;
            for (vector<Teacher>::iterator it = this->vTeacher.begin(); it != this->vTeacher.end(); it++)
            {
                cout << it->m_empId << " " << it->name << " " << it->pwd << endl;
            }
           break;
        }
        
        else
        {
            cout << "bad choice, only 1 or 2 is accepted" << endl;
        }
    }
    
    
}

void Manager::showComputerRoom()
{
    for (vector<Room>::iterator it = this->vRoom.begin(); it != this->vRoom.end(); it++) 
    {
        cout << it->room_id << " " << it->room_size << endl;
    }
}

void Manager::cleanFile()
{   
    string order_file;
    order_file = DATA_PATH;
    order_file += ORDER_FILE;
        
    ofstream ofs(order_file, ios::trunc);
    ofs.close();
    
    cout << "clear file ok" << endl;
    
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
    
    
    string room_file;
    room_file = DATA_PATH;
    room_file += ROOM_FILE;
    ifs.open(room_file, ios::in);
    
    if (!ifs.is_open())
    {
        cout << "fail to load room file" << endl;
        return;
    }
    
    this->vRoom.clear();
    
    Room r;
    while (ifs >> r.room_id && ifs >> r.room_size)
    {
        this->vRoom.push_back(r);
    }
    
    cout << "num of room: " << this->vRoom.size() << endl;
    ifs.close(); 
}

bool Manager::checkRepeat(int id, int type)
{
    if (type == 1)
    {
        for (vector<Student>::iterator it = this->vStudent.begin(); it != this->vStudent.end(); it++)
        {
            if (id == it->m_Id)
            {
                return true;
            }
        }
    }
    
    else if (type == 2)
    {
        for (vector<Teacher>::iterator it = this->vTeacher.begin(); it != this->vTeacher.end(); it++)
        {
            if (id == it->m_empId)
            {
                return true;
            }
        }
    }
    
    return false;
}