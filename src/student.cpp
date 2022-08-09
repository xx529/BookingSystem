#include "../h/student.h"
#include "../h/room.h"
#include "../h/file.h"
#include "../h/order.h"
#include <fstream>
#include <vector>

Student::Student()
{
    
}
    
Student::Student(int id, string name, string pwd)
{
    this->m_Id = id;
    this->name = name;
    this->pwd = pwd;
    
    ifstream ifs;
    
    string room_file;
    room_file = DATA_PATH;
    room_file += ROOM_FILE;
    ifs.open(room_file, ios::in);
    
    Room r;
    
    while (ifs >> r.room_id && ifs >> r.room_size)
    {
        this->vRoom.push_back(r);
    }
    
    cout << "num of room: " << this->vRoom.size() << endl;
    ifs.close(); 
}

void Student::menu()
{
    cout << endl;
    cout << "****************** " << this->name << " *********************" << endl;
    cout << endl;
    cout << "         ### Select Your Choice ###           " << endl;
    cout << "         --------------------------           " << endl;
    cout << "         ##  1. Apply Order      ##           " << endl;
    cout << "         ##  2. Show My Order    ##           " << endl;
    cout << "         ##  3. Show All Order   ##           " << endl;
    cout << "         ##  4. Cancel Order     ##           " << endl;
    cout << "         ##                      ##           " << endl;
    cout << "         ##  Any Key To Quit     ##           " << endl;
    cout << "         --------------------------           " << endl;
    cout << "              select number: ";
}

void Student::applyOrder()
{
    cout << "only Monday to Friday can apply room" << endl;
    cout << "select your booking time" << endl;
    cout << "1. Monday" << endl;
    cout << "2. Tuesday" << endl;
    cout << "3. Wednesday" << endl;
    cout << "4. Thursday" << endl;
    cout << "5. Friday" << endl;
    
    int date = 0;
    
    while (true)
    {
        cin >> date;
        
        if (date >= 1 && date <=5)
        {
            break;
        }
        
        cout << "please select 1 to 5" << endl;
    }
    
    cout << "only can select AM or PM" << endl;
    cout << "1. AM" << endl;
    cout << "2. PM" << endl;
    
    int interval = 0;
    
    while (true)
    {
        cin >> interval;
        if (interval >=1 && interval <=2)
        {
            break;
        }
        
        cout << "please select 1 to 2" << endl;
    }
    
    cout << "select room" << endl;
    cout << "1. Room: " << this->vRoom[0].room_id << " size: " << this->vRoom[0].room_size << endl;
    cout << "2. Room: " << this->vRoom[1].room_id << " size: " << this->vRoom[1].room_size << endl;
    cout << "3. Room: " << this->vRoom[2].room_id << " size: " << this->vRoom[2].room_size << endl;
    
    int room = 0;
    
    while (true)
    {
        cin >> room;
        if (room >= 1 && room <= 3)
        {
            break;
        }
        
        cout << "please select 1 to 3";
    }
    
    
    string order_file;
    order_file = DATA_PATH;
    order_file += ORDER_FILE;
    ofstream ofs(order_file, ios::app);
    
    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "stuId:" << this->m_Id << " ";
    ofs << "stuName:" << this->name << " ";
    ofs << "roomId:" << room << " ";
    ofs << "state:" << 1 << endl;
    
    ofs.close();
    
    system("clear");
    
    cout << "succeed to apply, wait for permission" << endl;
    
}

void Student::showMyOrder()
{
    Order order;
    
    if (order.order_size == 0)
    {
        cout << "not any order record" << endl;
        return;
    }
    
    bool noRecord = true;
    
    for (int i=0; i < order.order_size; i++)
    {
        
        if (atoi(order.m_orderData[i]["stuId"].c_str()) == this->m_Id)
        {
            noRecord = false;
            
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
    
    if (noRecord)
    {
        cout << "empty" << endl;
    }
}

void Student::showAllOrder()
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

void Student::cancelOrder()
{
    Order order;
    
    if (order.order_size == 0)
    {
        cout << "not any order record" << endl;
        return;
    }
    
    cout << "only Ing or success can be canceled" << endl;
    
    vector <int> v;
    int index = 1;
    
    for (int i=0; i<order.order_size; i++)
    {
        if (atoi(order.m_orderData[i]["stuId"].c_str()) == this->m_Id)
        {
            if (order.m_orderData[i]["state"] == "1" || order.m_orderData[i]["state"] == "2")
            {
                v.push_back(i);
                cout << index++ << "、";

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
    }
        
    cout << "which record do you want to cancel, 0 mean turn back" << endl;
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
                order.m_orderData[v[select - 1]]["state"] = "0";
                order.updateOrder();
                cout << "cancel complete" << endl;
                break;
            }
        }
        
        cout << "wrong select, again" << endl;
        
    }
    
    
    
}