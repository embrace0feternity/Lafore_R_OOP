#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

bool compare(std::string a, std::string b)
{
    return (a<b);
}

int main()
{
    using namespace std;
    string words[] = { "i", "saw", "your", "smilling", "your", "hopes", "were", "filled", "with", "dreams" };
    
    vector<string> v1;
    for (const auto &i : words) v1.push_back(i);
    
    cout << "Массив слов перед сортировкой: ";
    for (int i=0; i<v1.size(); i++) cout << v1[i] << ' ';
    cout << endl << endl;; 
    
    sort(v1.begin(), v1.end(), compare);

    cout << "Массив слов после сортировки. Бессмыслица: ";
    for (int i=0; i<v1.size(); i++) cout << v1[i] << ' ';
    cout << endl; 
    
    return 0;
}