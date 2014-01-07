#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

int main(int argc, char* argv[])
{
    using namespace std;
   
    vector<string> cmdlineargs(argv+1, argv+argc);
   
    for(auto rbiterv=cmdlineargs.rbegin(); rbiterv != cmdlineargs.rend(); ++rbiterv) {
        auto& arg = *rbiterv;
        
        for(auto rbiterarg = arg.rbegin(); rbiterarg != arg.rend(); ++rbiterarg) {
            cout << *rbiterarg;    
        }
        
        cout << endl;
    }
   
    return EXIT_SUCCESS;
}

