#include "moneytest.h"
#include "money.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( MoneyTest );


void 
MoneyTest::setUp()
{
}


void 
MoneyTest::tearDown()
{
}


void 
MoneyTest::testConstructor()
{
	const std::string currencyFF( "FF" );
	const double longNumber = 12345678.90123;

	// Process
	Money money( longNumber, currencyFF );
	//
	//     // Check
	CPPUNIT_ASSERT_EQUAL( longNumber, money.getAmount() );
	CPPUNIT_ASSERT_EQUAL( currencyFF, money.getCurrency() );
}

void
MoneyTest::testEqual()
{
	// Set up
	const Money money123FF( 123, "FF" );
	const Money money123USD( 123, "USD" );
	const Money money12FF( 12, "FF" );
	const Money money12USD( 12, "USD" );

	//           // Process & Check
	CPPUNIT_ASSERT( money123FF == money123FF );     // ==
	CPPUNIT_ASSERT( money12FF != money123FF );      // != amount
	CPPUNIT_ASSERT( money123USD != money123FF );    // != currency
	CPPUNIT_ASSERT( money12USD != money123FF );    // != currency and != amount
}

