CC = gcc
CFLAGS = -fPIC -shared -Wall -Wextra
TARGET = libmysyslog.so

all: $(TARGET)

$(TARGET): libmysyslog.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

deb:
	mkdir -p deb/libmysyslog/usr/lib
	cp $(TARGET) deb/libmysyslog/usr/lib/
	dpkg-deb --build deb/libmysyslog .
