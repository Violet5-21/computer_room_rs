//
// Created by Violet on 24-10-21.
//

#include "Teacher.h"

Teacher::Teacher(int id, string & name, string & code)
{
    m_id = id;
    m_name = name;
    m_code = code;
}

void Teacher::operation_menu()
{
    string welcome = " Welcome to the teacher! ";
    string action1 = " 1. Check for a reservation. ";
    string action2 = " 2. Valid reservation. ";
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
    cout << "\t\t\t|" << setw(26+static_cast<int>(exit.size()/2)) << exit
         << setw(26-static_cast<int>(exit.size()/2)) << "|\n";
    cout << "\t\t\t|" << setfill(' ') << setw(52) << "|\n";
    cout << "\t\t\t" << setfill('-') << setw(53) << "\n";
    cout << reminder << setfill(' ');
}

void Teacher::show_all_order()
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

void Teacher::check_order()
{
    Order_File of;
    if (of.m_size == 0)
    {
        cout << "There is no reservation. \n";
    }
    else
    {
        cout << "Wait to valid. \n";
        vector<int> v;
        int index = 1;
        for (int i = 0; i < of.m_size; ++i)
        {
            if (of.m_data[i]["status"] == "1")
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

                cout << status << endl;
            }
        }

        cout << "Please enter the index of you want to valid. \n";

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
                    cout << "Please enter the valid result. \n";
                    cout << "1. Pass. \n";
                    cout << "2. Not Pass. \n";

                    int flag;
                    cin >> flag;

                    if (flag == 1)
                    {
                        of.m_data[v[select-1]]["status"] = "2";
                    }
                    else if (flag == 2)
                    {
                        of.m_data[v[select-1]]["status"] = "-1";
                    }
                    of.update();

                    cout << "Valid over! \n" << endl;
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
