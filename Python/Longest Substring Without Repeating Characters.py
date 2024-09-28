# This is a global variable to keep track of substrings
substrings = []

def findSubstring(mainString):
    # This is the current substring that we are looking at
    currentSubstring = ""

    # add character to substring unless it is already there
    # if it is there we break
    for character in mainString:
        # check if character is in string already. ignore whitespace
        if character in currentSubstring.replace(" ", ""):
            print(f"already got {character}")
            # break
            substrings.append(currentSubstring)
            # Clear current substring to look for next one
            currentSubstring = ""

        currentSubstring += character

    # add final substring to substrings array after loop is finished
    substrings.append(currentSubstring)
    print(currentSubstring)

if __name__ == "__main__":
    findSubstring("Enter a string here to find the longest substring with no repeating characters")
    print(substrings)