#include <iostream>
#include <string.h>

class strCount
{
private:
    int count;
    char *str;
    friend class String;

    strCount(const char *s)
    {
        std::cout << "const " << this << std::endl;
        int length = strlen(s);
        str = new char[length+1];
        strcpy(str,s);
        count = 1;
    }
    ~strCount() { delete[]str; std::cout << "destr " << this << std::endl; }
};

class String
{
private:
    strCount *psc;
public:
    String() { psc = new strCount("N/A"); }
    String(const char *s) { psc = new strCount(s); }
    String(String &S)
    {
        psc = S.psc;
        (psc->count)++;
    }
    ~String()
    {
        if (psc->count == 1) delete psc; else (psc->count)--;
    }
    void show()
    {
        std::cout << psc->str;
        std::cout << " (addr = " << psc << ")" << std::endl;
    }
    void operator= (String &S)
    {

        psc = S.psc;
        (psc->count)++;
    }
};

int main()
{
    String s3("Hi vlad");
    std::cout << "S3 = "; s3.show();
    
    String s1;
    s1 = s3;
    std::cout << "S1 = "; s1.show();
    
    String s2(s3);
    std::cout << "S2 = "; s2.show();
    return 0;
}


