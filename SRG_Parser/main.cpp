#include <iostream>
#include <fstream>
#include "SRG_File.h"
#include "SRG_Utilities.h"

int main( int argc, char** argv )
{
    if( argc > 1 ) {
        std::ofstream out( std::string( argv[ 1 ] ) + "_dump" );

        SRG_File file = SRG_File::parse_file( argv[ 1 ] );
        file.dump( out );

        out.close();
    }
    else {
        std::cout << "Usage: SRG_Parser.exe filename\n";
    }

    return 0;
}