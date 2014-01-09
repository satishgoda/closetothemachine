#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
    copy(istreambuf_iterator<char>(cin), istreambuf_iterator<char>(), ostreambuf_iterator<char>(cout));
    
    cout << "Done" << endl;
    
    return EXIT_SUCCESS;
}
