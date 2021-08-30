#include <iostream>

class Distance
{
private:
    int feet;
    double inches;
public:
    class exception 
    { 
    public:
        std::string str;
        float error;
        exception(const std::string str, float error): str(str), error(error) { }
    };
    Distance(): feet(0), inches(0) { }
    Distance(int f, double in) 
    { 
        if (in >= 12) throw exception("Error into 2 arguments constructor.", in);
        feet = f;   inches = in;
    }
    void getDistance()
    {
        std::cout << "Write feet: "; std::cin >> feet;
        std::cout << "Write inches: "; std::cin >> inches;
        if (inches >= 12) throw exception("Error into getDistance().", inches);
    }
    void showDistance()const { std::cout << feet << '-' << inches << std::endl; }

};

int main()
{
    Distance d1;
    try
    {
        Distance d2(12, 12.5);
        d1.getDistance();
        
        d1.showDistance();
        d2.showDistance();
    }
    catch(Distance::exception other)
    {
        std::cerr << other.str << " Неправильное значение - " << other.error << std::endl;
    }
    
    return 0;
}