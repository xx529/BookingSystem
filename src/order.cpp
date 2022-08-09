#include <string>
#include <fstream>
#include "../h/order.h"

Order::Order()
{
    string order_file;
    order_file = DATA_PATH;
    order_file += ORDER_FILE;
    
    ifstream ifs;
    ifs.open(order_file, ios::in);
        
    string date;
    string interval;
    string stuId;
    string stuName;
    string roomId;
    string state;
    
    this->order_size = 0;
    
    while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> state)
    {
        string key;
        string value;
        map<string, string> m;
        
        int pos;
        
        pos = date.find(":");
        if (pos != -1)
        {
            key = date.substr(0, pos);
            value = date.substr(pos + 1, date.size() - pos);
            m.insert(make_pair(key, value));
            
        }
        
        pos = interval.find(":");
        if (pos != -1)
        {
            key = interval.substr(0, pos);
            value = interval.substr(pos + 1, interval.size() - pos);
            m.insert(make_pair(key, value));
            
        }
        
        pos = stuId.find(":");
        if (pos != -1)
        {
            key = stuId.substr(0, pos);
            value = stuId.substr(pos + 1, stuId.size() - pos);
            m.insert(make_pair(key, value));
            
        }
        
        pos = stuName.find(":");
        if (pos != -1)
        {
            key = stuName.substr(0, pos);
            value = stuName.substr(pos + 1, stuName.size() - pos);
            m.insert(make_pair(key, value));
        }
        
        pos = roomId.find(":");
        if (pos != -1)
        {
            key = roomId.substr(0, pos);
            value = roomId.substr(pos + 1, roomId.size() - pos);
            m.insert(make_pair(key, value));
        }
        
        pos = state.find(":");
        if (pos != -1)
        {
            key = state.substr(0, pos);
            value = state.substr(pos + 1, state.size() - pos);
            m.insert(make_pair(key, value));
        }
        
        this->m_orderData.insert(make_pair(this->order_size, m));
        this->order_size++;
        
    }
}

void Order::updateOrder()
{
    if (this->order_size == 0)
    {
        return;
    }
    
    string order_file;
    order_file = DATA_PATH;
    order_file += ORDER_FILE;
    
    ofstream ofs(order_file, ios::out | ios::trunc);
    for (int i=0; i < this->order_size; i++)
    {
        ofs << "date:" << this->m_orderData[i]["date"] << " ";
        ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
        ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
        ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
        ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
        ofs << "state:" << this->m_orderData[i]["state"] << endl;
    }
    
    ofs.close();
}