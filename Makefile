all:
	gcc -c -fpic twilio.c
	gcc -shared -o libtwilio.so twilio.o
	gcc page.c -lcurl -L./ -I./ -ltwilio -o page

page:
	gcc page.c -lcurl -L./ -I./ -ltwilio -o page

twilio:
	gcc -c -fpic twilio.c
	gcc -shared -o libtwilio.so twilio.o

clean:
	rm page
	rm twilio.o
	rm libtwilio.so
