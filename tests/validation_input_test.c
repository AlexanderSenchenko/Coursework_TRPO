#include "ctest.h"
#include "check.h"


CTEST(check_vertex, one_vertex)
{
    // Given
    const char  vertex[5] = "1";

    // When
    const int result = check_vertex(vertex);

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}
//gcc -I thirdparty -I src -Wall -o test tests/*.c 

