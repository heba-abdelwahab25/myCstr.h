#include "my_str.h"
#include <stdio.h>
#include <string.h>


static char null_check(void * p)
{
    char reslt = 1;
    if(p == NULL)
    {
        reslt = 0;
    }

    return reslt;
}


int my_strlen(char str[]){
    int counter = 0;
    if(null_check(str))
    {

        while(*(str+counter)!=NULL)
        {
            counter++;
        }
    }

    return counter;
}


static int my_min(int first,int second){
    int reslt = 0;
    if(first > second){
        reslt = second;
    }
    else{
        reslt = first;
    }

    return reslt;
}


void *my_memchr(const void *str, int c, size_t n){

    char *ret = NULL;

    if(null_check(str))
    {
        char *srch = str;
        for(int i=0; i<n; i++)
        {
            if(*(srch+i)==(char)c)
            {
                ret=(srch+i);
                break;
            }
            else
            {

                continue;
            }
        }
    }
    else{

    }


    return ret;

}


int my_memcmp(const void *str1, const void *str2, size_t n){

    int ret=0;

    if(null_check(str1) && null_check(str2))
    {
        for(int i=0; i<n; i++)
        {
            if(*((char*)str1+i)==*((char*)str2+i))
            {
                continue;
            }
            else
            {
                if(*((char*)str1+i)>*((char*)str2+i))
                    ret=1;
                else
                    ret=-1;
                break;

            }

        }
    }

    else{}


    return ret;
}


void *my_memcpy(void *dest, const void * src, size_t n){

    if(null_check(dest) && null_check(src))
    {
            for(int i=0; i<n; i++)
        {
            *((char*)dest+i)=*((char*)src+i);
        }
    }
    else{}

    return dest;
}


void *my_memmove(void *dest, const void * src, size_t n){

    if(null_check(dest) && null_check(src))
    {
        char tmp[n];
        for(int i=0; i<n; i++)
        {
            tmp[i]=*((char*)src+i);
        }
        for(int i=0; i<n; i++)
        {
            *((char*)dest+i)=tmp[i];
        }
    }
    return dest;
}


void *my_memset(void *str, int c, size_t n){

    if(null_check(str))
    {
        for(int i=0; i<n; i++)
        {
            *((char*)str+i)=c;
        }

    }
    else{}
    return str;
}


char *my_strcat(char *dest, const char *src){

    if(null_check(dest) && null_check(src))
    {
        int counter= my_strlen(dest);

        while(*src!=NULL)
        {
            *(dest+counter)=*src++;
            counter++;
        }
    }
    else{}
    return dest;
}


char *my_strchr(const char *str, int c){

    char *ret = NULL;

    if(null_check(str))
    {
        for(int i=0; i< my_strlen(str); i++)
        {
            if(*(str+i) == (char)c)
            {
                ret = (str + i);
                break;
            }
            else
            {

                continue;
            }
        }
    }
    else{

    }


    return ret;

}


int my_strcmp(const char *str1, const char *str2){

        int ret=0;

    if(null_check(str1) && null_check(str2))
    {
        int len1 = my_strlen(str1);
        int len2 = my_strlen(str2);

        for(int i=0; i < my_min(len1,len2); i++)
        {
            if(*(str1+i)==*(str2+i))
            {
                continue;
            }
            else
            {
                if(*(str1+i)>*(str2+i))
                    ret=1;
                else
                    ret=-1;
                break;

            }

        }
    }

    else{}


    return ret;
}


int my_strncmp(const char *str1, const char *str2, size_t n){

    int ret=0;

    if(null_check(str1) && null_check(str2))
    {
        for(int i=0; i<n; i++)
        {
            if(*(str1+i) == *(str2+i))
            {
                continue;
            }
            else
            {
                if(*(str1+i) > *(str2+i))
                    ret=1;
                else
                    ret=-1;
                break;

            }

        }
    }

    else{}


    return ret;
}


int my_strcoll(const char *str1, const char *str2){

    return my_strcmp(str1,str2);
}


char *my_strcpy(char *dest, const char *src){

    if(null_check(dest) && null_check(src))
    {
            for(int i=0; i < my_strlen(src); i++)
        {
            *(dest+i)=*(src+i);
        }
    }
    else{}

    return dest;

}


char *my_strncpy(char *dest, const char *src, size_t n){

    if(null_check(dest) && null_check(src))
    {
    return my_memcpy(dest,src,n);
    }
    else{}
}



size_t my_strcspn(const char *str1, const char *str2) {

    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    int ret = -1;

    if (null_check(str1) && null_check(str2)) {
        for (int i = 0; i < len1; i++) {
            char tmp = *(str1 + i);
            for (int n = 0; n < len2; n++) {
                if (*(str2 + n) == tmp) {
                    ret = i;
                    break;
                }
            }
            if (ret != -1) {
                break;
            }
        }
    }
    else {}
    return ret;
}


char *my_strpbrk(const char *str1, const char *str2) {
    char* ret = NULL;
    if (null_check(str1) && null_check(str2)) {
        int s = my_strcspn(str1, str2);
        if (s != -1)
            ret = (char *)(str1 + s);
    }
    else {}
    return ret;
}

char *my_sttrerror(int errnum){
        return strerror(errnum);

}


char *my_strrchr(const char *str, int c) {
    int len = my_strlen(str) - 1;
    char* ret = NULL;
    while (len >= 0) {
        if (*(str + len) == c) {
            ret = (char *)(str + len);
            break;
        }
        len--;
    }
    return ret;
}

size_t my_strspn(const char *str1, const char *str2){

    int len1=my_strlen(str1);
    int len2=my_strlen(str2);
    int ret=0;

    if(null_check(str1)&&null_check(str2))
    {
        for(int i=0; i<len1; i++)
        {
            char tmp = *(str1+i);
            int flag = 0;
            for(int n=0; n<len2; n++)
            {
                if(*(str2+n) == tmp)
                {
                    ret++;
                    flag++;
                    break;
                }

            }
            if(flag == 0)
            {
                break;
            }
        }
    }
    else{}


    return ret;
}


char *my_strstr(const char *haystack, const char *needle){

    char *ret=NULL;
    if(null_check(haystack)&&null_check(needle))
    {
        int len = my_strlen(needle);
        int flag=0;
        haystack=my_strchr(haystack, *needle);
        if(haystack != NULL)
        {
            for(int i=1; i<len; i++)
            {
                haystack++;
                if(*haystack != *(needle+i))
                {
                    break;
                }
                else if(i == len - 1)
                {
                    ret=haystack - i;
                }
            }
            if(ret == NULL && haystack != NULL)
            {
                ret=my_strstr(haystack,needle);
            }
        }
    }
    else{}

    return ret;
}


char *my_strtok(char *str, const char *delim){

    int len = my_strlen(str);
    static char *ret = NULL;
    static int s = 0;
    int count = 0;
    if(s == -1)
        ret = NULL;
    else if(null_check(str) && null_check(delim))
    {
        while(*str == *delim)
        {
            my_memmove(str,str+1,len-1);
            *(str+len-count) = NULL;
            count++;
        }
        len -= count;
        s = my_strcspn(str, delim);
        if(s != -1)
        {
            *(str+s)=NULL;
            ret=str;
        }
        else
        {
            ret=NULL;
        }

    }
    else if(str==NULL&&delim!=NULL)
    {

        ret+=s+1;
        int len2=my_strlen(ret);
        while(*ret==*delim)
        {
            memmove(ret,ret+1,len2-1);
            *(ret+len2-count)=NULL;
            count++;
        }
        s=strcspn(ret,delim);
        if(s!=-1)
        {
            *(ret+s)=NULL;
        }
        else
        {
        }

    }

    return ret;
}


size_t my_strxfrm(char *dest, const char *src, size_t n){

    my_memmove(dest,src,n);

    return my_strlen(dest);

}
