#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("Command line arguments:\n");
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    // Display process identifiers
    pid_t pid = getpid();
    pid_t ppid = getppid();
    pid_t sid = getsid(0);
    pid_t pgid = getpgid(0);

    printf("\nProcess identifiers:\n");
    printf("PID: %d\n", pid);
    printf("PPID: %d\n", ppid);
    printf("SID: %d\n", sid);
    printf("PGID: %d\n", pgid);

    char *username = getlogin(); // get username
    printf("Username: %s\n", username);

    struct passwd *pw = getpwnam(username); // get passwd entry using username
    if (pw != NULL) {
        printf("UID: %d\n", pw->pw_uid);
        printf("GID: %d\n", pw->pw_gid);

        struct group *grp = getgrgid(pw->pw_gid);
        if (grp != NULL) {
            printf("Group: %s\n", grp->gr_name);
        } else {
            printf("Group name not found\n");
        }
    } else {
        printf("User not found\n");
    }

    return 0;
}
