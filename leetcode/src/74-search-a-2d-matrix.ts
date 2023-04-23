// Time: O(log(n*m))
// Space: O(1)
function searchMatrix(matrix: number[][], target: number): boolean {
    // Search column: O(log n)
    let bottom = 0;
    let top = matrix.length - 1;
    while (bottom <= top) {
        const mid = Math.floor((top + bottom) / 2);

        if (matrix[mid][0] === target) return true;
        else if (matrix[mid][0] < target) bottom = mid + 1;
        else top = mid - 1;
    }

    // Search row: O(log m)
    const row = matrix[Math.max(top, 0)];
    let start = 0;
    let end = row.length - 1;
    while (start <= end) {
        const mid = Math.floor((start + end) / 2);

        if (row[mid] === target) return true;
        else if (row[mid] < target) start = mid + 1;
        else end = mid - 1;
    }

    return false;
};

console.log(searchMatrix([[1,3,5,7],[10,11,16,20],[23,30,34,60]], 3));
console.log(searchMatrix([[1,3,5,7],[10,11,16,20],[23,30,34,60]], 20));
console.log(searchMatrix([[1,3,5]], 3))
console.log(searchMatrix([[1]], 1));
