//
// Created by Violet on 24-10-21.
//

#include "global_file.h"

void administrator_menu(Identification * &administrator)
{
    administrator->operation_menu();
    while (true)
    {
        auto person = dynamic_cast<Administrator*>(administrator);

        int select = 0;
        cin >> select;

        if (select == 1)
        {
            cout << "Add a new account. \n";
            person->add_person();
        }
        else if (select == 2)
        {
            cout << "Check account. \n";
            person->show_person();
        }
        else if (select == 3)
        {
            cout << "Check computer room. \n";
            person->show_computer();
        }
        else if (select == 4)
        {
            cout << "Clean all accounts. \n";
            person->clean_file();
        }
        else
        {
            delete administrator;
            cout << "Log out. \n";
            return;
        }
    }
}

void student_menu(Identification * &student)
{
    student->operation_menu();
    while (true)
    {
        auto person = dynamic_cast<Student*>(student);

        int select = 0;
        cin >> select;

        if (select == 1)
        {
            person->apply_odder();
        }
        else if (select == 2)
        {
            person->show_odder();
        }
        else if (select == 3)
        {
            person->show_all_odder();
        }
        else if (select == 4)
        {
            person->cancel_odder();
        }
        else
        {
            delete student;
            cout << "Log out. \n";
            return;
        }
    }
}

void Teacher_menu(Identification * &teacher)
{
    teacher->operation_menu();
    while (true)
    {
        auto person = dynamic_cast<Teacher*>(teacher);

        int select = 0;
        cin >> select;

        if (select == 1)
        {
            person->show_all_order();
        }
        else if (select == 2)
        {
            person->check_order();
        }
        else
        {
            delete teacher;
            cout << "Log out. \n";
            return;
        }
    }
}

void log_in(const string & filename, int type)
{
    Identification * person  = nullptr;

    ifstream ifs(filename, ios_base::in);
    if (!ifs.is_open())
    {
        cout << "File is not exist. \n";
        ifs.close();
    }
    else
    {
        int id = 0;
        string name;
        string code;

        if (type == 1)
        {
            cout << "Please enter your student number: ";
            cin >> id;
        }
        else if (type == 2)
        {
            cout << "Please enter your teacher number: ";
            cin >> id;
        }

        cout << "Please enter your user name: ";
        cin >> name;

        cout << "Please enter the code: ";
        cin >> code;

        if (type == 1)
        {
            int t_id;
            string t_name;
            string t_code;
            while (ifs >> t_id && ifs >> t_name && ifs >> t_code)
            {
                if (id == t_id && name == t_name && code == t_code)
                {
                    cout << "Student log in! \n";
                    person = new Student(id, name, code);
                    student_menu(person);

                    return;
                }
            }
        }
        else if (type == 2)
        {
            int t_id;
            string t_name;
            string t_code;
            while (ifs >> t_id && ifs >> t_name && ifs >> t_code)
            {
                if (id == t_id && name == t_name && code == t_code)
                {
                    cout << "Teacher log in! \n";
                    person = new Teacher(id, name, code);
                    Teacher_menu(person);

                    return;
                }
            }
        }
        else if (type == 3)
        {
            string t_name;
            string t_code;
            while (ifs >> t_name && ifs >> t_code)
            {
                if (name == t_name && code == t_code)
                {
                    cout << "Administrator log in! \n";
                    person = new Administrator(name, code);
                    administrator_menu(person);

                    return;
                }
            }
        }

        cout << "Fail! \n";
        ifs.close();
    }
}
