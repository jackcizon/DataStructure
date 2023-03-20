#include"D:\code_test_file\DSA\DataStructure\LinkList\JosephQuestion\SingleCircular.h"

circular(int);

#define Joseph void main(void)

#define BEGIN {

#define END }

#define n 7

        Joseph
BEGIN

    int_circular* joseph_list = int_new();

    //insert n player from 1 to n
    for(int i = 1; i <= n; i ++)
    {
        int_append(joseph_list, i);
    }

    //loop ptr
    int_node* ptr = int_head(joseph_list);
    int_node* temp = NULL;

    //interval deletion
    while(int_size(joseph_list) > 2)
    //if we let size > 1, may cause infinite loop
    {
        ptr = ptr->next;
        temp = ptr;
        printf("temp->data == %d, will be deleted\n", temp->data);//true
        
        ptr = ptr->next;
        int_remove(joseph_list, temp->data);
        
        printf("now size is %ld\n", int_size(joseph_list));
        printf("now in the cycle, remain palyers: ");
        
        int_traverse(joseph_list);
        puts("");
    }
    
    printf("and now, the pointer point to player %d\n", ptr->data);
    int_delete(joseph_list, 0);/*delete the second last player*/
    printf("now the winner is : %d", ptr->data);

END