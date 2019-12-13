#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <array>
#include <sstream>

using std::array;
using std::cout;
using std::endl;
using std::istringstream;
using std::string;
using std::vector;

class Date
{
private:
    unsigned int year;
    unsigned int month;
    unsigned int day;

public:
    // Date(): year(0), month(0), day(0) {}

    Date(string date)
    {
        // deal string date
        for (auto &&i : date)
        {
            if (!isalnum(i))
            {
                i = ' ';
            }
            tolower(i);
        }

        istringstream record(date);
        string word;
        vector<string> vecdate;
        while (record >> word)
        {
            vecdate.push_back(word);
        }
        if (vecdate.size() > 3)
        {
            throw std::runtime_error("date string is not standard");
        }

        // month
        array<string, 12> const month_list{"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
        int index = 0;
        for (auto &&str : vecdate)
        {
            for (size_t i = 0; i < month_list.size(); i++)
            {
                if (str.find(month_list[i]) != string::npos)
                {
                    month = i + 1;
                    break;
                }
            }
            ++index;
        }

        switch (vecdate.size())
        {
        case 3:
            switch (index)
            {
            case 3:
                if (vecdate[0].size() == 4)
                {
                    year = stoul(vecdate[0]);
                    month = stoul(vecdate[1]);
                    day = stoul(vecdate[2]);
                }
                else if (vecdate[2].size() == 4)
                {
                    year = stoul(vecdate[2]);
                    month = stoul(vecdate[0]);
                    day = stoul(vecdate[1]);
                }
                else
                {
                    throw std::runtime_error("date string is not standard");
                }
                break;
            case 2:
                year = stoul(vecdate[0]);
                day = stoul(vecdate[1]);
                break;
            case 1:
                year = stoul(vecdate[0]);
                day = stoul(vecdate[2]);
                break;
            case 0:
                year = stoul(vecdate[2]);
                day = stoul(vecdate[1]);
                break;
            default:
                throw std::runtime_error("date string is not standard");
                break;
            }
            break;
        case 2:
            if (stoul(vecdate[0]) <= 1231 && stoul(vecdate[1]) <= 1231)
            {
                throw std::runtime_error("confused");
            }
            else if (stoul(vecdate[0]) <= 1231)
            {
                month = stoul(vecdate[0].substr(0, 2));
                day = stoul(vecdate[0].substr(2, 2));
                year = stoul(vecdate[1]);
            }
            else if (stoul(vecdate[1]) <= 1231)
            {
                month = stoul(vecdate[1].substr(0, 2));
                day = stoul(vecdate[1].substr(2, 2));
                year = stoul(vecdate[0]);
            }
            else
            {
                throw std::runtime_error("confused, month and date may wrong");
            }
            break;
        case 1:
            if (vecdate[0].size() == 8)
            {
                year = stoul(vecdate[0].substr(0, 4));
                month = stoul(vecdate[0].substr(4, 2));
                day = stoul(vecdate[0].substr(6, 2));
            }
            else
            {
                throw std::runtime_error("confused");
            }
            break;
        default:
            throw std::runtime_error("bad format");
            break;
        }
    }
    ~Date() {}
    void print_date()
    {
        cout << month << ", " << day << ", " << year << endl;
    }
};

int main()
{
    Date date1("1967 4 6"), data2("1990/////03////12"), date3("18650403"), date4("1221, 1967"), date5("2019.12.14");
    date1.print_date();
    data2.print_date();
    date3.print_date();
    date4.print_date();
    date5.print_date();
}