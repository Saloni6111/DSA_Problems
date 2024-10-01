class TrieNode:
    def __init__(self):
        self.children = {}  # Dictionary to store child nodes
        self.isWord = False  # Flag to indicate if this node marks the end of a valid word
        
    def addWord(self, word):
        cur = self 
        for c in word:
            if c not in cur.children:  # If character not in children, create a new TrieNode
                cur.children[c] = TrieNode()
            cur = cur.children[c]  # Move to the child node
        cur.isWord = True  # Mark the end of the word

def findWords(board, words):
    root = TrieNode()  
    for w in words: 
        root.addWord(w)
            
    ROWS, COLS = len(board), len(board[0]) 
    res, visit = set(), set() 
        
    def dfs(r, c, node, word):
        # Check for out-of-bounds or if the current character is not in the Trie or already visited
        if (r < 0 or c < 0 or 
            r == ROWS or c == COLS or
            board[r][c] not in node.children or (r, c) in visit):
                return  
            
        visit.add((r, c))  # Mark the cell as visited
        node = node.children[board[r][c]]  # Move to the child node corresponding to the current character
        word += board[r][c]  # Append current character to the forming word
        
        if node.isWord:  
            res.add(word)  
            
        dfs(r + 1, c, node, word)  # Move down
        dfs(r - 1, c, node, word)  # Move up
        dfs(r, c + 1, node, word)  # Move right
        dfs(r, c - 1, node, word)  # Move left
        
        visit.remove((r, c))  # Unmark the cell -> backtrack
        
    for r in range(ROWS):  
        for c in range(COLS):
            dfs(r, c, root, "")  
    return list(res)  

if __name__ == "__main__":
    
    # Testcase: 01
    board = [['o', 'a', 'a', 'n'],['e', 't', 'a', 'e'],['i', 'h', 'k', 'r'],['i', 'f', 'l', 'v']]
    words = ["oath", "pea", "eat", "rain"]
    found_words = findWords(board, words)
    print(found_words)  # Expected output: ['eat', 'oath']
    
    # Testcase: 02
    board = [["a","b"],["c","d"]]
    words = ["abcb"]
    found_words = findWords(board, words)
    print(found_words) # Expected output: []
    
    # Testcase: 03
    board = [["a","b","c","d"],["s","a","a","t"],["a","c","k","e"],["a","c","d","n"]]
    words = ["bat","cat","back","backend","stack"]
    found_words = findWords(board, words)
    print(found_words) # Expected output: ["cat","back","backend"]

    # Testcase: 04
    board = [["x","o"],["x","o"]]
    words = ["xoxo"]
    found_words = findWords(board, words)
    print(found_words) # Expected output: []
