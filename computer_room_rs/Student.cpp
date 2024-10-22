//
// Created by Violet on 24-10-21.
//

#include "Student.h"

Student::Student(int id, string & name, string & code)
{
    m_id = id;
    m_name = name;
    m_code = code;

    ifstream ifs(COMPUTER_ROOM_FILE);

    Computer_Room c;
    while (ifs >> c.m_computer_id && ifs >> c.m_capacity)
    {
        vCom.push_back(c);
    }
    ifs.close();
}

void Student::operation_menu()
{
    string welcome = " Welcome to the student! ";
    string action1 = " 1. Apply for a reservation. ";
    string action2 = " 2. Check reservation. ";
    string action3 = " 3. Check all reservation. ";
    string action4 = " 4. Cancel reservation. ";
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

void Student::apply_odder()
{
    cout << "Computer rooms open from Monday to Friday. \n";
    cout << "Please enter the time you want to reserve. \n";
    cout << "1. Monday. \n";
    cout << "2. Tuesday. \n";
    cout << "3. Wednesday. \n";
    cout << "4. Thursday. \n";
    cout << "5. Friday. \n";

    int date, interval, room;

    while (cin >> date)
    {
        if (0 <= date && date <= 5)
        {
            cout << "Please enter morning or afternoon you want to reserve. \n";
            cout << "1: morning. \n";
            cout << "2: afternoon\n";
            if (cin >> interval && (interval == 1 || interval == 2))
            {
                cout << "Please enter the room number. \n";
                cout << "#1 capacity: " << vCom[0].m_capacity << endl;
                cout << "#2 capacity: " << vCom[1].m_capacity << endl;
                cout << "#3 capacity: " << vCom[2].m_capacity << endl;
                if (cin >> room && (room == 1 || room == 2 || room == 3))
                {
                    break;
                }
                else
                {
                    cout << "Wrong room. \n";
                    continue;
                }
            }
            else
            {
                cout << "Wrong interval! \n";
                continue;
            }
        }
        else
        {
            cout << "Wrong time! \n";
            continue;
        }
    }

    cout << "Reserve successfully";

    ofstream ofs(ORDER_FILE, ios_base::app);
    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "student_id:" << m_id << " ";
    ofs << "room:" << room << " ";
    ofs << "status:" << 1 << " \n";
    ofs.close();
}

void Student::show_odder() const
{
    Order_File of;

    if (of.m_size == 0)
    {
        cout << "There is no reservation. \n";
    }
    else
    {
        for (int i = 0; i < of.m_size; ++i)
        {
            if (stoi(of.m_data[i]["student_id"]) == m_id)
            {
                cout << "date: " << of.m_data[i]["date"];
                cout << "interval: " << (of.m_data[i]["interval"] == "1"? "morning" : "afternoon");
                cout << "room: " << of.m_data[i]["room"];
                string status = "status";
                if (of.m_data[i][status] == "1")
                {
                    status += ": under check. ";
                }
                else if (of.m_data[i][status] == "2")
                {
                    status += ": successful. ";
                }
                else if (of.m_data[i][status] == "-1")
                {
                    status += ": fail, ";
                }
                else
                {
                    status += ": canceled. ";
                }
                cout << status << endl;
            }
        }
    }
}

void Student::show_all_odder()
{
    Order_File of;
    if (of.m_size == 0)
    {
        cout << "There is no reservation. \n";
    }
    else
    {
        for (int i = 0; i < of.m_size; ++i)
        {
            cout << i+1 << ". "
                << "date: " << of.m_data[i]["date"]
                << "interval: " << of.m_data[i]["interval"]
                << "student_id: " << of.m_data[i]["student_id"]
                << "name: " << of.m_data[i]["name"]
                << "room: " << of.m_data[i]["room"]
                << "status: " << of.m_data[i]["status"];
            string status = "status";
            if (of.m_data[i][status] == "1")
            {
                status += ": under check. ";
            }
            else if (of.m_data[i][status] == "2")
            {
                status += ": successful. ";
            }
            else if (of.m_data[i][status] == "-1")
            {
                status += ": fail, ";
            }
            else
            {
                status += ": canceled. ";
            }
            cout << status << endl;
        }
    }
}

void Student::cancel_odder() const
{
    Order_File of;
    if (of.m_size == 0)
    {
        cout << "There is no reservation. \n";
    }
    else
    {
        cout << "Please enter the index of you want to delete";
        vector<int> v;
        int index = 1;
        for (int i = 0; i < of.m_size; ++i)
        {
            if (stoi(of.m_data[i]["student_id"]) == m_id && (of.m_data[i]["status"] == "1" || of.m_data[i]["status"] == "2"))
            {
                v.push_back(i);
                cout << index++ << ". "
                    << "date: " << of.m_data[i]["date"]
                    << "interval" << (of.m_data[i]["interval"] == "1"? "morning" : "afternoon")
                    << "room" << of.m_data[i]["room"];

                string status = "status";

                if (of.m_data[i][status] == "1")
                {
                    status += ": under check. ";
                }
                else if (of.m_data[i][status] == "2")
                {
                    status += ": successful. ";
                }

                cout << status << endl;
            }
        }

        cout << "Please enter the index of you want to delete. \n";

        int select = 0;

        while (cin >> select)
        {
            if (select >= 0 && select <= v.size())
            {
                if (!select)
                {
                    break;
                }
                else
                {
                    of.m_data[v[select-1]]["status"] = "0";
                    of.update();
                    cout << "Canceled! \n" << endl;
                    break;
                }
            }
            else
            {
                cout << "Wrong index. \n";
            }
        }
    }
}
