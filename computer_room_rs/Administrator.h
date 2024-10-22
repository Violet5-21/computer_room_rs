//
// Created by Violet on 24-10-21.
//

#ifndef COMPUTER_ROOM_RS_ADMINISTRATOR_H
#define COMPUTER_ROOM_RS_ADMINISTRATOR_H

#include "Identification.h"
#include "Teacher.h"
#include "Student.h"
#include <vector>
#include <iomanip>
#include <fstream>
#include "global_file.h"
#include "computer_room.h"

class Student;
class Teacher;

class Administrator: public Identification
{
private:
    vector<Student> vStu;
    vector<Teacher> vTea;
    vector<Computer_Room> vCom;
public:
    Administrator() = default;
    Administrator(const string & name, const string & code);
    void operation_menu() override;
    bool check_repeat(int id, int type);
    void add_person();
    void show_person();
    void show_computer();
    static void clean_file();
    void initiate_v();
    ~Administrator() = default;
};

#endif //COMPUTER_ROOM_RS_ADMINISTRATOR_H
