function isPalindrome(s: string): boolean {
    const f = s.toLowerCase().replace(/[^a-z0-9]/gi, '');
    return f === [...f].reverse().join("");
};

console.log(isPalindrome("A man, a plan, a canal: Panama"));
