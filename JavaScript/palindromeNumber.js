
/**
 * A palindrome number is a number that remains the same when its digits are reversed.
 * In other words, it reads the same both forward and backward.
 * Properties of Palindrome Numbers:
 * They are symmetric, so reversing their digits gives the same number.
 * Any negative number cannot be a palindrome, since the negative sign - is not symmetric.
 */
function isPalindrome(number) {
    // Convert the number to a string
    const strNumber = number.toString()
    // Set pointers at the beginning and end of the string
    let start = 0
    let end = strNumber.length - 1
    // Loop through the string from both ends
    while (start < end) {
        // If characters at start and end don't match, it's not a palindrome
        if (strNumber[start] !== strNumber[end]) {
            return false
        }
        // Move the pointers towards the center
        start++
        end--
    }
    // If all characters match, it is a palindrome
    return true
}

// Example usage:
console.log('12321', isPalindrome(12321))
console.log('54345', isPalindrome(54345))
console.log('1000003545', isPalindrome(1000003545))
console.log('121', isPalindrome(121))