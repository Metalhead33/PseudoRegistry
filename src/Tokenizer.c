/* 
 * File:   Tokenizer.c
 * Author: metalhead33
 *
 * Created on 2016. december 11., 18:45
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tokenizer.h"
/*
 * 
 */
TokenizedCString* TokenizeString(char* str,char delimiter)
{
	TokenizedCString* tmp_struct;
        int i;
        char* tmp_token;
        char delim[2];
        
        delim[0] = delimiter;
        delim[1] = '\0';
        
        tmp_struct = (TokenizedCString*)malloc(sizeof(TokenizedCString));
        if(!tmp_struct) return 0;
        
        tmp_struct->tokens = 1;
        //printf("Start of cycle!");
        for(i=0;str[i] != '\0' && str[i] != EOF;++i)
        {
                if(str[i] == delimiter) tmp_struct->tokens += 1;
        }
        //printf("Allocating %d bytes of space!", tmp_struct.tokens);
        tmp_struct->tokenized_string = (char**)malloc(sizeof(char*) * tmp_struct->tokens);
        
        tmp_token = strtok(str,delim);
        i = 0;
        while(tmp_token != NULL)
        {
                tmp_struct->tokenized_string[i] = (char*)malloc(sizeof(char) * (strlen(tmp_token) + 1));
                if(tmp_struct->tokenized_string[i])
                {
                strcpy(tmp_struct->tokenized_string[i],tmp_token);
                /*printf("%s\n",tmp_token);*/
                tmp_token = strtok(NULL,delim);
                ++i;
                }
                else return 0;
        }
        return tmp_struct;
}

TokenizedCString* CopyTokenizeString(const char* str,char delimiter)
{
	TokenizedCString* tmp_struct;
        int i;
        char* tmp_str;
        char* tmp_token;
        char delim[2];
        
        delim[0] = delimiter;
        delim[1] = '\0';
        
        tmp_struct = (TokenizedCString*)malloc(sizeof(TokenizedCString));
        if(!tmp_struct) return 0;
        
        tmp_struct->tokens = 1;
        //printf("Start of cycle!");
        for(i=0;str[i] != '\0' && str[i] != EOF;++i)
        {
                if(str[i] == delimiter) tmp_struct->tokens += 1;
        }
        //printf("Allocating %d bytes of space!", tmp_struct.tokens);
        tmp_struct->tokenized_string = (char**)malloc(sizeof(char*) * tmp_struct->tokens);
        tmp_str = (char*)malloc(sizeof(char) * (strlen(str) + 1));
        if(tmp_str) strcpy(tmp_str,str);
        else return 0;
        
        tmp_token = strtok(tmp_str,delim);
        i = 0;
        while(tmp_token != NULL)
        {
                tmp_struct->tokenized_string[i] = (char*)malloc(sizeof(char) * (strlen(tmp_token) + 1));
                if(tmp_struct->tokenized_string[i])
                {
                strcpy(tmp_struct->tokenized_string[i],tmp_token);
                /*printf("%s\n",tmp_token);*/
                tmp_token = strtok(NULL,delim);
                ++i;
                }
                else return 0;
        }
        free(tmp_str);
        return tmp_struct;
}

void DestroyTokens(TokenizedCString* p_tok)
{
	int i;
        //printf("Deconstructing the tokens!\n");
	for(i = 0;i < p_tok->tokens;++i)
	{
                //printf("Freeing %p",p_tok->tokenized_string[i]);
		free(p_tok->tokenized_string[i]);
	}
	free(p_tok->tokenized_string);
	p_tok->tokens = 0;
	free(p_tok);
}
