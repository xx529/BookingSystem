#pragma once
#include <iostream>
#include <string>
#include "./identity.h"
#include "./room.h"
#include <vector>

using namespace std;


class Student :public Indentity
{
public:

    Student();
    
    Student(int id, string name, string pwd);
    
    int m_Id;
    
    vector<Room> vRoom;
    
    virtual void menu();
    
    void applyOrder();
    
    void showMyOrder();
    
    void showAllOrder();
    
    void cancelOrder();
    
};