#pragma once
#include <iostream>
#include <string>
#include <map>
#include "./file.h"

using namespace std;

class Order
{
public:
    
    Order();
    
    void updateOrder();
    
    int order_size;
    
    map<int, map<string, string>> m_orderData;
    
};