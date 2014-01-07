#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

namespace cppparser 
{
    using namespace std;
    
    class Argument {
        private:
            static bool isDash(char c) {
                return c == '-';
            }
            Argument() = delete;
            ~Argument() = delete;
            Argument(const Argument&) = delete;
            Argument& operator=(const Argument&) = delete;
         
        public:
            
            static bool beginsWithDash(const string& arg) {
                return arg.front() == '-';
            }
            
            static bool isAllDashes(const string& arg) {
                return all_of(arg.cbegin(), arg.cend(), isDash);
            }
            
            static bool stillContainsDashes(const string& arg) {
                return any_of(arg.cbegin(), arg.cend(), isDash);
            }
    };
} // namespace cppparser


int main(int argc, char* argv[])
{
    using namespace std;
    using namespace cppparser;
   
    vector<string> cmdlineargs { argv+1, argv+argc };
    string flag {};
   
    for(const auto &arg : cmdlineargs) {
        if (Argument::beginsWithDash(arg)) {
            if( Argument::isAllDashes(arg) ) {
                cout << "Spurious flag " << arg << endl;
                flag.clear();
            }
            else {
                flag = arg.substr(arg.find_first_not_of("-", 0));
                
                if( Argument::stillContainsDashes(flag) ) {
                    cout << "ERROR: Dude.. this is too much " << flag << endl;
                    flag.clear();
                } else {
                    cout << "*" << flag << "*" << endl;
                }
            }
        } // flag?
        else {
            if( flag.size() > 0 ) 
                cout << "    ";
            cout << arg << endl;
        } // insert args into output stream
    } // range based for loop
   
    return EXIT_SUCCESS;
}


