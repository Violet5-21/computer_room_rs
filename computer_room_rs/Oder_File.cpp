//
// Created by Violet on 24-10-22.
//

#include "Oder_File.h"

Order_File::Order_File()
{
    ifstream ifs(ORDER_FILE);
    string date;
    string interval;
    string student_id;
    string student_name;
    string room_id;
    string status;

    m_size = 0;

    while (ifs >> date && ifs >> interval && ifs >> student_id && ifs >> student_name && ifs >> room_id && ifs >> status)
    {
        string key, value;
        map<string, string> m;

        unsigned long long pos = date.find(':');
        if (pos != -1)
        {
            key = date.substr(0, pos);
            value = date.substr(pos+1, date.size()-pos);
            m.insert(make_pair(key, value));
        }

        pos = interval.find(':');
        if (pos != -1)
        {
            key = interval.substr(0, pos);
            value = interval.substr(pos+1, interval.size()-pos);
            m.insert(make_pair(key, value));
        }

        pos = student_id.find(':');
        if (pos != -1)
        {
            key = student_id.substr(0, pos);
            value = student_id.substr(pos+1, student_id.size()-pos);
            m.insert(make_pair(key, value));
        }
        pos = student_name.find(':');
        if (pos != -1)
        {
            key = student_name.substr(0, pos);
            value = student_name.substr(pos+1, student_name.size()-pos);
            m.insert(make_pair(key, value));
        }
        pos = room_id.find(':');
        if (pos != -1)
        {
            key = room_id.substr(0, pos);
            value = room_id.substr(pos+1, room_id.size()-pos);
            m.insert(make_pair(key, value));
        }
        pos = status.find(':');
        if (pos != -1)
        {
            key = status.substr(0, pos);
            value = status.substr(pos+1, status.size()-pos);
            m.insert(make_pair(key, value));
        }

        m_data.insert(make_pair(m_size, m));
        m_size++;
    }
}

void Order_File::update()
{
    if (m_size > 0)
    {
        ofstream ofs(ORDER_FILE, ios_base::trunc);

        for (int i = 0; i < m_size; ++i)
        {
            ofs << "date:" << m_data[i]["date"] << " ";
            ofs << "interval:" << m_data[i]["interval"] << " ";
            ofs << "student_id:" << m_data[i]["student_id"] << " ";
            ofs << "student_name:" << m_data[i]["student_name"] << " ";
            ofs << "room:" << m_data[i]["room"] << " ";
            ofs << "status:" << m_data[i]["status"] << " \n";
        }

        ofs.close();
    }
}
