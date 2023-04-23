function search(nums: number[], target: number): number {
    let start = 0;
    let end = nums.length - 1;

    while (start <= end) {
        let mid = Math.round((start + end) / 2);
        if (nums[mid] === target) return mid;
        if (nums[mid] > target) end = mid - 1;
        else start = mid + 1;
    }

    return -1;
};

console.log(search([-1,0,3,5,9,12], 9));
