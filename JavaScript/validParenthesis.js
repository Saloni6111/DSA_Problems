var isValid = function(s) {
    const elts = {
        "[": "]",
        "{": "}",
        "(": ")"
    };
    const stack = [];

    for (let i = 0; i < s.length; i++) {
        const char = s[i];

        if (elts[char]) {
            stack.push(char);
        } else if (stack.length === 0 || elts[stack.pop()] !== char) {
            return false;
        }
    }
    return stack.length === 0;
};