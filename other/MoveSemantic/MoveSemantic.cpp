#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class cell{
    std::string data = "N/A";
};


class Spreadsheet{
    int mRows;
    int mColumns;
    cell** mCells = nullptr;
    Spreadsheet() = default;
public:
    ~Spreadsheet();
    Spreadsheet(int rows, int colums);
    Spreadsheet(Spreadsheet &&other) noexcept;
    Spreadsheet& operator= (Spreadsheet &&other) noexcept;
};


Spreadsheet::Spreadsheet(int rows, int colums): mRows(rows), mColumns(colums) {
    cout << "Дефолтный конструктор" << endl; 
    mCells = new cell*[mRows];
    for (int i; i<mRows; ++i) 
        mCells[i] = new cell[mColumns];
}

Spreadsheet::~Spreadsheet() {
    for (int i; i<mRows; ++i) 
        delete[] mCells[i];
    delete[] mCells;
}

Spreadsheet::Spreadsheet(Spreadsheet &&other) noexcept{
    cout << "Конструктор перемещения" << endl; 
    mRows = other.mRows;
    mColumns = other.mColumns;
    mCells = other.mCells;

    other.mRows = 0;
    other.mColumns = 0;
    other.mCells = nullptr;
}

Spreadsheet& Spreadsheet::operator= (Spreadsheet &&other) noexcept{
    cout << "Оператор перемещения" << endl;
    if (&other == this) return *this;
    for (int i; i<mRows; ++i) delete[] mCells[i];
    delete[] mCells;
    mRows = 0;  mColumns = 0;

    mRows = other.mRows;
    mColumns = other.mColumns;
    mCells = other.mCells;

    other.mCells = nullptr;
    return *this;
}


Spreadsheet createObj(int n, int m)
{
    return Spreadsheet(n,m);
}

int main()
{
    int n = 4, m = 5;

    swap(n,m);
    vector<Spreadsheet> vec;
    for (int i=0; i<2; i++)
    {
        cout << "Итерация " << i << endl;
        vec.push_back(Spreadsheet(2, 3));
        cout << endl;
    }
    Spreadsheet s1(n, m);
    s1 = createObj(2,3);
    return 0;
}





