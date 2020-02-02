
#include<header.h>
#include <dict.h>

void test_newDict(void){
    CU_ASSERT(newDict(200) == NULL);
}

int main (void)// Main function
{

CU_pSuite pSuite1 = NULL;

// Initialize CUnit test registry
if (CUE_SUCCESS != CU_initialize_registry())
return CU_get_error();

// Add suite1 to registry
pSuite1 = CU_add_suite("my_Suite1", NULL, NULL);
if (NULL == pSuite1) {
CU_cleanup_registry();
return CU_get_error();
}

// add test1 to suite1
if ((NULL == CU_add_test(pSuite1, "\n\n……… Testing newDict function……..\n\n", test_newDict)))
{
CU_cleanup_registry();
return CU_get_error();
}

CU_basic_run_tests();// OUTPUT to the screen
CU_cleanup_registry();//Cleaning the Registry
return CU_get_error();

}