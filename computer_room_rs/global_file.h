//
// Created by Violet on 24-10-21.
//

#ifndef COMPUTER_ROOM_RS_GLOBAL_FILE_H
#define COMPUTER_ROOM_RS_GLOBAL_FILE_H

#include "Identification.h"
#include "Student.h"
#include "Teacher.h"
#include "Administrator.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

const string STUDENT_FILE = "student.txt";
const string TEACHER_FILE = "teacher.txt";
const string ADMINISTRATOR_FILE = "administrator.txt";
const string COMPUTER_ROOM_FILE = "computer_room.txt";
const string ORDER_FILE = "order.txt";

void administrator_menu(Identification * &administrator);

void student_menu(Identification * &student);

void Teacher_menu(Identification * &teacher);

void log_in(const string & filename, int type);

#endif //COMPUTER_ROOM_RS_GLOBAL_FILE_H
