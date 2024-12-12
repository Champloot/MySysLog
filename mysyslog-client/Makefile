CC = gcc
CFLAGS = -Wall -Wextra -I../libmysyslog -L../libmysyslog
LDFLAGS = -lmysyslog
TARGET = mysyslog-client

all: $(TARGET)

$(TARGET): mysyslog-client.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGET)

deb:
	mkdir -p deb/mysyslog-client/usr/bin
	cp $(TARGET) deb/mysyslog-client/usr/bin/
	dpkg-deb --build deb/mysyslog-client .
