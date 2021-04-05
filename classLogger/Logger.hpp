
#ifndef _LOGGER_HPP
#define _LOGGER_HPP

#include <iostream>
#include <cassert>
#include <ctime>
#include <cstdarg>
#include <fstream>

namespace MSGS {
    /// @brief Sub-projects verbosity levels
    enum verbosity {
        ERROR        = 1,
        WARNING      = 2,
        INFO         = 3,
        SUBPROJECT1  = 1 << 2,
        SUBPROJECT2  = 1 << 3,
        SUBPROJECT3  = 1 << 4,
        SUBPROJECT4  = 1 << 5
    };
    /// @brief Simple structure representing logger messages
} // namespace MSGS

/**
 * @brief General purpose logging facility.
 *
 * The following functions available for use in the application:
 * Function name    Verbosity   Description
 *   message(...)     4+        print verbose messages
 *   info(...)        3         print information messages
 *   warning(...)     2         print warning messages
 *   error(...)       1         print error messages
 *
 * Verbosity is a runtime variable that determines what is printed.
 * Verbosity levels 4 or higher represent a bit mask, where each bit is
 * typically assigned to a subsystem. To print messages from that subsystem,
 * set the verbosity bit for it. If the bit is not set, message is not
 * printed.
 *
 * Verbosity levels 1, 2, and 3 are special and represent respectively errors,
 * warnings and infos. Setting verbosity to
 *    0   disables all messages
 *    1   enables errors
 *    2   enables errors and warnings
 *    3   enables errors, warnings and informations
 *
 * By default, verbosity is set to 3.
 */
class Logger
{
public:
    /// @brief Returns reference to the logger object
    static Logger& Get() noexcept;

    /**
     * @brief The function prints the error message type, time, message-text,
     * and end-of-line.
     * For example:
     *
     * @code
     * Logger::Error(MSGS::IXF, xml.name().c_str());
     * @endcode
     * The result message in logfile looks like the below:
     * @code
     * ERROR  [10:11:27]: Invalid XML file: design.xml
     * @endcode
     */
    /*static*/ void Error(const std::string& m, ...) noexcept;

    /**
     * @brief Method to print out warning message.
     */
    /*static*/ void Warning(const std::string& m, ...) noexcept;

    /**
     *  @brief Method to print out info message.
     */
    /*static*/ void Info(const std::string& m, ...) noexcept;

    /**
     * @brief Print out information message if the current verbosity
     * matches message level.
     *
     * @param level - level of the message
     */
    /*static*/ void Message(MSGS::verbosity level, const std::string& m, ...)
        noexcept;

    /// @name Logger verbosity and log file
public:
    /// @brief Returns current verbosity level.
    unsigned int GetVerbosity() const noexcept;

    /// @brief Sets verbosity level.
    void SetVerbosity(unsigned int level) noexcept;

private:
    unsigned int m_verbosity;
    std::ofstream m_logfile;

private:
    /**
     * @brief The only available constructor, open logger logfile.
     * @param path - path where log file must be created
     */
    Logger(const std::string& path) noexcept;

    /// @brief Destructor
    ~Logger() noexcept;

public:
    /// @name Deleted special member functions

    /// This class is not copy-constructible
    Logger(const Logger&) = delete;

    /// This class is not move-constructible
    Logger(Logger&&) = delete;

    /// This class is not copy-assignable
    Logger& operator=(const Logger&) = delete;

    /// This class is not move-assignable
    Logger& operator=(Logger&&) = delete;
};

#endif // _LOGGER_HPP

// vim:fo=croqt:cindent:expandtab:textwidth=80:tabstop=4:shiftwidth=4
