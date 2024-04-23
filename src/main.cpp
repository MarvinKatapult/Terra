#include <stdio.h>
#include "tstring.hpp"

int main() {

    TString str( "Hello" );
    TString str2( " World!" );

    str.append( str2 );

    printf( "%s\n", str.ascii() );

    return 0;
}
