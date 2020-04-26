#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(unix)
#include <unistd.h>
#define sleep(ms) usleep(ms * 1000);
#endif

#define true 1
#define false 0
typedef char bool;
typedef char int8;

void help();

int main(int argc, char *argv[])
{

    char command[100], *execPath = 0, *systemCommand = 0;

    bool w8process = false; /// wait for process to finish to run again
    int8 uoft = 1;          /// unit of measure of time (0) milliseconds (1) second (2) minute (3) hour
    double loopTime = 0;    /// standby time in milliseconds

    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0)
        {
            help();
            exit(0);
        }
        if (argv[i][0] == '-')
        {
            switch (argv[i][1])
            {
            case 't':
                loopTime = atof(argv[i + 1]);
                i++;
                break;
            case 'e':
                execPath = argv[i + 1];
                i++;
                break;
            case 'S':
                systemCommand = argv[i + 1];
                i++;
                break;

            case 'm':
                uoft = 0;
                break;

            case 's':
                uoft = 1;
                break;

            case 'M':
                uoft = 2;
                break;

            case 'H':
                uoft = 3;
                break;

            case 'w':
                w8process = true;
                break;

            default:
                printf("[x] Invalid argument: %s", argv[i]);
                printf("\n\n");
                help();
                exit(1);
            }
        }
    }

    if (!(execPath || systemCommand))
    {
        printf("[?] Missing arguments\n\n");
        help();
        exit(1);
    }

    switch (uoft)
    {
    case 1: ///second
        loopTime *= 1000;
        break;

    case 2: ///minute
        loopTime *= 60000;
        break;

    case 3: ///hour
        loopTime *= 3600000;
        break;
    }

    if (execPath && !(execPath[0] == '/' || execPath[0] == '.'))
    {
        strcpy(command, "./");
        strcat(command, execPath);
    }
    else if (execPath)
    {
        strcpy(command, execPath);
    }

    if (systemCommand)
    {
        strcpy(command, systemCommand);
    }

    if (!w8process)
    {
        strcat(command, " &");
    }

    while (true)
    {
        system(command);
        sleep(loopTime);
    }
    return 0;
}

void help()
{
    printf("Use: tasktime [options] [-e \"executable\"] <or> [-S \"system command\"]\n");
    printf("\noptions:\n");
    printf("  -m           The unit of time measurement will be in milliseconds\n");
    printf("  -s           The unit of time measurement will be in seconds\n");
    printf("  -M           The unit of time measurement will be in minutes\n");
    printf("  -H           The unit of time measurement will be in Hours\n");
    printf("  -t           Timeout for each Executable or System Command call\n");
    printf("  -w           Causes software to wait for system executable or command to complete execution until timeout\n");
    printf("  -h --help    Help\n");
    printf("\nEx: ./tasktime -s -t 2 -S ls");
    printf("\nEx: ./tasktime -s -t 2 -e examples/public_ip.sh ");
    printf("\n");
}
