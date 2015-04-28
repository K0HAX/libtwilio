# libtwilio
A C library to send SMS messages using Twilio

Compiling
---------
* Update secrets.h to match your twilio credentials
* Run ```make```

Running
-------
Use ```./runit.sh``` to run the page program.  
Runit is a simple script to include $PWD in the LD_LIBRARY_PATH so page can find the library as it's dynamically linked.
