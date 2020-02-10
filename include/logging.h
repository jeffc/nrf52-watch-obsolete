/*
 * Defines logging macros.
 */

#ifndef _LOGGING_H_
#define _LOGGING_H_

#define LOGGING_DISABLED 0
#define LOG_LEVEL_DEBUG  1
#define LOG_LEVEL_INFO   2
#define LOG_LEVEL_WARN   3
#define LOG_LEVEL_ERROR  4

#ifndef LOGLEVEL
#define LOGLEVEL LOG_LEVEL_INFO
#endif

#ifdef EMBEDDED

#define _LOG_DEBUG(...)  NRF_LOG_DEBUG(__VA_ARGS__)
#define _LOG_INFO(...)   NRF_LOG_INFO(__VA_ARGS__)
#define _LOG_WARN(...)   NRF_LOG_WARN(__VA_ARGS__)
#define _LOG_ERROR(...)  NRF_LOG_ERROR(__VA_ARGS__)

#elif NATIVE

#include <cstdio>

#define _LOG_DEBUG(...)  {printf("[D] " __VA_ARGS__); fflush(stdout);}
#define _LOG_INFO(...)   {printf("[I] " __VA_ARGS__); fflush(stdout);}
#define _LOG_WARN(...)   {printf("[W] " __VA_ARGS__); fflush(stdout);}
#define _LOG_ERROR(...)  {printf("[E] " __VA_ARGS__); fflush(stdout);}

#endif

#if LOGLEVEL >= LOG_LEVEL_DEBUG
#define LOG_DEBUG(...) _LOG_DEBUG(__VA_ARGS__)
#else
#define LOG_DEBUG {}
#endif

#if LOGLEVEL >= LOG_LEVEL_INFO
#define LOG_INFO(...) _LOG_INFO(__VA_ARGS__)
#else
#define LOG_INFO {}
#endif

#if LOGLEVEL >= LOG_LEVEL_WARN
#define LOG_WARN(...) _LOG_WARN(__VA_ARGS__)
#else
#define LOG_WARN {}
#endif

#if LOGLEVEL >= LOG_LEVEL_ERROR
#define LOG_ERROR(...) _LOG_ERROR(__VA_ARGS__)
#else
#define LOG_ERROR {}
#endif

#endif
