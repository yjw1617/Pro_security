CROSS_COMPILE=
CC=$(CROSS_COMPILE)gcc
CFLAGS = -g -c
LDFLAGS = -lpthread

OBJS = main.o mes.o tool.o pthread_led.o

my_app: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)
	mv *.o ./OUT

$(OBJS):%.o:%.c
	$(CC) $(CFLAGS) $<

.PHONY:clean
clean:
	rm app ./OUT/*.o  *.o -rf