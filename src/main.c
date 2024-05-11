#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

int check_parantheses(Stack *opening_brackets, char *str)
{
	char brackets[3][2] = {"{}", "()", "[]"};
	int brackets_size = sizeof(brackets[0]) / sizeof(brackets[0][0]);

	for (int i = 0; i < strlen(str); i++) {
		for (int j = 0; j < brackets_size; j++) {

			if (str[i] == brackets[j][0]) push(opening_brackets, str[i]);

			else if (str[i] == brackets[j][1]) {
				if (peek(opening_brackets) == brackets[j][0]) pop(opening_brackets);
			}
		}
	}

	return is_empty(opening_brackets);
}

int main()
{
	Stack *opening_brackets = create_stack(20);

	if (!opening_brackets)
	{
		return -1;
	}

	char parantheses_str[opening_brackets->capacity];

	printf("Enter parantheses: ");
	scanf("%21s", parantheses_str);

	int balanced = check_parantheses(opening_brackets, parantheses_str);

	if (!balanced)
	{
		printf("%s, is not balanced\n", parantheses_str);
	}
	else 
	{
		printf("%s, is balanced\n", parantheses_str);
	}

	free(opening_brackets);

	return 0;
}
