#include <iostream>
#include <fstream>
#include <string>

class exceptions
{
public:
    std::string where;
    exceptions(std::string str) { where = str;}
};

template<typename T>
class doFile
{
    static std::fstream ffile;
public:
    void open(char *argv, char ch);
    void close() { ffile.close(); }
    void write(T data);
    void read();
};
template<typename T>
std::fstream doFile<T>::ffile;

template<typename T>
void doFile<T>::open(char *argv, char ch)
{
    if (ch == 'w') ffile.open(argv, std::ios::binary | std::ios::out | std::ios::app);
    else ffile.open(argv, std::ios::binary | std::ios::in);
    if (!ffile.is_open()) throw exceptions("Open file error");
}

template<typename T>
void doFile<T>::write(T data)
{
    ffile.write(reinterpret_cast<char*>(&data), sizeof(data));
    if (!ffile) {
        throw exceptions("Impossible to write down inforamion");
    }
}

template<typename T>
void doFile<T>::read()
{
    T buff;  
    while(true)
    {
        ffile.read(reinterpret_cast<char*>(&buff),sizeof(buff));
        if (ffile.eof()) break;
        std::cout << buff << std::endl;
    }
}

template<typename T>
void open(doFile<T> &dF1, char *arg, char ch)
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
    if (argc != 2){
        std::cerr << "Unknowed command. Use \"main12_v2.exe name_of_file\"" << std::endl;
        exit(0);
    }
    //char arg[] = "q.dat";
    std::cout << argv[1] << std::endl;
    doFile<char> dF;
    char ch = 'a';
    std::cout << "Choose an action - write(w) or read(r) "; std::cin >> ch;
    while(ch!='q')
    {
        if (ch == 'w')
        {
            int data;
            open(dF, argv[1],'w');
            std::cout << "Write a data: "; //std::cin >> data;
            for (int i=0; i<5; i++) dF.write('a');
            dF.close(); 
        }
        else if (ch == 'r')
        {
            open(dF,argv[1],'r');
            dF.read();
            dF.close();
        }
        else if (ch == 'q') break;
        std::cin >> ch;
    } 
    return 0;
}
