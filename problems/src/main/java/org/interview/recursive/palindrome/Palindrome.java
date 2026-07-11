package org.interview.recursive.palindrome;

public record Palindrome(String input) {
    private static final int STARTING_INDEX = 0;
    private static final int OFFSET = 1;

    public boolean check() {
        if (input.isEmpty())
            return true;
        return isValid(STARTING_INDEX, endingIndex());

    }

    public boolean isValid(int startingIndex, int endIndex) {
        if (startingIndex >= endIndex)
            return true;
        if (input.charAt(startingIndex) != input.charAt(endIndex))
            return false;

        return isValid(startingIndex + OFFSET, endIndex - OFFSET);

    }

    private int endingIndex() {
        return input.length() - 1;
    }
}
