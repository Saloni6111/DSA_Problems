# This is a global variable to keep track of substrings
substrings = []

def findSubstring(mainString):
    # This is the current substring that we are looking at
    currentSubstring = ""

    for character in mainString:
        # check if character is in string already. ignore whitespace
        if character in currentSubstring.replace(" ", ""):
            substrings.append(currentSubstring)
            # Clear current substring to look for next one
            currentSubstring = ""

        currentSubstring += character

    # add final substring to substrings array after loop is finished
    substrings.append(currentSubstring)

# find the longest substring
def longestSubstring():
    # the current longest item
    longestItem = ""

    # loop through all substrings to find the longest. ignore whitespaces
    for item in substrings:
        if len(item.replace(" ", "")) > len(longestItem.replace(" ", "")):
            longestItem = item

    return len(longestItem)        

if __name__ == "__main__":
    # Test case 1: abcabc1abc12
    # Expected output: 5
    findSubstring("abcabc1abc12")
    longest = longestSubstring()
    print(longest)

    #clean up
    substrings.clear()

    # Test case 2: this is a test string
    # Expected output: 6
    findSubstring("this is a test string")
    longest = longestSubstring()
    print(longest)