#include <stdio.h>
#include <regex.h>

int validateEmail(const char *email) {
    regex_t regex;
    int reti;

 
    char pattern[] = "^[a-zA-Z0-9._%+-]+@[a-z0-9.-]+\\.[a-z]{2,}$";

    
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) 
    {
        printf("Could not compile regex\n");
        return -1;
    }

    reti = regexec(&regex, email, 0, NULL, 0);
    regfree(&regex);

    if (!reti) 
    {
        return 0;
    } 
    else if (reti == REG_NOMATCH) 
    {
        return -1; 
    } 
    else 
    {
        char error_message[100];
        regerror(reti, &regex, error_message, sizeof(error_message));
        printf("Regex match failed: %s\n", error_message);
        return -1;
    }
}

int main() {
    const char *emails[] = {
        "hello@example.com",
        "hello@example.org",
        "mail2friend\"@hi5.com",
        "mail2admin\"@Prog.org",
        "guest_user@example.in",
        "guest.user@example.com"
    };
    int numEmails = sizeof(emails) / sizeof(emails[0]);

    for (int i = 0; i < numEmails; i++) {
        int result = validateEmail(emails[i]);
        printf("%s: %s\n", emails[i], (result == 0) ? "Valid" : "Invalid");
    }

    return 0;
}