#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <readline/history.h>
#include <readline/readline.h>

#include "ui.h"

char *ui_read_command(void) {
    char *input;
    while (1) {
        input = readline("sdb > ");
        if (input == NULL)
            return NULL;
        if (strlen(input) > 0) {
            add_history(input);
            return input;
        }
        free(input);
    }
}

const command_t *ui_find_command(const char *name, const command_t *commands) {
    for (int i = 0; commands[i].name != NULL; i++) {
        if (strcmp(name, commands[i].name) == 0)
            return &commands[i];
    }
    return NULL;
}

void ui_print_help(const command_t *commands) {
    printf("Helper:\n");
    for (int i = 0; commands[i].name != NULL; i++)
        printf("  %-8s - %s\n", commands[i].name, commands[i].help);
}

void logo_putout(){
    puts("    .oooooo..o oooooooooo.   oooooooooo.  ");
    puts("   d8P'    `Y8 `888'   `Y8b  `888'   `Y8b ");
    puts("   Y88bo.       888      888  888     888 ");
    puts("    `Y8888o.    888      888  888oooo888' ");
    puts("         `Y88b  888      888  888    `88b ");
    puts("   oo     .d8P  888     d88'  888    .88P ");
    puts("   8^`88888P'  o888bood8P'   o888bood8P'  ");
    puts("                                       ");
}
