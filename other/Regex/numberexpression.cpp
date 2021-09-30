#include <iostream>
#include <regex>
#include <string>

using namespace std;


int main()
{
    std::string lines[] = {"Roses are #ff0000",
                           "violets are #0000ff",
                           "all of my base are belong to you"};
 
    std::regex color_regex("#([a-f0-9]{2})"
                            "([a-f0-9]{2})"
                            "([a-f0-9]{2})");
 
    // simple match
    for (const auto &line : lines) {
        std::cout << line << ": " << std::boolalpha
                  << std::regex_search(line, color_regex) << '\n';
    }   
    std::cout << '\n';
    std::smatch color_match;
    for (string& line : lines) {
        if(std::regex_search(line, color_match, color_regex)) {
            std::cout << "matches for '" << line << "'\n";
            std::cout << "Prefix: '" << color_match.prefix() << "'\n";
            for (size_t i = 0; i < color_match.size(); ++i) 
                std::cout << i << ": " << color_match[i] << '\n';
            std::cout << "Suffix: '" << color_match.suffix() << "\'\n\n";
        }
    }
}
// #include <iostream>
// #include <regex>
// #include <string>

// using namespace std;


// int main()
// {
//     string expr = "1+3*3-4";
//     regex Operator("[\\+-*/]");
//     cmatch res;

//     regex_iterator<string::iterator> rit(expr.begin(), expr.end(), Operator);
//     regex_iterator<string::iterator> rend;

//     for (int i=0; i<expr.size(); i++)
//     {
//         if (regex_search(expr, res, Operator))
//         {
//         }
//     }

//     return 0;
// }