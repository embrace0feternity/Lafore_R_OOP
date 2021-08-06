#include <iostream>
using namespace std;

class week
{
private:
    string day;
public:
    week(string &s): day(s) { }
    void show()const    {   cout << day << endl;    }
    string& getDay() {  return day;  }
    void sort();
};

void sort(week **str)
{
    week *temp = nullptr;
    for (int i=0; i<7; i++)
    {
        for (int j=i+1; j<7; j++)
        if (str[i]->getDay() > str[j]->getDay())
        {
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
    }
}

int main(int argc, char **argv)
{
    week *day[7];
    char ch = 'a'; string str;
    for (int i = 0; i<7; i++)  
    {
        cin >> str;
        day[i] = new week(str);
    }
    for (int i=0; i<7; i++) day[i]->show();
    cout << endl;
    
    sort(day);
    for (int i=0; i<7; i++) day[i]->show();
    return 0;
}