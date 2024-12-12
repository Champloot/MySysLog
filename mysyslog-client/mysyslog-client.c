#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libmysyslog.h"

int main(int argc, char* argv[]) {
    char *msg = NULL, *path = NULL;
    int level = INFO, driver = DRIVER_TEXT, format = FORMAT_TEXT;
    int opt;

    while ((opt = getopt(argc, argv, "m:l:d:f:p:")) != -1) {
        switch (opt) {
            case 'm': msg = optarg; break;
            case 'l': level = atoi(optarg); break;
            case 'd': driver = atoi(optarg); break;
            case 'f': format = atoi(optarg); break;
            case 'p': path = optarg; break;
            default:
                fprintf(stderr, "Usage: %s -m message -l level -d driver -f format -p path\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    if (!msg || !path) {
        fprintf(stderr, "Message and path are required.\n");
        exit(EXIT_FAILURE);
    }

    if (mysyslog(msg, level, driver, format, path, argv[0]) != 0) {
        fprintf(stderr, "Failed to write to syslog.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
