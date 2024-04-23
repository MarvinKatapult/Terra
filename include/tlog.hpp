#pragma once

typedef struct _IO_FILE FILE;

class TLog {
    
    public:

        enum TLogLevel {
            TLogDebug,
            TLogWarning,
            TLogError
        };

        enum TLogColor {
            TLogBlack,
            TLogRed,
            TLogGreen,
            TLogYellow,
            TLogBlue,
            TLogPurple,
            TLogCyan,
            TLogWhite,
            TLogDefault
        };

        /** Constructors **/
        TLog( void );
        TLog( TLogLevel log_level, TLogColor log_color = TLogDefault );
        TLog( const char * file_path, bool clear_file = true, TLogColor color = TLogDefault );

        /** Deconstructor **/
        ~TLog( void );

        /** Utils **/
        bool print( const char * format, ... ); 
        bool print( TLogColor color, const char * format, ... );
        bool print( TLogLevel level, const char * format, ... );

    private:

        void resetColor( void );
        void setColorForLogLevel( void );
        void setColor( TLogColor color );

        FILE * myFile;
        TLogLevel myLogLevel;
        TLogColor myLogColor;
};
