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

        /**
         * @brief Constructor
         */
        TLog( void );

        /**
         * @brief Constructor
         * @param log_level Loglevel
         * @param log_color Logcolor
         */
        TLog( TLogLevel log_level, TLogColor log_color = TLogDefault );

        /**
         * @brief Constructor
         * @param file_path Filepath
         * @param clear_file If true, clears file before writing
         * @param color Logcolor
         */
        TLog( const char * file_path, bool clear_file = true, TLogColor color = TLogDefault );

        /**
         * @brief Deconstructor
         */
        ~TLog( void );

        /**
         * @brief Prints to set file
         * @param format Format
         * @return true, if successful, otherwise false
         */
        bool print( const char * format, ... ); 

        /**
         * @brief Prints to set file with color
         * @param color Color
         * @param format Format
         * @return true, if successful, otherwise false
         */
        bool print( TLogColor color, const char * format, ... );

        /**
         * @brief Prints to set file with loglevel
         * @param level Loglevel
         * @param format Format
         * @return true, if successful, otherwise false
         */
        bool print( TLogLevel level, const char * format, ... );

    private:

        /**
         * @brief Resets the color with ascii sequence
         */
        void resetColor( void );

        /**
         * @brief Sets the color for set Loglevel
         */
        void setColorForLogLevel( void );

        /**
         * @brief Sets Color with ascii sequence
         * @param color Color
         */
        void setColor( TLogColor color );

        FILE * myFile;
        TLogLevel myLogLevel;
        TLogColor myLogColor;
};
