#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "./identity.h"
#include "./student.h"
#include "./teacher.h"
#include "./room.h"

using namespace std;

class Manager :public Indentity
{
public:

    Manager();
    
    Manager(string name, string pwd);
    
    virtual void menu();
    
    void addPerson();
    
    void showPerson();
    
    void showComputerRoom();
    
    void cleanFile();
    
    void initVector();
    
    vector<Student> vStudent;
    
    vector<Teacher> vTeacher;
    
    vector<Room> vRoom;
    
    bool checkRepeat(int id, int type);
    
};