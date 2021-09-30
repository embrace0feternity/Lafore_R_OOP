#include <iostream>
#include <new>
using namespace std;


const int SIZE = 500;
const int N = 5;
char buf[SIZE];



int main()
{
    double *pd1, *pd2;
    int i;

    pd1 = new double[N];
    pd2 = new(buf) double[N];
    for (int i=0; i<N; i++)
        pd1[i] = pd2[i] = i*10;
        
    cout << "Memory addres\n" << "heap: " << 
        pd1 << "\t\tstatic: " << pd2 << ' ' << static_cast<void*>(buf) << endl;
    
    for (int i=0; i<N; i++)
    {
        cout << "pd1[" << i << "] = " << pd1[i] << " at" <<  pd1+i 
        << "\t\tpd2[" << i << "] = " << pd2[i] << " at " <<  pd2+i << endl; 
    }
    cout << endl << endl;
    
    double *pd3, *pd4;
    pd3 = new double[N];
    pd4 = new(buf) double[N];
    for (int i=0; i<N; i++)
        pd3[i] = pd4[i] = i*10+25;
        
    cout << "Memory addres\n" << "heap: " << 
        pd3 << "\t\tstatic: " << pd4 << ' ' << static_cast<void*>(buf) << endl;
    
    for (int i=0; i<N; i++)
    {
        cout << "pd3[" << i << "] = " << pd3[i] << " at" <<  pd3+i 
        << "\t\tpd4[" << i << "] = " << pd4[i] << " at " <<  pd4+i << endl;  
    }
    cout << endl << endl;

    double *pd5, *pd6;
    pd5 = new double[N];
    pd6 = new(buf+N*sizeof(double)) double[N];
    for (int i=0; i<N; i++)
        pd5[i] = pd6[i] = i*10+53;
        
    cout << "Memory addres\n" << "heap: " << 
        pd3 << "\t\tstatic: " << pd4 << ' ' <<  static_cast<void*>(buf) << endl;
    
    for (int i=0; i<N; i++)
    {
        cout << "pd6[" << i << "] = " << pd6[i] << " at" <<  pd5+i 
        << "\t\tpd5[" << i << "] = " << pd5[i] << " at " <<  pd6+i << endl; 
    }
    
    cout << endl << endl;
    delete[] pd1, pd3, pd5;
}