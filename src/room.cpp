#include <string>
#include <fstream>
#include "../h/room.h"

Room::Room()
{
    
}

Room::Room(int id, int size)
{
    this->room_id = id;
    this->room_size = size;
}