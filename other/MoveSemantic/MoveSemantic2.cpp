#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class cell{
    std::string data = "N/A";
};

class qwer{
    int a = 0;
    cell* mCells = nullptr;
    qwer() = default;
public:
    qwer(int a): a(a) { mCells = new cell; }
    ~qwer() { delete mCells; }
    
    qwer(qwer &&other): qwer(other.a) 
    {
        cout << "move constr" << endl;
        mCells = other.mCells;

        other.a = 0;
        other.mCells = nullptr;
    }

    qwer& operator=(qwer &&other) noexcept;
    void show()const { cout << a << endl; }
};

qwer& qwer::operator= (qwer &&other) noexcept{
    cout << "move operator" << endl;
    if (this == &other) return *this;
    delete mCells;

    a = other.a;
    mCells = other.mCells;

    other.a = 0;
    other.mCells = nullptr;
    return *this;
}

qwer createObj()
{
    return qwer(6);
}

int main()
{
    qwer vlad(3);
    vlad = createObj();
    vlad.show();
    return 0;
}