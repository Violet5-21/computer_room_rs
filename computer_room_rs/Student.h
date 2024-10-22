//
// Created by Violet on 24-10-21.
//

#ifndef COMPUTER_ROOM_RS_STUDENT_H
#define COMPUTER_ROOM_RS_STUDENT_H

#include "Identification.h"
#include "computer_room.h"
#include <iomanip>
#include <vector>
#include "global_file.h"
#include "Oder_File.h"

class Student: public Identification
{
public:
    int m_id = 0;
    vector<Computer_Room> vCom;

    Student() = default;
    Student(int id, string & name, string & code);
    void operation_menu() override;
    void apply_odder();
    void show_odder() const;
    static void show_all_odder();
    void cancel_odder()const;
    ~Student() = default;
};

#endif //COMPUTER_ROOM_RS_STUDENT_H
