#include <stdio.h>
#include "include/utils.h"

void display_menu() {
    printf("================================================\n");
    ascii_title();
    printf("© 2024 tr41z\n");
    printf("Language used: C\n");
    printf("Github Repo: https://github.com/tr41z/ciscan\n");
    printf("================================================\n\n");
}

void ascii_title() {
    printf(
       "       _                         \n"
       "      (_)                        \n"
       "  ___  _  ___   ___  __ _  _ __  \n"
       " / __|| |/ __| / __|/ _` || '_ \\ \n"
       "| (__ | |\\__ \\| (__| (_| || | | |\n"
       " \\___||_||___/ \\___|\\__,_||_| |_| \n"
       "                                 \n"
    );
}