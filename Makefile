all:
	gcc -O2 -Wall -c -fpic lib/SendSMS.c -o lib/SendSMS.o
	gcc -O2 -Wall -shared -o libtwilio.so lib/SendSMS.o
	gcc page.c -O2 -Wall -lcurl -L./ -I./ -ltwilio -o page

page:
	gcc page.c -lcurl -L./ -I./ -ltwilio -o page

twilio:
	gcc -c -fpic lib/SendSMS.c -o lib/SendSMS.o
	gcc -shared -o libtwilio.so lib/SendSMS.o

clean:
	rm page
	rm lib/SendSMS.o
	rm libtwilio.so

asm:
	gcc -O2 -Wall -c -fpic -S lib/SendSMS.c -o lib/SendSMS.s
	gcc page.c -O2 -Wall -lcurl -L./ -I./ -ltwilio -S -o page.s

