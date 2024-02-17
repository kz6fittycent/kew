#ifndef FILE_H
#define FILE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/param.h>
#include <errno.h>
#include <time.h>
#include <dirent.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <stdio.h>
#include <regex.h>
#include <pwd.h>
#include <sys/types.h>
#include "stringfunc.h"
#include "cutils.h"

#define RETRY_DELAY_MILLISECONDS 100
#define MAX_RETRY_COUNT 20
#define MAX_FILENAME_LENGTH 256

#ifndef MAXPATHLEN
#define MAXPATHLEN 4096
#endif

#ifndef AUDIO_EXTENSIONS
#define AUDIO_EXTENSIONS "\\.(m4a|aac|mp4|mp3|ogg|flac|wav|opus)$"
#endif

enum SearchType
{
        SearchAny = 0,
        DirOnly = 1,
        FileOnly = 2,
        SearchPlayList = 3,
        ReturnAllSongs = 4
};

void getDirectoryFromPath(const char *path, char *directory);

int isDirectory(const char *path);

/* Traverse a directory tree and search for a given file or directory */
int walker(const char *startPath, const char *searching, char *result,
           const char *allowedExtensions, enum SearchType searchType, bool exactSearch);

int expandPath(const char *inputPath, char *expandedPath);

int createDirectory(const char *path);

int removeDirectory(const char *path);

int deleteFile(const char *filePath);

void generateTempFilePath(const char *srcFilePath, char *filePath, const char *prefix, const char *suffix);

void deleteTempDir(void);

#endif
