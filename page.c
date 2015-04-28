#include <stdio.h>
#include <string.h>
#include <twilio.h>
#include <secrets.h>

int main(int argc, char *argv[])
{
    SendSMS("Hello, this is Michael. I am a C program!", CONFIG_PHONE_TO);
    return 0;
}
