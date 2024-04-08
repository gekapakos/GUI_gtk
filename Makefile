CC = gcc
CFLAGS = -g `pkg-config --cflags gtk+-2.0` `pkg-config --cflags gthread-2.0`
LIBS = -lm `pkg-config --libs gtk+-2.0` `pkg-config --libs gthread-2.0`
TARGET = ui-scrolled-canvas-skeleton
SRCS = ui-scrolled-canvas-skeleton.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LIBS)

clean:
	rm -f $(TARGET)
