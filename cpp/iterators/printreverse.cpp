#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

int main(int argc, char* argv[])
{
    using namespace std;
   
    vector<string> cmdlineargs(argv+1, argv+argc);
   
    auto rbiterv = cmdlineargs.rbegin();
   
    while( rbiterv != cmdlineargs.rend() ) {
        auto& arg = *rbiterv++;
        auto rbiterarg = arg.rbegin();
       
        while( rbiterarg != arg.rend() ) {
            cout << *rbiterarg++;
        }
        cout << endl;
    }
   
    return EXIT_SUCCESS;
} 
