# gpio_poll

This is Linux GPIO polling example:

```
$ echo 403 > /sys/class/gpio/export
$ echo both > /sys/class/gpio/gpio403/edge
$ ./gpio_poll 403
value: 1
value: 1 -> 0
value: 0 -> 1
value: 1 -> 0
value: 0 -> 1
value: 1 -> 0
value: 0 -> 1
...
```
