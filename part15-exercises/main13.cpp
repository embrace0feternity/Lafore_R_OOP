#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <ctype.h>
#include <iterator>


void parse(std::string &str, std::vector<std::string> &vect)
{
    str = " " + str; // для поиска первого слова
    const int SIZE = str.length();
    std::string word; // строка, хранящая слово
    for (int i=1; i<SIZE; i++)
    {
        str[i] = tolower(str[i]); // перевод букв верхнего регистра в нижний
        // Если текущий символ буква, а прошлый не буква, - это начало слова
        if ((str[i-1] == ' ') && (str[i] >= 'a' && str[i] <= 'z' || str[i] >= '0' && str[i] <='9')) 
        {
            int wordhead = i, wordtail, j;  // wordhead - позиция начала слова
            // Прохожу от начала слова. Если текущий символ буква, а следующий не буква, - это конец слова
            for (j = i; j<SIZE; j++)

                if ((str[j] >= 'a' && str[j] <= 'z' || str[j] >= '0' && str[j] <='9') && (str[j+1] == ' ' || str[j+1] == ',' || str[j+1] == '.' || str[j+1] == '\n' || str[j+1] == '\0'))
                {
                    wordtail = j; // запомнил позицию окончания слова
                    break;
                }
            word = str.substr(wordhead, wordtail-wordhead+1); // присваиваю word-у подстроку, т.е мое слово
            vect.push_back(word); // закидываю его в деку
            i += wordtail - wordhead; // перепрыгиваю через это слово в строке, т.к оно нам больше не нужно
        }
    }
}




int main(int argc, char **argv)
{
    using namespace std;
    ifstream inFile("text.txt", ios::in);
    std::string text;
    getline(inFile, text, '$');

    std::vector<std::string> vect;
    //string str = "  Hi my name is Vlad";
    
    parse(text, vect); // ф-ия разбиения строки на слова
    std::cout << "Размер вектора: " << vect.size() << std::endl;
    // Теперь все слова находятся в векторе vect

    map<string,int> strMap; // Создал мапу. В мапе хранятся пары <слово, кол-во таких слов в тексте>
    for (int i=0; i<vect.size(); i++) // Прохожусь по вектору
    {
        /*
            emplace вставляет пару <string, int> в мапу и возвращает пару <итератор, бул>
            Если бул = тру - успешно вставили пару <string, int> в мапу, итератор указывает на 
            только что вставленный элемент. 
            Если бул = фолс, то пара не вставляется в мапу т.к она там уже есть. Итератор
            указывает на имеющуюся в мапе пару <string, int>.
        */
        pair<map<string,int>::iterator, bool> res = strMap.emplace(vect[i],1);
        // Если пара (а именно, ключик) уже есть, то увеличиваю кол-во повторений слова
        if (!res.second)     strMap[vect[i]] += 1; 
    }
    std::cout << "Размер отображения: " << strMap.size() << std::endl;
    
    ofstream out_file("main13_table0fwordfrequency.txt", std::ios::out | std::ios::trunc);
    // Итератор вывода с потоком out_file, т.е мой файлик. Записываю мапу в файл. Мапа это не POD тип, поэтому пишу вот так..
    for (auto iter = strMap.begin(); iter != strMap.end(); iter++)
    {
        out_file << iter->first << ' ' << iter->second << '\n';
    }
    out_file.close();

    return 0;
}