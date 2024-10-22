//
// Created by Violet on 24-10-21.
//

#include "Administrator.h"

Administrator::Administrator(const string & name, const string & code)
{
    m_name = name;
    m_code = code;

    initiate_v();

    ifstream ifs(COMPUTER_ROOM_FILE);

    Computer_Room c;

    while (ifs >> c.m_computer_id && ifs >> c.m_capacity)
    {
        vCom.push_back(c);
    }
    cout << "The number of computer rooms is: " << vCom.size() << endl;

    ifs.close();
}

void Administrator::operation_menu()
{
    string welcome = " Welcome to the administrator! ";
    string action1 = " 1. Add account. ";
    string action2 = " 2. Check account. ";
    string action3 = " 3. Check computer room. ";
    string action4 = " 4. Clean reservation. ";
    string exit = " 0. Exit ";
    string reminder = " Please select your action: ";

    cout << setfill('=') << setw(50+static_cast<int>(welcome.size()/2)) << welcome
         << setw(50-static_cast<int>(welcome.size()/2)) << "\n";
    cout << "\t\t\t" << setfill('-') << setw(53) << "\n";
    cout << "\t\t\t|" << setfill(' ') << setw(52) << "|\n";
    cout << "\t\t\t|" << setw(26+static_cast<int>(action1.size()/2)) << action1
         << setw(26-static_cast<int>(action1.size()/2)) << "|\n";
    cout << "\t\t\t|" << setfill(' ') << setw(52) << "|\n";
    cout << "\t\t\t|" << setw(26+static_cast<int>(action2.size()/2)) << action2
         << setw(26-static_cast<int>(action2.size()/2)) << "|\n";
    cout << "\t\t\t|" << setfill(' ') << setw(52) << "|\n";
    cout << "\t\t\t|" << setw(26+static_cast<int>(action3.size()/2)) << action3
         << setw(26-static_cast<int>(action3.size()/2)) << "|\n";
    cout << "\t\t\t|" << setfill(' ') << setw(52) << "|\n";
    cout << "\t\t\t|" << setw(26+static_cast<int>(action4.size()/2)) << action4
         << setw(26-static_cast<int>(action4.size()/2)) << "|\n";
    cout << "\t\t\t|" << setfill(' ') << setw(52) << "|\n";
    cout << "\t\t\t|" << setw(26+static_cast<int>(exit.size()/2)) << exit
         << setw(26-static_cast<int>(exit.size()/2)) << "|\n";
    cout << "\t\t\t|" << setfill(' ') << setw(52) << "|\n";
    cout << "\t\t\t" << setfill('-') << setw(53) << "\n";
    cout << reminder << setfill(' ');
}

bool Administrator::check_repeat(int id, int type)
{
    if (type == 1)
    {
        for (const auto & i: vStu)
        {
            if (id == i.m_id)
            {
                return true;
            }
        }
    }
    else if (type == 2)
    {
        for (const auto & i: vTea)
        {
            if (id == i.m_id)
            {
                return true;
            }
        }
    }

    return false;
}

void Administrator::add_person()
{
    cout << "1. Add student. \n";
    cout << "2. Add teacher. \n";

    string tip;
    string error_tip;
    string file_name;
    ofstream ofs;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        file_name = STUDENT_FILE;
        tip = "Please enter school id: ";
        error_tip = "Duplicate student ID. \n";
    }
    else if (select == 2)
    {
        file_name = TEACHER_FILE;
        tip = "Please enter teacher id: ";
        error_tip = "Duplicate Teacher ID. \n";
    }

    ofs.open(file_name, ios_base::out | ios_base::app);
    int id;
    string name;
    string code;

    cout << tip;

    while (cin >> id)
    {
        if (this->check_repeat(id, select))
        {
            cout << error_tip << endl;
        }
        else
        {
            break;
        }
    }

    cout << "Please enter your name: ";
    cin >> name;

    cout << "Please enter your code: ";
    cin >> code;

    ofs << id << " " << name << " " << code;
    ofs.close();

    if (select == 1)
    {
        Student s(id, name, code);
        vStu.push_back(s);
    }
    else if (select == 2)
    {
        Teacher t(id, name, code);
        vTea.push_back(t);
    }
}

void Administrator::show_person()
{
    cout << "1. Students. \n";
    cout << "2. Teacher. \n";

    int select;
    if (cin >> select && select == 1)
    {
        cout << "The information is as follows. \n";
        for (const auto & i: vStu)
        {
            cout << "Student ID: " << i.m_id << "name: " << i.m_name << "code: " << i.m_code << endl;
        }
    }
    else if (cin >> select && select == 2)
    {
        for (const auto & i: vTea)
        {
            cout << "Teacher ID: " << i.m_id << "name: " << i.m_name << "code: " << i.m_code << endl;
        }
    }
}

void Administrator::show_computer()
{
    cout << "The information of computer rooms is as follows. \n";
    for (const auto & i: vCom)
    {
        cout << "Computer room ID: " << i.m_computer_id << " Computer room capacity: " << i.m_capacity << endl;
    }
}

void Administrator::clean_file()
{
    ofstream ofs(ORDER_FILE, ios_base::out | ios_base::trunc);
    ofs.close();

    cout << "Cleaned! \n";
}

void Administrator::initiate_v()
{
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios_base::in);
    if (!ifs.is_open())
    {
        cout << "Failed. \n";
        ifs.close();
    }
    else
    {
        vStu.clear();

        Student s;
        while (ifs >> s.m_id && ifs >> s.m_name && ifs >> m_code)
        {
            vStu.push_back(s);
        }
        cout << "The number of students so far: " << vStu.size() << endl;
        ifs.close();
    }

    ifs.open(TEACHER_FILE, ios_base::in);
    if (!ifs.is_open())
    {
        cout << "Failed. \n";
        ifs.close();
    }
    else
    {
        vTea.clear();

        Teacher s;
        while (ifs >> s.m_id && ifs >> s.m_name && ifs >> m_code)
        {
            vTea.push_back(s);
        }
        cout << "The number of students so far: " << vTea.size() << endl;
        ifs.close();
    }
}
