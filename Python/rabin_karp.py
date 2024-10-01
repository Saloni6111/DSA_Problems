d = 256  # Number of characters in the input alphabet
q = 101  # A prime number

# Rabin-Karp algorithm for string matching
def rabin_karp(pattern, text):
    m = len(pattern)
    n = len(text)
    p = 0  # hash value for pattern
    t = 0  # hash value for text
    h = 1

    # The value of h would be "pow(d, m-1) % q"
    for i in range(m - 1):
        h = (h * d) % q

    # Calculate the hash value of pattern and first window of text
    for i in range(m):
        p = (d * p + ord(pattern[i])) % q
        t = (d * t + ord(text[i])) % q

    # Slide the pattern over text one by one
    for i in range(n - m + 1):
        if p == t:
            if all(text[i + j] == pattern[j] for j in range(m)):
                print(f"Pattern found at index {i}")

        # Calculate hash value for next window of text
        if i < n - m:
            t = (d * (t - ord(text[i]) * h) + ord(text[i + m])) % q
            if t < 0:
                t = t + q

# Test case
text = "ABCCDDAEFG"
pattern = "CDD"
rabin_karp(pattern, text)

"""
Test case:
Text: ABCCDDAEFG
Pattern: CDD
Expected output:
Pattern found at index 3
"""
