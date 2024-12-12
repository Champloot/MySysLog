#ifndef LIBMYSYSLOG_H
#define LIBMYSYSLOG_H

#define DEBUG 0
#define INFO 1
#define WARN 2
#define ERROR 3
#define CRITICAL 4

#define DRIVER_TEXT 0
#define DRIVER_JSON 1

#define FORMAT_TEXT 0
#define FORMAT_JSON 1

int mysyslog(const char* msg, int level, int driver, int format, const char* path, const char* process);

#endif
