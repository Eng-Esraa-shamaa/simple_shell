#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

/**
 * struct list_s - lista
 * @str: str
 * @next: next
 */

typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

/* String Functions */
int _strlen(const char *s);
char *_strdup(const char *str);
int _strcmp(const char *s1, const char *s2);
char *str_concat(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strtok(char *str, char delim);
int _strncmp(const char *str1, const char *str2, size_t n);

char *_get_env(const char *var);
char *get_path(char *file_name);
char *_strncpy(char *dest, char *src, int n);
char *searchAndReplace(char *str);
char *_create_var(char *name, char *val);
char **tokenize(char *str, int bin);
char *addTilde(char *path);
char *_search_remove(char *str);
char *_clear_buf(char *str, int sum);
char *_check_com(char *str);
int _check_ch(char *str);
int exists(char *path);
int _set_env(char *var, char *val, int ow);
int _check_unset(char *str);
int _check_set_env(char *str);
int _check_help(char *str);
int _unset_env(char *var);
int _atoi(char *s);
int _check_cd(char *str);
int args(char *str);
int _check_bin(char *str);
int _child_fork(pid_t child_pid, char *pro);
int _check_env(char *str);
int _check_exe(char *path);
int _check_dir(const char *path);
int getLineAndCheck(char *str);
int _check_dig(char *str);
int _check_exit(char *str);
int checkRoute(char *str);
int _get_ret(char *str);
void free_buff_env(char *str);
void _help_case(char *var);
void free_env(char *var);
void _sh(int sn);
void _check_isatty_sig(void);
void _print_env(void);
void wait_free(int status, char **argv, char *dup);
void free_dup_arr(char **arr, char *dup);
void free_exit(char *str);
#endif
