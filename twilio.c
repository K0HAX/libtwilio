#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

#include "secrets.h"

// Twilio requires the SID inside the URL, this function is private.
void BuildURL(char *src, char *dst)
{
    dst[0] = 0;
    strcat(dst, "https://api.twilio.com/2010-04-01/Accounts/");
    strcat(dst, src);
    strcat(dst, "/SMS/Messages");
}

// This function is exposed to the library.
int SendSMS(char *Message, char *MessageTo)
{
    CURL *curl;
    CURLcode res;

    struct curl_httppost *formpost=NULL;
    struct curl_httppost *lastptr=NULL;
    struct curl_slist *headerlist=NULL;
    static const char buf[] = "Expect:";

    curl_global_init(CURL_GLOBAL_ALL);

    /* Fill in the from field */
    curl_formadd(&formpost,
            &lastptr,
            CURLFORM_COPYNAME, "From",
            CURLFORM_COPYCONTENTS, CONFIG_PHONE_FROM,
            CURLFORM_END);

    /* Fill in the to field */
    curl_formadd(&formpost,
            &lastptr,
            CURLFORM_COPYNAME, "To",
            CURLFORM_COPYCONTENTS, MessageTo,
            CURLFORM_END);

    /* Fill in the message */
    curl_formadd(&formpost,
            &lastptr,
            CURLFORM_COPYNAME, "Body",
            CURLFORM_COPYCONTENTS, Message,
            CURLFORM_END);

    curl = curl_easy_init();
    headerlist = curl_slist_append(headerlist, buf);
    if(curl) {
        // Initialize the URL with something large.
        char TwilioURL[512];
        BuildURL(CONFIG_SID, TwilioURL);

        curl_easy_setopt(curl, CURLOPT_URL, TwilioURL);
        curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
        curl_easy_setopt(curl, CURLOPT_USERNAME, CONFIG_SID);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, CONFIG_TOKEN);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        /* always clean up */
        curl_easy_cleanup(curl);
        curl_formfree(formpost);
        curl_slist_free_all(headerlist);
    }

    return 0;
}
