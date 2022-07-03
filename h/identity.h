#pragma once
#include <iostream>
#include <string>

using namespace std;

class Indentity
{
public:
    virtual void menu() = 0;
    string name;
    string pwd;
};