// Time: O(N * (K * log(K))
// Memory: O(N * K)
function groupAnagrams(strs: string[]): string[][] {
    const anagramsMap = new Map();

    // Time: O(N * (K * log(K)))
    for (const str of strs) {
        const standardForm = str
            .split("") // O(K)
            .sort((a, b) => a.localeCompare(b)) // O(K * log(K))
            .join("");// O(K)

        if (anagramsMap.has(standardForm)) {
            anagramsMap.get(standardForm).push(str);
        } else {
            anagramsMap.set(standardForm, [str]);
        }
    }

    return [...anagramsMap.values()];
};

console.log(groupAnagrams(["eat","tea","tan","ate","nat","bat"]));
console.log(groupAnagrams([""]));
console.log(groupAnagrams(["a"]));
