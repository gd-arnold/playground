function findMin(nums: number[]): number {
    let start = 0;
    let end = nums.length - 1;

    while (start <= end) {
        let mid = Math.floor((start + end) / 2);

        if (nums[mid] > nums[nums.length - 1]) start = mid + 1;
        else end = mid - 1;
    }

    return nums[start];
};

console.log(findMin([4,5,6,7,0,1,2]));

