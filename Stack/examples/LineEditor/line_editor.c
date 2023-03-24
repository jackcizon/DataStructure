#include"line_editor.h"
#include"stack.h"
#include<ctype.h>


stack(char);


void LineEdit(void)
{
    char_stack* undo = char_new();
    char_stack* redo = char_new();

    char c;
    while ((c = getchar()) != EOF) 
    {
        //additional feature see details in ascii table.
        switch(c)
        {
            case '\n'://newline
            {
                putchar(c);
                continue;
            }
             
            case '\b'://baskspace
            {
                /*we delete ch from buffer*/
                /*pop form undo_stack, and push in redo*/
                char last_char;
                char_pop(undo, &last_char);
                if(!char_empty(undo))
                {
                    char_push(redo, last_char);
                    printf("\b \b");
                }
                break;
            }
            case 21://undo
            {
                char last_char;
                char_pop(undo, &last_char);
                if(!char_empty(undo))
                {
                    char_push(redo, last_char);
                }
                printf("\b \b");
                break;
            }
            case 18://redo
            {
                char last_char;
                char_pop(redo, &last_char);
                putchar(last_char);
                break;
            }
            case 4://terminate
            {
                return 0;
            }
            default:
            {
                if (isprint(c)) 
                {
                    char_push(undo, c);
                    while(!char_empty(redo))
                    {
                        char* temp = malloc(sizeof *temp);
                        char_pop(redo, temp);
                        free(temp);
                    }
                    putchar(c);
                }
                break;
            }
        }
    }

}


