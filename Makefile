TARGET = gpio_poll

all: $(TARGET)

$(TARGET): gpio_poll.c
	$(CC) $^ -o $@

clean:
	rm -f $(TARGET)

.PHONY: clean
