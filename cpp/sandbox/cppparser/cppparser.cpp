#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <cstdlib>
using namespace std;

namespace cppparser {
    enum class states {POSITIONAL, FLAG, SPURIOUS};
}

using PositionalArguments = vector<string>;
using FlagArguments = map<string, vector<string>>;
using CString = char *;


int main(int argc, char *argv[])
{
    PositionalArguments posArgs;
    FlagArguments flagArgs;
    CString flag = nullptr;

    cppparser::states currentState = cppparser::states::POSITIONAL;

    for(auto arg = argv+1; *arg != nullptr; ++arg) {
        if (**arg == '-') {
            flag = *(arg) + 1;
            if(*flag == '\0') {
                currentState = cppparser::states::SPURIOUS;
            } else if (*flag == '-'){
                currentState = cppparser::states::POSITIONAL;
            } else {
                currentState = cppparser::states::FLAG;
                if ( flagArgs.find(flag) == flagArgs.end() ) {
                    flagArgs[flag];
                }
            }
            continue;
        } // check for ^-

        switch (currentState) {
            case cppparser::states::POSITIONAL:
                posArgs.push_back(*arg);
            break;

            case cppparser::states::FLAG:
                flagArgs[flag].push_back(*arg);
            break;

            case cppparser::states::SPURIOUS:
                cout << "Skipping " << *arg << endl;
            break;

            default:
                cout << "Something wrong in the parser logic" << endl;
            break;
        } // switch
    } // for

    if (posArgs.size() == 0) {
        cout << "ERROR: No positional arguments were entered... aborting" << endl;
        // exit(0);
    } else {
        cout << "Positional arguments entered.." << endl;
        for (const auto& arg: posArgs) {
            cout << arg << " ";
        }
        cout << endl;
    }

    for(const auto& pair : flagArgs) {
        cout << pair.first << endl;
        for(const auto& flagarg : pair.second) {
            cout << "\t" << flagarg << endl;
        }
        cout << endl;
    }

    return EXIT_SUCCESS;
}
