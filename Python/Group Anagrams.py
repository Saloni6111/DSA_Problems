from collections import defaultdict

def group_anagrams(words):
    # Create a defaultdict to group anagrams
    anagrams = defaultdict(list)
    
    # Iterate over each word in the input list
    for word in words:
        # Sort the word and use the sorted tuple as the key
        sorted_word = tuple(sorted(word))
        # Append the word to the list corresponding to the sorted tuple
        anagrams[sorted_word].append(word)
    
    # Return the grouped anagrams as a list of lists
    return list(anagrams.values())

# Input from the user
input_str = input("Enter words separated by space: ")
words = input_str.split()  # Split the input into individual words

# Get the grouped anagrams
result = group_anagrams(words)

# Print the result
print("Grouped anagrams:", result)
