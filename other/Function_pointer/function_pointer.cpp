#include <iostream>

using std::endl;

double first(int);
double second(int);
void general(int, double (*functionPointer)(int));


// these algorthms aren't true, i just invite them
double first(int lines) {  return 0.03*lines; }
double second(int lines) {  return 0.02*lines + 0.0001*lines*lines; }


int main(int argc, char **argv)
{
    // Write how many lines do u have in code. Then 2 algorithms will calculete how much times your code takes.
    int lines;
    std::cout << "How many lines in your code do you need?? " << endl;  std::cin >> lines;
    
    std::cout << "The first algorythm: "; 
    general(lines, first);

    std::cout << "The second algorythm: "; 
    general(lines, second);
    
    return 0;
}

void general(int lines, double (*functionPointer)(int))
{
    std::cout << lines << " will take you " << (*functionPointer)(lines) << " hours." << endl;
}