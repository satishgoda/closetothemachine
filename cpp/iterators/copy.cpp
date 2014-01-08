#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <cstdlib>

void doCopy(const std::string infilename, const std::string outfilename={})
{
    using namespace std;
    using CharInputStreamBufIter = istreambuf_iterator<char>;
    using CharOutputStreamBufIter = ostreambuf_iterator<char>;
    
    ifstream infile { infilename };
    
    if(!infile) {
        cout << "Unable to open input file: " << infilename << endl;
        exit(1);
    }
    
    ofstream outfile { };
    ostream *output = nullptr;
    
    if( outfilename.empty() ) {
        output = &cout;
        
        cout << "Copying text to standard output instead.." << endl;
    } 
    else {
        outfile.open(outfilename);
        
        if(!outfile) {
            cout << "Unable to open output file: " << outfilename << endl;
            exit(1);
        }
        
        output = &outfile;
        
        cout << infilename << " -> " << outfilename << endl;
    }
    
    copy(CharInputStreamBufIter(infile), CharInputStreamBufIter(), CharOutputStreamBufIter(*output));
}

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
            
            doCopy(argv[1]);
        break;
        
        case 3:
            doCopy(argv[1], argv[2]);
        break;
        
        default:
            cout << "Should we even reach here?" << endl;
        break;
    }
    
    return EXIT_SUCCESS;
}

