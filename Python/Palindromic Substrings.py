def count_palindromic_substrings(s):
    # Initialize variables to store count and list of palindromic substrings
    count = 0
    palindromic_substrings = []

    # Function to expand around the center and check for palindromes
    def expand_around_center(left, right):
        nonlocal count
        # Expand as long as the characters at left and right are equal
        while left >= 0 and right < len(s) and s[left] == s[right]:
            # Add the palindrome substring to the list
            palindromic_substrings.append(s[left:right+1])
            count += 1
            left -= 1
            right += 1

    # Iterate over each character and check for both odd-length and even-length palindromes
    for i in range(len(s)):
        # Odd-length palindromes (center at i)
        expand_around_center(i, i)
        # Even-length palindromes (center between i and i+1)
        expand_around_center(i, i+1)

    return count, palindromic_substrings

# Input from the user
s = input("Enter a string: ")

# Get the number of palindromic substrings and the substrings themselves
count, palindromic_substrings = count_palindromic_substrings(s)

# Display the result
print(f"Total number of palindromic substrings: {count}")
print("The palindromic substrings are:")
for substring in palindromic_substrings:
    print(substring)
