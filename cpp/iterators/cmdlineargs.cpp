#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <cstdlib>

int main(int argc, char* argv[])
{
    using namespace std;
   
    for(auto arg = argv+1; arg < argv+argc; ++arg) {
        cout << *arg << endl;   
    }
   
    cout << endl;
   
   
    for(const auto& arg : vector<string> {argv+1, argv+argc}) {
        cout << arg << endl;   
    }
    
    cout << endl;
   
   
    copy(argv+1, argv+argc, ostream_iterator<char *>(cout, "\n"));
   
    cout << endl;
   
   
    vector<string> cmdlineargs {argv+1, argv+argc};
   
    copy(cmdlineargs.cbegin(), cmdlineargs.cend(), ostream_iterator<string>(cout, "\n"));
    
    cout << endl;
    
    
    copy(cmdlineargs.crbegin(), cmdlineargs.crend(), ostream_iterator<string>(cout, "\n"));
    
    cout << endl;
    
    
    reverse_copy(cmdlineargs.crbegin(), cmdlineargs.crend(), ostream_iterator<string>(cout, "\n"));
   
    return EXIT_SUCCESS;
}

