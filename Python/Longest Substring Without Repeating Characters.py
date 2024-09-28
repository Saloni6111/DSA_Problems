# This is a global variable to keep track of substrings
substrings = []

def findSubstring(mainString):
    # This is the current substring that we are looking at
    currentSubstring = ""

    # add character to substring unless it is already there
    # if it is there we add the current substring to global variable and start looking for next one
    for character in mainString:
        # check if character is in string already. ignore whitespace
        if character in currentSubstring.replace(" ", ""):
            substrings.append(currentSubstring)
            # Clear current substring to look for next one
            currentSubstring = ""

        currentSubstring += character

    # add final substring to substrings array after loop is finished
    substrings.append(currentSubstring)

#find the longest substring
def longestSubstring():
    longestItem = ""
    for item in substrings:
        if len(item) > len(longestItem):
            longestItem = item

    return len(longestItem)        

if __name__ == "__main__":
    findSubstring("abcabc1abc12")
    longest = longestSubstring()

    print(substrings)
    print(longest)