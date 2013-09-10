#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(s_suite_test)

BOOST_AUTO_TEST_CASE(t_case1)
{
	BOOST_CHECK_EQUAL(1,2);
}

BOOST_AUTO_TEST_SUITE_END()	