function binarySearch(arr, key) {
  let start = 0;
  let end = arr.length - 1;

  while (start <= end) {
    let mid = Math.floor(start + (end - start) / 2);

    if (arr[mid] === key) {
      return mid;
    } else if (arr[mid] > key) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  return -1;
}

const arr = [2, 3, 4, 10, 40];
const key = 10;

const result = binarySearch(arr, key);
if (result !== -1) {
  console.log("Element found at index:", result);
} else {
  console.log("Element not found");
}
