#include "tstring.hpp"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_INT_LENGTH  12

TString::TString( const char * p_str ) {
    copyCString( p_str );
}

TString::TString( int p_number ) {
    myBuffer = (char *)malloc( MAX_INT_LENGTH * sizeof( char ) );
    if ( !myBuffer ) return;
    
    snprintf( myBuffer, 12, "%d", p_number );
}

TString::TString( const TString & p_str ) {
    copyCString( p_str.ascii() );
}

TString::~TString() {
    free( myBuffer );
}

void TString::append( const TString & p_str ) {
    const int start_length = strlen( myBuffer );
    const int end_length = p_str.length() + start_length;

    char * buffer = (char *)malloc( sizeof( char * ) * end_length + 1 );
    strcpy( buffer, myBuffer );

    strcat( buffer, p_str.buffer() );

    free( myBuffer );
    myBuffer = buffer;
}

const char * TString::ascii() const {
    return (const char *)myBuffer;
}

int TString::toInt() const {
    return strtol( ascii(), 0L, 10 );
}

int TString::length() const {
    unsigned int count = 0;
    char * current = myBuffer;
    while( *current != '\0' ) {
        current++;
        count++;
    }
    return count;
}

void TString::copyCString( const char * p_str ) {
    myBuffer = (char *)malloc( sizeof( char * ) * strlen( p_str ) + 1 );
    if ( !myBuffer ) return;
    strcpy( myBuffer, p_str );
}
