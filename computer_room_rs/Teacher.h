//
// Created by Violet on 24-10-21.
//

#ifndef COMPUTER_ROOM_RS_TEACHER_H
#define COMPUTER_ROOM_RS_TEACHER_H

#include "Identification.h"
#include "Oder_File.h"
#include <iomanip>

class Teacher: public Identification
{
public:
    int m_id = 0;

    Teacher() = default;
    Teacher(int id, string & name, string & code);
    void operation_menu() override;
    static void show_all_order();
    static void check_order();
    ~Teacher() = default;
};

#endif //COMPUTER_ROOM_RS_TEACHER_H
