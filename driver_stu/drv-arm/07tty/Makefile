ARM_CFLAGS := -static 

all: tty01 tty02
all-arm: tty01-arm tty02-arm

tty01: tty01.c
	gcc -o $@ $<
tty02: tty02.c
	gcc -o $@ $<

tty01-arm: tty01.c
	arm-linux-gcc -o $@ $< $(ARM_CFLAGS)
tty02-arm: tty02.c
	arm-linux-gcc -o $@ $< $(ARM_CFLAGS)

install:
	adb remount
	adb push tty01-arm /system/bin/
	adb push tty02-arm /system/bin/
clean:
	rm -f *~ *.o tty01 tty02 tty01-arm tty02-arm


