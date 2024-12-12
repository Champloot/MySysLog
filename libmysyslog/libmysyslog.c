#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "libmysyslog.h"

static const char* log_level_to_string(int level) {
    switch (level) {
        case DEBUG: return "DEBUG";
        case INFO: return "INFO";
        case WARN: return "WARN";
        case ERROR: return "ERROR";
        case CRITICAL: return "CRITICAL";
        default: return "UNKNOWN";
    }
}

static int write_text_format(FILE* file, const char* msg, int level, const char* process) {
    time_t now = time(NULL);
    fprintf(file, "%ld %s %s %s\n", now, log_level_to_string(level), process, msg);
    return 0;
}

static int write_json_format(FILE* file, const char* msg, int level, const char* process) {
    time_t now = time(NULL);
    fprintf(file, "{\"timestamp\":%ld,\"log_level\":\"%s\",\"process\":\"%s\",\"message\":\"%s\"}\n",
            now, log_level_to_string(level), process, msg);
    return 0;
}

int mysyslog(const char* msg, int level, int driver, int format, const char* path, const char* process) {
    FILE* file = fopen(path, "a");
    if (!file) {
        perror("Failed to open log file");
        return -1;
    }

    int result;
    if (format == FORMAT_TEXT) {
        result = write_text_format(file, msg, level, process);
    } else if (format == FORMAT_JSON) {
        result = write_json_format(file, msg, level, process);
    } else {
        fprintf(stderr, "Unknown format\n");
        result = -1;
    }

    fclose(file);
    return result;
}
