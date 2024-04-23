#include <tlog.hpp>

#include <stdio.h>
#include <stdarg.h>

TLog::TLog() {
    myLogLevel = TLogDebug;
    myLogColor = TLogDefault;
    myFile = stdout;
}

TLog::TLog( TLogLevel p_log_level, TLogColor p_log_color ) 
    : myLogLevel( p_log_level ), myLogColor( p_log_color ) { 
    myFile = stdout;
}

TLog::TLog( const char * p_file_path, bool p_clear_file, TLogColor p_log_color ) 
    : myLogColor( p_log_color ) {
    myLogLevel = TLogDebug; 

    const char * mode = p_clear_file ? "w" : "a";
    myFile = fopen( p_file_path, mode );
}

TLog::~TLog() {
    if ( !myFile ) fclose( myFile );
}

bool TLog::print( const char * p_format, ... ) {
    setColorForLogLevel();

    // Print
    va_list args;
    va_start( args, p_format );
    bool ret = vfprintf( myFile, p_format, args ) >= 0;
    va_end( args );

    resetColor();
    return ret;
}

bool TLog::print( TLogColor p_color, const char * p_format, ... ) {

    // Print
    setColor( p_color );
    va_list args;
    va_start( args, p_format );
    bool ret = vfprintf( myFile, p_format, args ) >= 0;
    va_end( args );
    resetColor();

    return ret;
}

bool TLog::print( TLogLevel p_level, const char * p_format, ... ) {

    myLogLevel = p_level;
    setColorForLogLevel();
    // Print
    va_list args;
    va_start( args, p_format );
    bool ret = vfprintf( myFile, p_format, args ) >= 0;
    va_end( args );
    resetColor();

    return ret;
}

void TLog::setColor( TLogColor p_color ) {
    if ( myFile != stdout && myFile != stderr ) return;
    switch ( p_color ) {
        case TLogDefault:
            resetColor();
            break;
        case TLogBlack:
            fprintf( myFile, "\033[0;30m" );
            break;
        case TLogRed:
            fprintf( myFile, "\033[0;31m" );
            break;
        case TLogGreen:
            fprintf( myFile, "\033[0;32m" );
            break;
        case TLogYellow:
            fprintf( myFile, "\033[0;33m" );
            break;
        case TLogBlue:
            fprintf( myFile, "\033[0;34m" );
            break;
        case TLogPurple:
            fprintf( myFile, "\033[0;35m" );
            break;
        case TLogCyan:
            fprintf( myFile, "\033[0;36m" );
            break;
        case TLogWhite:
            fprintf( myFile, "\033[0;37m" );
            break;
    }
}

void TLog::resetColor() {
    if ( myFile != stdout && myFile != stderr ) return;
    fprintf( myFile, "\033[0m" );
}

void TLog::setColorForLogLevel() {
    switch ( myLogLevel ) {
        case TLogDebug:
            setColor( TLogBlue );
            break;
        case TLogWarning:
            setColor( TLogYellow );
            break;
        case TLogError:
            setColor( TLogRed );
            break;
    }
}
