	/* 
	 * File:   Tokenizer.h
	 * Author: metalhead33
	 *
	 * Created on 2016. december 11., 18:43
	 */

#ifndef TOKENIZER_H
#define TOKENIZER_H

#ifdef __cplusplus
	extern "C" {
#endif
typedef struct struct_CSTR {
	char ** tokenized_string;
	unsigned int tokens;
} TokenizedCString;

TokenizedCString* TokenizeString(char* str,char delimiter);
TokenizedCString* CopyTokenizeString(const char* str,char delimiter);
void DestroyTokens(TokenizedCString* p_tok);

#ifdef __cplusplus
}
#endif

#endif /* TOKENIZER_H */

