const d = 256; // Number of characters in the input alphabet
const q = 101; // A prime number

// Rabin-Karp algorithm for string matching
function rabinKarp(pattern, text) {
    const m = pattern.length;
    const n = text.length;
    let p = 0; // hash value for pattern
    let t = 0; // hash value for text
    let h = 1;

    // The value of h would be "pow(d, m-1) % q"
    for (let i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    // Calculate the hash value of pattern and first window of text
    for (let i = 0; i < m; i++) {
        p = (d * p + pattern.charCodeAt(i)) % q;
        t = (d * t + text.charCodeAt(i)) % q;
    }

    // Slide the pattern over text one by one
    for (let i = 0; i <= n - m; i++) {
        if (p === t) {
            let match = true;
            for (let j = 0; j < m; j++) {
                if (text[i + j] !== pattern[j]) {
                    match = false;
                    break;
                }
            }

            if (match) {
                console.log("Pattern found at index " + i);
            }
        }

        // Calculate hash value for next window of text
        if (i < n - m) {
            t = (d * (t - text.charCodeAt(i) * h) + text.charCodeAt(i + m)) % q;
            if (t < 0) {
                t = t + q;
            }
        }
    }
}

// Test case
const text = "ABCCDDAEFG";
const pattern = "CDD";
rabinKarp(pattern, text);

/*
Test case:
Text: ABCCDDAEFG
Pattern: CDD
Expected output:
Pattern found at index 3
*/
