/*
 * Defines logging macros.
 */

#ifndef _LOGGING_H_
#define _LOGGING_H_

#define LOG_LEVEL_DEBUG  1
#define LOG_LEVEL_INFO   2
#define LOG_LEVEL_WARN   3
#define LOG_LEVEL_ERROR  4
#define LOGGING_DISABLED 5

#ifndef LOGLEVEL
#define LOGLEVEL LOG_LEVEL_INFO
#endif

#ifndef LOG_COLOR_DEBUG
#define LOG_COLOR_DEBUG "\033[2m" /* dim text */ 
#endif

#ifndef LOG_COLOR_INFO
#define LOG_COLOR_INFO "\033[96m" /* light cyan */ 
#endif

#ifndef LOG_COLOR_WARN
#define LOG_COLOR_WARN "\033[93m" /* yellow */ 
#endif

#ifndef LOG_COLOR_ERROR
#define LOG_COLOR_ERROR "\033[91m" /* light red */ 
#endif

#ifndef LOGGING_NO_COLOR
#define LOGPRINTF(color, fmt, ...) {printf(color fmt "\033[0m\n" __VA_OPT__(,)  __VA_ARGS__); fflush(stdout);}
#else
#define LOGPRINTF(color, fmt, ...) {printf(fmt "\n" __VA_OPT__(,) __VA_ARGS__); fflush(stdout);}
#endif

#ifdef EMBEDDED

#define NRF_LOG_ENABLED 1

#define _LOG_DEBUG(...)  NRF_LOG_DEBUG(__VA_ARGS__)
#define _LOG_INFO(...)   NRF_LOG_INFO(__VA_ARGS__)
#define _LOG_WARN(...)   NRF_LOG_WARN(__VA_ARGS__)
#define _LOG_ERROR(...)  NRF_LOG_ERROR(__VA_ARGS__)

#elif NATIVE

#include <cstdio>

#define _LOG_DEBUG(fmt, ...)  LOGPRINTF(LOG_COLOR_DEBUG, "[D] " fmt, __VA_ARGS__)
#define _LOG_INFO(fmt, ...)   LOGPRINTF(LOG_COLOR_INFO,  "[I] " fmt, __VA_ARGS__)
#define _LOG_WARN(fmt, ...)   LOGPRINTF(LOG_COLOR_WARN,  "[W] " fmt, __VA_ARGS__)
#define _LOG_ERROR(fmt, ...)  LOGPRINTF(LOG_COLOR_ERROR, "[E] " fmt, __VA_ARGS__)

#endif

#if LOGLEVEL <= LOG_LEVEL_DEBUG
#define LOG_DEBUG(...) _LOG_DEBUG(__VA_ARGS__)
#else
#define LOG_DEBUG(...) {}
#endif

#if LOGLEVEL <= LOG_LEVEL_INFO
#define LOG_INFO(...) _LOG_INFO(__VA_ARGS__)
#else
#define LOG_INFO(...) {}
#endif

#if LOGLEVEL <= LOG_LEVEL_WARN
#define LOG_WARN(...) _LOG_WARN(__VA_ARGS__)
#else
#define LOG_WARN(...) {}
#endif

#if LOGLEVEL <= LOG_LEVEL_ERROR
#define LOG_ERROR(...) _LOG_ERROR(__VA_ARGS__)
#else
#define LOG_ERROR(...) {}
#endif

#endif
