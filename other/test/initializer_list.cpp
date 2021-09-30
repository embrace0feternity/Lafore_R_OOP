#include <iostream>
#include <initializer_list>
#include <vector>

using namespace std;

template <typename T>
class EvenSequence{
    vector<T> mSequence;
public:
    EvenSequence(initializer_list<T> args){
        if (args.size() % 2 == 1) throw("Initializer_list should contain even number of elements");
        mSequence.reserve(args.size());
        for (const T &i : args) mSequence.push_back(i);
    } 
    void show()const{
        for (const T &i : mSequence) cout << i << ' ';
        cout << endl;
    }
};

int main()
{
    EvenSequence<int> seq = {1, 2, 3, 4, 5, 7};
    seq.show();

    EvenSequence<string> seqstr = {"Vlad", "Egor", "Masha", "Sonya"};
    seqstr.show();
}