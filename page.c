#include <stdio.h>
#include <string.h>
#include <twilio.h>
#include <secrets.h>

int main(int argc, char *argv[])
{
    // extern int SendSMS (char *Message, char *MessageTo, char *MessageFrom, char *TwilioSID, char *TwilioToken);
    SendSMS("Hello, this is Michael. I am a C program!", CONFIG_PHONE_TO, CONFIG_PHONE_FROM, CONFIG_SID, CONFIG_TOKEN);
    return 0;
}
