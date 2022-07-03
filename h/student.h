#pragma once
#include <iostream>
#include <string>
#include "./identity.h"

using namespace std;


class Student :public Indentity
{
public:

    Student();
    
    Student(int id, string name, string pwd);
    
    int m_Id;
    
    virtual void menu();
    
    void applyOrder();
    
    void showMyOrder();
    
    void showAllOrder();
    
    void cancelOrder();
    
};