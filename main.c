//
//  main.c
//  codegroups
//
//  Copyright (C) 2018 Michael Budiansky. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are permitted
// provided that the following conditions are met:
//
// Redistributions of source code must retain the above copyright notice, this list of conditions
// and the following disclaimer.
//
// Redistributions in binary form must reproduce the above copyright notice, this list of conditions
// and the following disclaimer in the documentation and/or other materials provided with the
// distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
// FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
// WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void code_groups(int groups_per_row, int group_count, bool numbers_only);
void license(void);
void man_page_source(void);

int main(int argc, const char * argv[]) {
    bool error = false;
    bool silent = false;
    bool numbers_only = false;
    int groups_per_row = 8;
    int group_count = 32;
    
    srand((unsigned int)time(NULL));
    
    for (int index = 1; index < argc && !error; index++) {
        //  -c groups_per_row
        if (strcmp(argv[index], "-c") == 0 && index + 1 < argc) {
            groups_per_row = atoi(argv[++index]);
            error = groups_per_row < 1 || groups_per_row > 100;
            
        //  -n number of groups
        } else if (strcmp(argv[index], "-n") == 0 && index + 1 < argc) {
            group_count = atoi(argv[++index]);
            error = group_count < 1 || group_count > 1000;
            
        //  --numbers numbers only
        } else if (strcmp(argv[index], "--numbers") == 0) {
            numbers_only = true;

       //  -v --version    print version of codegroups
        } else if ((strcmp(argv[index], "--version") == 0) ||
                   (strcmp(argv[index], "-v") == 0)) {
            printf("codegroups 0.9.1\n");
            silent = true;;
            
        //  -h --help       print help for codegroups
        } else if ((strcmp(argv[index], "--help") == 0) ||
                   (strcmp(argv[index], "-h") == 0)) {
            printf("Generates a series of random 5-character code groups.\n"
                   "Usage:\n"
                   "  codegroups [-c <groups_per_row] [-n <number_of_groups>]\n"
                   "  codegroups -h | --help\n"
                   "  codegroups -v | --version\n"
                   "  codegroups --license\n"
                   "  codegroups --man-page\n"
                   "\n"
                   "Options:\n"
                   "  -c <groups_per_row>     Number of groups per row [default: 8]\n"
                   "  -n <number_of_groups>     Number of groups to print [default: 32]\n"
                   "  -h --help     Show this screen.\n"
                   "  --version     Show version.\n"
                   "  --license     Show software copyright and license\n"
                   "  --man_page    Show source for man page\n");
            silent = true;

        //  --man-page      print source for man page
        } else if (strcmp(argv[index], "--man-page") == 0) {
            man_page_source();
            silent = true;

        //  --licence       print copyright and license
        } else if (strcmp(argv[index], "--license") == 0) {
            license();
            silent = true;;

        } else {
            error = true;
        }
    }
    
    if (silent) {
        
    } else if (error) {
        fprintf(stderr, "Error: invalid options\n");
        
    } else {
        code_groups(groups_per_row, group_count, numbers_only);
    }

    return error ? 1 : 0;
}

void code_groups(int groups_per_row, int group_count, bool numbers_only)
{
    char *chars = numbers_only ? "0123456789" : "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890.,?/=+*";
    size_t nchars = strlen(chars);
    
    for (int k = 1; k <= group_count; k++) {
        for (int i = 0; i < 5; i++) {
            int index =  rand() % nchars;
            printf("%c", chars[index]);
        }
        
        if (k % groups_per_row == 0 || k == group_count) {
            printf("\n");
            
        } else {
            printf(" ");
        }
    }
}
void license(void)
{
    printf("Copyright (C) 2018 Michael Budiansky. All rights reserved.\n"
           "\n"
           "Redistribution and use in source and binary forms, with or without modification, are permitted\n"
           "provided that the following conditions are met:\n"
           "\n"
           "Redistributions of source code must retain the above copyright notice, this list of conditions\n"
           "and the following disclaimer.\n"
           "\n"
           "Redistributions in binary form must reproduce the above copyright notice, this list of conditions\n"
           "and the following disclaimer in the documentation and/or other materials provided with the\n"
           "distribution.\n"
           "\n"
           "THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\" AND ANY EXPRESS OR\n"
           "IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND\n"
           "FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR\n"
           "CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL\n"
           "DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,\n"
           "DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,\n"
           "WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY\n"
           "WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.\n");
}

void man_page_source(void)
{
    printf(".TH codegroups 1\n"
           "\n"
           ".SH NAME\n"
           "codegroups \\- send series of random code groups to standard output\n"
           "\n"
           ".SH SYNOPSIS\n"
           ".nf\n"
           "\\fBcodegroups\\fR [\\fB\\-c\\fR \\fIGROUPS_PER_ROW\\fR] [\\fB\\-n\\fR \\fINUMBER_OF_GROUPS\\fR]\n"
           ".fi\n"
           "\n"
           ".SH DESCRIPTION\n"
           "Generates a series of random 5-character code groups and prints to standard output. Characters are\n"
           "from the set:\n"
           ".br\n"
           "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890.,?/=+*\n"
           "\n"
           ".SH OPTIONS\n"
           "\n"
           ".TP\n"
           ".BR \\-c \" \" \\fIGROUPS_PER_ROW\\fR\n"
           "Number of code groups per row. Default is 8.\n"
           "\n"
           ".TP\n"
           ".BR \\-n \" \" \\fINUMBER_OF_GROUPS\\fR\n"
           "Total number of code groups to send. Default is 32.\n"
           "\n"
           ".TP\n"
           ".BR \\-\\-numbers\n"
           "Use numbers only.\n"
           "\n"
           ".TP\n"
           ".BR \\-\\-version\n"
           "Show version.\n"
           "\n"
           ".TP\n"
           ".BR \\-h \", \" \\-\\-help\\fR\n"
           "Show help message.\n"
           "\n"
           ".TP\n"
           ".BR \\-\\-license\n"
           "Show software copyright and license.\n"
           "\n"
           ".TP\n"
           ".BR \\-\\-man\\-page\n"
           "Show source for this man page\n"
           "\n"
           ".SH EXAMPLES\n"
           "Generate 5 rows of 5 code groups per row:\n"
           ".PP\n"
           ".nf\n"
           ".RS\n"
           "\\fBcodegroups -c 5 -n 25\\fR\n"
           ".RE\n"
           ".fi\n"
           ".PP\n"
           "\n"
           "Play 80 code groups at 16 wpm (CODEX standard):\n"
           ".PP\n"
           ".nf\n"
           ".RS\n"
           "\\fBcodegroups -n 80 | mbeep --codex-wpm 16 -i /dev/stdin -c\\fR\n"
           ".RE\n"
           ".fi\n"
           ".PP\n"
           "\n"
           ".SH SEE ALSO\n"
           ".BR mbeep (1)\n"
           "\n"
           ".SH AUTHOR\n"
           "Michael Budiansky \\fIhttps://www.7402.org/email\\fR\n"
           );
}

