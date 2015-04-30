all:
	gcc -c -fpic lib/SendSMS.c -o lib/SendSMS.o
	gcc -shared -o libtwilio.so lib/SendSMS.o
	gcc page.c -lcurl -L./ -I./ -ltwilio -o page

page:
	gcc page.c -lcurl -L./ -I./ -ltwilio -o page

twilio:
	gcc -c -fpic lib/SendSMS.c -o lib/SendSMS.o
	gcc -shared -o libtwilio.so lib/SendSMS.o

clean:
	rm page
	rm lib/SendSMS.o
	rm libtwilio.so
