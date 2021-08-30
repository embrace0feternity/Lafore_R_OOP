#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    const char lastline[] = "But the one i love dearest, i look into your eyes and say...\n";
    ofstream outfile("song.txt");
    
    /*
            В программах "formato.cpp" и "formati.cpp" проблема с записью в файл строк, содержащие пробелы.
        Для решения проблемы нужно писать символ начала новой строки и использовать функцию getline.
        Строки должны иметь тип char *, а не std::string. Многие операции гораздо проще проводить с char *
    */
    outfile << "I surmise that evething will happen for a reason\n"
        << "Of my lack of cognisence and of my acts of treason\n"
        << "I can't live knowing that my actions cost her life\n"
        << lastline;
    cout << "Данные записаны в файл!" << endl;
    return 0;
}