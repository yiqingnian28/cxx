#define BOOST_TEST_INCLUDED
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(s_suite_test_extern)

BOOST_AUTO_TEST_CASE(t_case2)
{
	BOOST_CHECK_EQUAL(10,110);
}

BOOST_AUTO_TEST_SUITE_END()	