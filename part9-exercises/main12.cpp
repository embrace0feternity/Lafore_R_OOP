#include <iostream>
using namespace std;

class Farting;

class sterling
{
public:
    long funt;
    int sh;
    int pens;
public:
    sterling(): funt(0), sh(0), pens(0) { }
    explicit sterling(double nw)
    {
        double temp = nw*240;   // 240 - koef. 1 funt = 240 pens
        funt = int(temp/240);
        temp = temp - funt*240;
        sh = int(temp/12);      // 1 sh = 12 pens
        pens = temp - sh*12;
    }
    sterling(long f, int sh, int p): funt(f), sh(sh), pens(p) {}

    void putSterling() { cout << ". Old money system: " << funt << '.' << sh << '.' << pens << endl; }
    operator double()
    {
        double temp = ((funt*20 + sh)*12 + pens)/240.;
        return temp;
    }
    sterling operator+ (sterling &other);
    sterling operator- (sterling &other);
    sterling operator* (sterling &other);
    sterling operator* (double &other);
    sterling operator/ (sterling &other);
    sterling operator/ (double &other);
};
sterling sterling::operator+(sterling &other)
{
    double temp1 = other;
    double temp2 = sterling(funt,sh,pens);
    return sterling(temp1 + temp2);   
}

sterling sterling::operator-(sterling &other)
{
    double temp1 = other;
    double temp2 = sterling(funt,sh,pens);
    return sterling(temp2- temp1);   
}

sterling sterling::operator* (sterling &other)
{
    double temp1 = sterling(funt,sh,pens);
    double temp2 = double(other);
    return sterling(temp1 * temp2);
}

sterling sterling::operator* (double &other)
{
    double temp2 = sterling(funt,sh,pens);
    return sterling(other * temp2);   
}

sterling sterling::operator/ (sterling &other)
{
    double temp1 = other;
    double temp2 = sterling(funt,sh,pens);
    return sterling(temp1 / temp2);   
}

sterling sterling::operator/ (double &other)
{
    double temp2 = sterling(funt,sh,pens);
    return sterling(other / temp2);   
}

class Farting   :   private sterling
{
private:
    int eighths;            // Определяет количество восьмых (3/8; eighths = 3)
public:
    Farting(): sterling(), eighths(0) { }
    Farting(sterling &other, int e);
    
    Farting(long f, int sh, int p, int e): sterling(f,sh,p), eighths(e) { }
    
    void putSterling() 
    { 
        cout << ". Super old money system: " << funt << '.' << sh << '.' << pens;
        if (eighths != 0) cout << '-' << eighths << "/8" <<  endl; else cout << endl; 
    }

    Farting operator+ (Farting &other); 
    Farting operator- (Farting &other); 
    Farting operator* (Farting &other); 
    Farting operator/ (Farting &other); 
};
Farting::Farting(sterling &other, int e)
{
    funt = other.funt;
    sh = other.sh;
    pens = other.pens;
    eighths = e;
    if (eighths>=8) 
    { 
        int temp = int (eighths/8);
        pens += temp;
        eighths -= temp*8; 
    }
    if (pens>=12) 
    { 
        int temp = int (pens/12);
        sh += temp; 
        pens -= temp*12; 
    }
    if (sh>=20) 
    {
        int temp = int(sh/20);
        funt += temp;
        sh -= temp*20;
    }
}

Farting Farting::operator+ (Farting &other)
{
    int e = eighths + other.eighths;
    sterling temp = sterling::operator+ (other);
    return Farting(temp,e);
}
Farting Farting::operator- (Farting &other)
{
    int e = eighths - other.eighths;
    sterling temp = sterling::operator- (other);
    return Farting(temp,e);
}
Farting Farting::operator* (Farting &other)
{
    int e = eighths*other.eighths;
    sterling temp = sterling::operator* (other);
    return Farting(temp,e);
}
Farting Farting::operator/ (Farting &other)
{
    int e = eighths*other.eighths;
    sterling temp = sterling::operator/ (other);
    return Farting(temp,e);
}

int main()
{
    cout << "Write amoount of money using old money system like this: \'7.17.9-1/8\' " << endl;
    long funt; int sh, pens, eighths;
    cout << "Funt: "; cin >> funt;
    cout << "Sh: "; cin >> sh;
    cout << "Pens: "; cin >> pens; 
    cout << "Eighths: "; cin >> eighths;

    cout << "Write one more time like this: \'7.17.9-7/8\' " << endl;
    long funt2; int sh2, pens2, eighths2;
    cout << "Funt: "; cin >> funt2;
    cout << "Sh: "; cin >> sh2;
    cout << "Pens: "; cin >> pens2;
    cout << "Eighths: "; cin >> eighths2;      
    cout << "Super old system:" << endl;

    Farting temp(funt,sh,pens,eighths);
    Farting temp2(funt2,sh2,pens2,eighths2);
    Farting temp3;
    temp3 = temp + temp2;
    cout << "temp + temp2"; temp3.putSterling();
    temp3 = temp - temp2;
    cout << "temp - temp2"; temp3.putSterling();
    temp3 = temp * temp2;
    cout << "temp * temp2"; temp3.putSterling();
    temp3 = temp / temp2;
    cout << "temp / temp2"; temp3.putSterling();
    
    return 0;

}

