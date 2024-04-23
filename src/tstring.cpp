#include "tstring.hpp"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_LONG_LENGTH  20

TString::TString() {
    initializeBuffer();
}

TString::TString( const char * p_str ) {
    initializeBuffer();
    copyCString( p_str );
}

TString::TString( char p_character ) {
    myBuffer = (char *)malloc( sizeof( char * ) * 2 );
    myBuffer[0] = p_character;
    myBuffer[1] = '\0';
}

TString::TString( int p_number ) {
    myBuffer = convertNumberToString( p_number );
}

TString::TString( long p_number ) {
    myBuffer = convertNumberToString( p_number );
}

TString::TString( const TString & p_str ) {
    initializeBuffer();
    copyCString( p_str.ascii() );
}

void TString::initializeBuffer() {
    myBuffer = (char *)malloc( sizeof( char * ) );
    myBuffer[0] = '\0';
}

char * TString::convertNumberToString( long p_number ) {
    char * buffer = (char *)malloc( MAX_LONG_LENGTH * sizeof( char ) );
    if ( !buffer ) return NULL;
    snprintf( buffer, 12, "%ld", p_number );

    return buffer;
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

void TString::prepend( const TString & p_str ) {
    const int start_length = strlen( myBuffer );
    const int end_length = p_str.length() + start_length;

    char * buffer = (char *)malloc( sizeof( char * ) * end_length + 1 );
    strcpy( buffer, p_str.buffer() );
    
    strcat( buffer, myBuffer );

    free( myBuffer );
    myBuffer = buffer;
}

void TString::replace( const TString & p_r_str, const TString & p_d_str ) {
    // TODO
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

TString TString::toLower() const {
    char * buffer = (char *)malloc( sizeof( myBuffer ) * length() + 1 );
    for ( int i = 0; i < length() + 1; i++ ) {
        buffer[i] = tolower( myBuffer[i] ); 
        if ( i == length() ) buffer[i] = '\0';
    }

    return TString( buffer );
}

TString TString::toUpper() const {
    char * buffer = (char *)malloc( sizeof( myBuffer ) * length() + 1 );
    for ( int i = 0; i < length() + 1; i++ ) {
        buffer[i] = toupper( myBuffer[i] ); 
        if ( i == length() ) buffer[i] = '\0';
    }

    return TString( buffer );
}

bool TString::contains( const TString & p_str ) const {
    return strstr( myBuffer, p_str.ascii() ) != NULL;
}

int TString::find( const TString & p_str ) const {
    char * found = strstr( myBuffer, p_str.ascii() );
    if ( !found ) return -1;

    return found - myBuffer;
}

char TString::character( int p_position ) const {
    if ( p_position > length() ) return '\0';
    return myBuffer[p_position];
}

void TString::copyCString( const char * p_str ) {
    free( myBuffer );

    myBuffer = (char *)malloc( sizeof( char * ) * strlen( p_str ) + 1 );
    if ( !myBuffer ) return;
    strcpy( myBuffer, p_str );
}

void TString::operator+=( const TString & str ) {
    append( str );
}

bool TString::operator==( const TString & str ) const {
    return strcmp( ascii(), str.ascii() ) == 0;
}

void TString::operator=( const TString & str ) {
    copyCString( str.ascii() );
}

char TString::operator[]( int p_index ) const {
    return character( p_index );
}
