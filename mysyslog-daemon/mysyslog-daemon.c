#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "libmysyslog.h"

static volatile int running = 1;

void handle_signal(int signal) {
    if (signal == SIGTERM || signal == SIGHUP) {
        running = 0;
    }
}

int main(int argc, char* argv[]) {
    signal(SIGTERM, handle_signal);
    signal(SIGHUP, handle_signal);

    const char* path = "/var/log/mysyslog.log";
    int format = FORMAT_TEXT, driver = DRIVER_TEXT;

    while (running) {
        mysyslog("Daemon is running", INFO, driver, format, path, argv[0]);
        sleep(10);
    }

    return 0;
}
