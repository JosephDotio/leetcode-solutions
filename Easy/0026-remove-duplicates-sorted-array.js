// 26 - Remove Duplicates from Sorted Array

let removeDuplicates = function (nums) {
  if (nums.length < 1) return 1;

  let i = 0;

  for (let j = 0; j < nums.length; j++) {
    if (nums[j] !== nums[i]) {
      i++;
      nums[i] = nums[j];
    }
  }
  return i + 1;
};

console.log(removeDuplicates([1,1,2,3,3,4,5]));