#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

/* Free NULL-terminated list of strings. */
void ft_free_strlist(char **strings)
{
    if (strings)
    {
        char **ss = strings;

        while (*ss)
        {
            free(*ss++);
        }
        free(strings);
    }
}

char **ft_split_whitespaces(const char *input)
{
    static const char white[] = "\t\n\v\f\r ";
    size_t nwords;
    size_t i;
    size_t wordlen;
    char **words;
    const char *s;

    /* Determine number of words in input string. */
    nwords = 0;
    s = input;
    s += strspn(s, white);  /* Skip initial whitespace. */
    while (*s)
    {
        /* Found non-whitespace at beginning of word. */
        nwords++;
                s += strcspn(s, white); /* Skip non-whitespace. */
        s += strspn(s, white);  /* Skip whitespace. */
    }

    /* Allocate memory for NULL-terminated list of words. */
    words = malloc((nwords + 1) * sizeof(words[0]));
        printf("%p\n", words);

    if (words != NULL)
    {
        /* Rescan input, allocate and copy words. */
        s = input;
        for (i = 0; i < nwords; i++)
        {
            s += strspn(s, white);  /* Skip whitespace. */
                    printf("%s\n", s);
            wordlen = strcspn(s, white);    /* Determine word length. */
                            printf("%ld\n", wordlen);

            /* Allocate memory for null-terminated word. */
            words[i] = malloc((wordlen + 1) * sizeof(*s));
            if (words[i] == NULL)
            {
                /* Error will be dealt with later. */
                break;
            }
            /* Copy word (source is not null-terminated). */
            memcpy(words[i], s, wordlen * sizeof(*s));
            words[i][wordlen] = 0;  /* Append null terminator to word. */
            s += wordlen;   /* Skip past the copied word. */
        }
        /* NULL-terminate the list of words. */
        words[i] = NULL;
        if (i < nwords)
        {
            /* Could not allocate enough memory.  Free what we got. */
            ft_free_strlist(words);
            words = NULL;   /* Will return NULL later. */
        }
    }
    if (words == NULL)
    {
        /* There was a memory allocation error. */
        errno = ENOMEM;
    }
    /* Return the NULL-terminated list of words, or NULL on error. */
    return words;
}

/* Print NULL-terminated list of strings. */
void ft_print_strlist_const(const char *const *strings)
{
    if (strings)
    {
        while (*strings)
        {
            puts(*strings);
            strings++;
        }
    }
}

void ft_print_strlist(char *const *strings)
{
    ft_print_strlist_const((const char *const *)strings);
}

int main(void)
{
    static const char str[] = "  hi im   a       new bie  learning malloc\nusage";
    char **words;

    words = ft_split_whitespaces(str);
    if (words == NULL)
    {
        perror("Split whitespace");
        return EXIT_FAILURE;
    }
    ft_print_strlist(words);
    ft_free_strlist(words);
    return EXIT_SUCCESS;
}