#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <cstdlib>

int main(int argc, char *argv[])
{
    using namespace std;
    
    switch (argc) {
        case 1:
            cout << argv[0] << ": missing file operand" << endl;
            exit(EXIT_FAILURE);
        break;
        
        case 2:
            cout << argv[0] << ":  missing destination file operand after " << argv[1] << endl;
            exit(EXIT_FAILURE);
        break;
        
        case 3:
        {
            cout << argv[1] << " -> " << argv[2] << endl;
            
            ifstream infile { argv[1] };
            ofstream outfile { argv[2] };
            
            string fileData { istreambuf_iterator<char>(infile), istreambuf_iterator<char>() };
            
            copy(fileData.begin(), fileData.end(), ostreambuf_iterator<char>(outfile));
        }
        break;
        
        default:
            cout << "Should we even reach here?" << endl;
        break;
    }
    
    return EXIT_SUCCESS;
}
