#include <stdio.h>
#include <string.h>
#include <lib/twilio.h>
#include <lib/SendSMS.h>
#include <secrets.h>

int main(int argc, char *argv[])
{
    if(argc != 3) {
        printf("Usage: %s <number> \"<message>\"\n", argv[0]);
        return 1;
    } else {
        // extern int SendSMS (char *Message, char *MessageTo, char *MessageFrom, char *TwilioSID, char *TwilioToken);
        struct TwilioAccount twilio;
        twilio.SID = CONFIG_SID;
        twilio.Token = CONFIG_TOKEN;
        SendSMS(argv[2], argv[1], CONFIG_PHONE_FROM, twilio);
    }
    return 0;
}
