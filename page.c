#include <stdio.h>
#include <string.h>
#include <twilio.h>
#include <secrets.h>

int main(int argc, char *argv[])
{
    if(argc != 3) {
        printf("Usage: %s <number> \"<message>\"\n", argv[0]);
        return 1;
    } else {
        // extern int SendSMS (char *Message, char *MessageTo, char *MessageFrom, char *TwilioSID, char *TwilioToken);
        SendSMS(argv[2], argv[1], CONFIG_PHONE_FROM, CONFIG_SID, CONFIG_TOKEN);
    }
    return 0;
}
