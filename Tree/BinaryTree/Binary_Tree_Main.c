#include"binary_tree.h"


int main(int argc, const string argv[])
{
    string s[] = {"php", "java", "c", "ruby"};

    BinaryTree* BT1 = NewTree(s, sizeof(s) / sizeof(s[0]));

    Insert(&(BT1->root), "hello");
    Insert(&(BT1->root), "world");
    Insert(&(BT1->root), "5");
    Insert(&(BT1->root), "0");

    DeleteV1(&(BT1->root), "0");
    DeleteV2(&(BT1->root), "5");

    Search(&(BT1->root), "c") ?
        puts("found") : puts("not found");

    printf("LCA: %s\n", LowestCommonAncestor(BT1, "php", "java", "ruby"));

    InOrderTraverse(Root(BT1));


    BinaryTree* BT2 = NewTree(s, sizeof(s) / sizeof(s[0]));

    Insert(&(BT2->root), "hi");
    Insert(&(BT2->root), "gobal");

    PreOrderTraverse(Root(BT2));

    SameTree(Root(BT1), Root(BT2)) ?
        puts("\nsame trees") : puts("\nnot same trees");

    printf("\nBT1. Len: %ld, Depth: %ld \n", Length(Root(BT1)), Depth(Root(BT1)));

    Destroy(BT1);
    Destroy(BT2);
    

    puts("\n\nall executions success!");

    return 0;
}


