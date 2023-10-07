#include "hashtable.h"
#include <stdio.h>
#include <string.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void Alert(void);
int suite_setup(void);
int suite_teardown(void);

CU_pSuite PrepareTest(void);
int TestFunc(CU_pSuite suite, const char* TestName, CU_TestFunc func);
void RunTest(void);

void TestNewNode(void);
void TestHashTable(void);

int main(int argc, char const *argv[])
{
    CU_pSuite suite = PrepareTest();
    
    TestFunc(suite, "test NewNode:", TestNewNode);
    TestFunc(suite, "test NewTable:", TestHashTable);

    RunTest();
    Alert();
    return 0;
}

void Alert(void)
{
    puts("press enter to exit...");
    getchar();
    puts("press 'continue' or 'step over' to end.");
}

int suite_setup(void)
{
    return 0;
}

int suite_teardown(void)
{
    return 0;
}

CU_pSuite PrepareTest(void)
{
    CU_pSuite suite = NULL;

    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return NULL;
    }

    // Add a suite to the registry
    suite = CU_add_suite("HashTable Test Suite", suite_setup, suite_teardown);
    if (suite == NULL)
    {
        CU_cleanup_registry();
        return NULL;
    }
    return suite;
}

int TestFunc(CU_pSuite suite, const char* TestName, CU_TestFunc func)
{
    if (CU_add_test(suite, "test function ==>>", func) == NULL)
    {
        CU_cleanup_registry();
        return false;
    }
    return true;
}


void RunTest(void)
{
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    CU_cleanup_registry();
}

void TestNewNode(void)
{
    printf(" %s ==>>", __func__);
    node* Node = NewNode("$_POST", "passwd");
    CU_ASSERT_PTR_NOT_NULL(Node);
    CU_ASSERT_STRING_EQUAL(Node->key, "$_POST");
    CU_ASSERT_STRING_EQUAL(Node->value, "passwd");

    FreeNode(Node);
}

void TestHashTable(void)
{
    printf(" %s ==>>", __func__);
    size_t size = 10;
    hashtable* ht = NewTable(size);
    CU_ASSERT_PTR_NOT_NULL(ht);
    for (size_t i = 0; i < size; i++)
    {
        CU_ASSERT_EQUAL(ht->table[i], NIL);
    }

    Insert(ht, "$_POST", "passwd");
    Insert(ht, "$_GET", "username");
    Insert(ht, "$_SERVER", "remote_ip");
    Insert(ht, "key1", "value1");
    Insert(ht, "key2", "value2");

    CU_ASSERT_STRING_EQUAL(Retrive(ht, "key1"), "value1");
    CU_ASSERT_STRING_EQUAL(Retrive(ht, "key2"), "value2");

    Delete(ht, "key1");
    CU_ASSERT_PTR_NULL(Retrive(ht, "key1"));
    CU_ASSERT_STRING_EQUAL(Retrive(ht, "key2"), "value2");
    Delete(ht, "key2");
    CU_ASSERT_PTR_NULL(Retrive(ht, "key2"));

    Traverse(ht);
    CU_ASSERT_PTR_NOT_NULL(ht);
    DestroyTable(&ht);
    CU_ASSERT_PTR_NULL(ht);
}

