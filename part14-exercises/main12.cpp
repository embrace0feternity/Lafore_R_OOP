#include <iostream>
#include <fstream>
#include <string>

class exceptions
{
public:
    std::string where;
    exceptions(std::string str) { where = str;}
};

int buff[256];

class doFile
{
    static std::fstream ffile;
public:
    void open(char *argv, char ch){
        if (ch == 'w') ffile.open(argv, std::ios::binary | std::ios::out);
        else ffile.open(argv, std::ios::binary | std::ios::out);
        if (!ffile.is_open()) throw exceptions("Open file error");
    }
    void write(int *data, const int size)
    {
        ffile.write(reinterpret_cast<char*>(data), size*sizeof(int));
        if (!ffile) {
            throw exceptions("Impossible to write down inforamion");
        }
        ffile.close();
    }
    void read(const int size)
    {
        ffile.read(reinterpret_cast<char*>(buff),size*sizeof(int));
        if (!ffile) {
            throw exceptions("Impossible to read from file");
        }
        ffile.close();
    }
};
std::fstream doFile::ffile;

void open(doFile &dF1, char *arg, char ch)
{
    try{
        dF1.open(arg,ch);
    }
    catch(const exceptions &e){
        std::cerr << e.where << '\n';
    }
}

int main(int argc, char **argv)
{
    doFile dF1;
    char arg[] = "temp.dat";

    const int SIZE = 10;
    char ch = 'a';    int arr[SIZE];
    std::cout << "Choose an action: write(w) or read(r): "; std::cin >> ch;
    while(true)
    {
        if(ch == 'w')
        {
            open(dF1, arg, ch);
            for (int i=0; i<SIZE; i++) arr[i] = i*i;
            try{
                dF1.write(arr, SIZE);
                std::cout << "Successful writing!" << std::endl;
            }
            catch(const exceptions &e){
                std::cerr << e.where << '\n';
            }
        }
        if(ch == 'r')
        {
            open(dF1, arg, ch);
            try{
                dF1.read(SIZE);
                std::cout << "Successful reading!" << std::endl;
            }
            catch(const exceptions &e){
                std::cerr << e.where << '\n';
            }
        }
        std::cin >> ch;
    }
    return 0;
}


