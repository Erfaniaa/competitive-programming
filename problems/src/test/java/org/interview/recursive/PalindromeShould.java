package org.interview.recursive;

import org.assertj.core.api.Assertions;
import org.interview.recursive.palindrome.Palindrome;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;

class PalindromeShould {

    @ParameterizedTest
    @CsvSource(
            {"ali , false",
                    "amin ,false",
                    "ddd , true",
                    "aia ,true",
                    "atda ,false",
                    "a ,true"})
    void chick_is_or_not(String input, boolean expected) {
        var palindrome = new Palindrome(input);
        Assertions.assertThat(palindrome.check()).isEqualTo(expected);
    }
}