#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

void scanDir(char *path)
{
    DIR *d = opendir(path);
    struct dirent *dir;
    struct stat st;
    if (!d)
    {
        printf("Cannot open directory\n");
        return;
    }
    while ((dir = readdir(d)) != NULL)
    {
        if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
            continue;
        stat(dir->d_name, &st);
        if (S_ISDIR(st.st_mode))
            printf("[DIR] %s\n", dir->d_name);
        else
            printf("[FILE] %s (%ld bytes)\n", dir->d_name, st.st_size);
    }
    closedir(d);
}

int main()
{
    char path[100];
    printf("Enter directory path (or . for current): ");
    scanf("%s", path);
    scanDir(path);
    return 0;
}
