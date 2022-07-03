#pragma once
#include <iostream>
#include <string>
#define _CRT_SECURE_NO_WARING
#include "./identity.h"

using namespace std;

class Teacher :public Indentity
{
public:

    Teacher();
    
    Teacher(int empId, string name, string pwd);
    
    int m_empId;
    
    virtual void menu();
    
    void validOrder();
    
    void showAllOrder();
    
};