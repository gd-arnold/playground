function isValid(s: string): boolean {
    const map: { [key: string]: string } = {")":"(","}":"{","]":"["};

    const stack: string[] = [];

    for (const b of s) {
        if (!(b in map)) stack.push(b);
        else if (stack[stack.length - 1] !== map[b]) return false;
        else stack.pop();
    }

    return stack.length === 0;
};
