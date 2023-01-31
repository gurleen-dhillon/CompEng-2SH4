#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CuTest.h"
#include "Questions.h"
    


   
    
	//=========test 1==================================
	void TestQ1_1(CuTest *tc) {
		
		int input1=9,input2=12,expected=21,actual;
		actual=addFunction(input1,input2);
		CuAssertIntEquals(tc, expected, actual);
	}

	//=========test 2==================================
    
	void TestQ1_2(CuTest *tc) {
		
		int input1=0,input2=6,expected=6,actual;
		actual=addFunction(input1,input2);
		CuAssertIntEquals(tc, expected, actual);
	}
   
	//=========test 3==================================

	 void TestQ1_3(CuTest  *tc) {
	     int input1=-420,input2=69,expected=-351,actual;
	     actual = addFunction(input1,input2);
	     CuAssertIntEquals(tc, expected, actual);
    }

	//===========================================================
	    CuSuite* Lab0GetSuite() {
	        CuSuite* suite = CuSuiteNew();
	        SUITE_ADD_TEST(suite, TestQ1_1);
	        SUITE_ADD_TEST(suite, TestQ1_2);
	        SUITE_ADD_TEST(suite, TestQ1_3);

		return suite;
	}
    
