#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "user.h"

void test_adjust_recommendation() {
    user_t user1 = {"Alice", 0,0,0,0,0,0,0,0,"",0,0,0,0,3};
    user_t user2 = {"Bob", 0,0,0,0,0,0,0,0,"",0,0,0,0,1};
    user_t user3 = {"Charlie", 0,0,0,0,0,0,0,0,"",0,0,0,0,2};

    // Test case 1: Feedback = -1 (Too hard), ID should decrease
    printf("test1");
    assert(adjust_recommendation(&user1, -1) == 2);
    // Test case 2: Feedback = -1 (Too hard), ID cannot go below 1
    printf("test2");
    assert(adjust_recommendation(&user2, -1) == 1);

    // Test case 3: Feedback = 1 (Too easy), ID should increase
    printf("test3");
    assert(adjust_recommendation(&user1, 1) == 3);
    // Test case 4: Feedback = 1 (Too easy), ID can increase
    printf("test4");
    assert(adjust_recommendation(&user3, 1) == 3);

    // Test case 5: Feedback = 0 (Not effective), Even ID, switch to odd ID
    printf("test5");
    assert(adjust_recommendation(&user3, 0) == 4);
    // Test case 6: Feedback = 0 (Not effective), Odd ID, switch to even ID
    printf("test6");
    user_t user4 = {"David", 0,0,0,0,0,0,0,0,"",0,0,0,0,3};
    assert(adjust_recommendation(&user4, 0) == 4);

    // Test case 7: Test ID cannot go below 1 (feedback=0 and already at minimum)
    printf("test7");
    user_t user5 = {"Eve", 0,0,0,0,0,0,0,0,"",0,0,0,0,1};
    assert(adjust_recommendation(&user5, 0) == 2);

    printf("All tests passed!\n");
}

int main() {
    test_adjust_recommendation();
    return 0;
}