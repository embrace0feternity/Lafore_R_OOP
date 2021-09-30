#include <iostream>
#include <regex>
#include <string>

int main()
{
    using namespace std;
    
    // string a = "Vlad@mail.ru Masha@yan.com";
    // regex b("([\\w-]+)"
    //         "@"
    //         "([\\w]+)"
    //         "\\."
    //         "\\w{2,5}"
    //         );
    string mPassword = "Vlad_Streha-123";
    std::regex check("^[\\w-_]+$");
    if (std::regex_match(mPassword.begin(), mPassword.end(), check)) std::cout << "True\n";
    else cout << "False\n";


    /*
        Итератор regex, необходим для вывода повторяющихся шаблонов выражения в строке
        Если найдено совпадение, работает как regex_search, но при это сохраняет своё состояние +
        такой итератор можно разыменовать и получить рез-т совпадения.
        b regex передается по ссылке, а не по значению
    */
    // regex_iterator<string::iterator> rit(a.begin(), a.end(), b);
    // regex_iterator<string::iterator> rend;

    // while(rit!=rend)
    // {
    //     cout << rit->str() << endl;
    //     rit++;
    // }  

    return 0; 
}