/********************************************************************************
This code is automatically generated by the VerticalThings compiler. DO NOT EDIT!
********************************************************************************/
/*Managed memory variables*/
unsigned char __vtmem[80];
int (*test_mod_test_func_A_p)[10]= (int (*)[10]) &__vtmem[0];
#define test_mod_test_func_A (*test_mod_test_func_A_p)
int (*test_mod_test_func_B_p)[10]= (int (*)[10]) &__vtmem[40];
#define test_mod_test_func_B (*test_mod_test_func_B_p)
/*End of managed memory variables*/
/*Module vars for test_mod*/
/*End of module vars for test_mod*/
/*Module vars for arduino*/
/*End of module vars for arduino*/
typedef enum { __test_mod_test_func}  __test_pipe;
 __test_pipe __state = __test_mod_test_func;
void _test_mod_test_func()
{
    int test_mod_test_func_C;
    int __t0;
    int __t1;
    int __t2;
    {
        for(int __i=0; __i<10; __i++)
        {
            A[__i]=0;
            test_mod_test_func_B[__i]=0;
        }
        test_mod_test_func_C=0;
        __t2=0;
        for(int __i=0; __i<10; __i++)
        {
            __t0=(A[__i]+test_mod_test_func_B[__i]);
            __t1=(A[__i]+test_mod_test_func_B[__i]);
            __t2=((__t0*__t1)+__t2);
        }
        test_mod_test_func_C=__t2;
    }
}
void loop()
{
    switch(__state)
    {
        case __test_mod_test_func:
        __state = __test_mod_test_func;
        _test_mod_test_func();
        break;
        default :
        __state = __test_mod_test_func;
    }
}
void setup()
{
}