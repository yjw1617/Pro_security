# CC=arm-none-linux-gnueabi-gcc
 CC=gcc
AFLAGS=-Wall -g
LDFLAGS= -L ./lib -ljson-c
OBJS= capture.cgi a9_beep.cgi zigbee_fan.cgi\
	  a9_led.cgi a9_seg.cgi \
	  env1.cgi setEnv.cgi\
	  cgi_led.cgi
run:$(OBJS)

$(OBJS):%.cgi:%.c
	$(CC) $(AFLAGS) $< cgic.c -o $@ $(LDFLAGS)
	
install:
	$(CC) $(AFLAGS) login.c -o login.cgi
	mv *.cgi ./out/
	sudo cp  ./out/*.cgi  /boa/cgi-bin

.PHONY:clean
clean:
	rm ./out/*.cgi

