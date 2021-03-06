#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <pwd.h>
#include <grp.h>
#include <algorithm>
#define MAXLINE 2048
#define MAXNUM 256

using namespace std;
char* convert(char a[]);//remain only a~z and 0~9
bool compare( char *a, char *b);//sort alphabetically
int setaprt(int argc,char**argv);
void allpt(int argc,char **argv);
int sp_dir(int argc,char**argv);

#define print1(x) cout <<((x&S_IFDIR)?"d":"-")<< ((x&S_IRUSR)?"r":"-")<< ((x&S_IWUSR)?"w":"-")<< ((x&S_IXUSR)?"x":"-")\
<< ((x&S_IRGRP)?"r":"-")<< ((x&S_IWGRP)?"w":"-")<< ((x&S_IXGRP)?"x":"-")\
<< ((x&S_IROTH)?"r":"-")<< ((x&S_IWOTH)?"w":"-")<< ((x&S_IXOTH)?"x":"-")
#define print2(x) print1(x.st_mode)<<" "<<x.st_nlink<<" "
int lpreprint(struct stat s);
int lprint(char listname[]);//print in "-l" format

int P1Dir_al(char listname0[]);//a==1,l==1,R==0
int P1Dir_l(char* listname);//a==0,l==1,R==0
#define Pfront 	DIR *dirptr = NULL;	struct dirent *entry;	struct stat s;\
	if(stat(listname,&s)!=0)\
	{\
		perror("stat goes wrong!\n");\
		exit(1);\
	}

int P1Dir_a(char* listname);
int P1Dir(char* listname);//a==0,l==0,R==0
