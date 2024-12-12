CC = gcc
CFLAGS = -Wall -Wextra -I../libmysyslog -L../libmysyslog
LDFLAGS = -lmysyslog
TARGET = mysyslog-daemon

all: $(TARGET)

$(TARGET): mysyslog-daemon.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGET)

deb:
	mkdir -p deb/mysyslog-daemon/usr/bin
	cp $(TARGET) deb/mysyslog-daemon/usr/bin/
	dpkg-deb --build deb/mysyslog-daemon .
