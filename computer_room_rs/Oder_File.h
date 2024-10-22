//
// Created by Violet on 24-10-22.
//

#ifndef COMPUTER_ROOM_RS_ODER_FILE_H
#define COMPUTER_ROOM_RS_ODER_FILE_H

#include <iostream>
#include <map>
#include "global_file.h"

using namespace std;

class Order_File
{
public:
    int m_size;
    map<int, map<string, string>> m_data;

    Order_File();
    void update();
    ~Order_File() = default;
};

#endif //COMPUTER_ROOM_RS_ODER_FILE_H
