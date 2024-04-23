#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

int check_paranthesis(Stack *opening_brackets, char *str)
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

	char paranthesis_str[opening_brackets->capacity];

	printf("Enter paranthesis: ");
	scanf("%21s", paranthesis_str);

	int balanced = check_paranthesis(opening_brackets, paranthesis_str);

	if (!balanced)
	{
		printf("%s, is not balanced\n", paranthesis_str);
	}
	else 
	{
		printf("%s, is balanced\n", paranthesis_str);
	}

	free(opening_brackets);

	return 0;
}
