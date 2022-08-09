#include "../h/teacher.h"
#include "../h/order.h"
#include <vector>

Teacher::Teacher()
{
    
}

Teacher::Teacher(int id, string name, string pwd)
{
    this->m_empId = id;
    this->name = name;
    this->pwd = pwd;
}

void Teacher::menu()
{
    cout << endl;
    cout << "****************** " << this->name << " *********************" << endl;
    cout << endl;
    cout << "         ### Select Your Choice ###           " << endl;
    cout << "         --------------------------           " << endl;
    cout << "         ##  1. Show All Order   ##           " << endl;
    cout << "         ##  2. Valid Order      ##           " << endl;
    cout << "         ##                      ##           " << endl;
    cout << "         ##  Any Key To Quit     ##           " << endl;
    cout << "         --------------------------           " << endl;
    cout << "              select number: ";
}

void Teacher::showAllOrder()
{
    Order order;
    
    if (order.order_size == 0)
    {
        cout << "not any order record" << endl;
        return;
    }
    
    for (int i=0; i < order.order_size; i++)
    {
        cout << "Student name: " << order.m_orderData[i]["stuName"] << " ";
        cout << "Student: number: " << order.m_orderData[i]["stuId"] << " ";
        cout << "Booking Date: " << order.m_orderData[i]["date"] << " ";
        cout << "interval: "<< (order.m_orderData[i]["interval"] == "1" ? "AM": "PM") << " ";
        cout << "roomId: "<< order.m_orderData[i]["roomId"] << " ";

        string state = "state: ";

        if (order.m_orderData[i]["state"] == "1")
        {
            state += "Ing";
        }

        else if (order.m_orderData[i]["state"] == "2")
        {
            state += "succeed";
        }

        else if (order.m_orderData[i]["state"] == "-1")
        {
            state += "fail";
        }

        else
        {
            state += "cancel";
        }

        cout << state << endl;
    }
}

void Teacher::validOrder()
{
    Order order;
    
    if (order.order_size == 0)
    {
        cout << "not any order record" << endl;
        return;
    }
    
    vector <int> v;
    int index = 1;
    
    cout << "only Ing can be valid" << endl;
    
    for (int i=0; i<order.order_size; i++)
    {
        if (order.m_orderData[i]["state"] == "1")
        {
            v.push_back(i);
            cout << index << " ";
            cout << "Booking Date: " << order.m_orderData[i]["date"] << " ";
            cout << "interval: "<< (order.m_orderData[i]["interval"] == "1" ? "AM": "PM") << " ";
            cout << "roomId: "<< order.m_orderData[i]["roomId"] << " ";
            cout << "state: Ing" << endl;
        }
    }
    
    cout << "which record do you want to valida, 0 mean turn back" << endl;
    int select = 0;
    
    while (true)
    {
        cin >> select;
        
        if (select >= 0 && select <= v.size())
        {
            if (select == 0)
            {
                break;
            }
            
            else
            {
                order.m_orderData[v[select - 1]]["state"] = "2";
                order.updateOrder();
                cout << "valida complete" << endl;
                break;
            }
        }
        
        cout << "wrong select, again" << endl;
        
    }
    
}