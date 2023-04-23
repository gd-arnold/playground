// Time: O(n)
// Space: O(1)
function maxArea(height: number[]): number {
    let maxArea = 0;

    let l = 0;
    let r = height.length - 1;

    while (l < r) {
        const start = height[l];
        const end = height[r];

        const area = (r - l) * Math.min(start, end);
        maxArea = Math.max(area, maxArea);

        if (start > end) r--;
        else l++;
    }

    return maxArea;
};

console.log(maxArea([1,8,6,2,5,4,8,3,7]));
