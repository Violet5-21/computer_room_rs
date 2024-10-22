//
// Created by Violet on 24-10-21.
//

#ifndef COMPUTER_ROOM_RS_IDENTIFICATION_H
#define COMPUTER_ROOM_RS_IDENTIFICATION_H

#include <iostream>
#include <string>

using namespace std;

class Identification
{
public:
    string m_name;
    string m_code;

    virtual void operation_menu() = 0;
    virtual ~Identification() = default;
};

#endif //COMPUTER_ROOM_RS_IDENTIFICATION_H
