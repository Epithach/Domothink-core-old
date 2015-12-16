#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

int	testf() {
  int	a(0);

  return (0);
}

BOOST_AUTO_TEST_SUITE(HelloTest1)

BOOST_AUTO_TEST_CASE(test1) {
	BOOST_CHECK(testf() == 1);
}

BOOST_AUTO_TEST_SUITE_END()

