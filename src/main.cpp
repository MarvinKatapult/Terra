#include <stdio.h>
#include "tstring.hpp"

int main() {

    TString str( "Das ist ein toller Satz. Das ist wudnerbar. Das das" );

    str.replace( "Das", "TEST" );
    printf( "String:>%s<\n", str.ascii() );

    return 0;
}
