// parameter (array, 0, tc-1,target)
int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}
// untuk mnenggunakan binary data harus si sorting dulu





// Special Case
int binarySearch(int arr[], int l, int r, int target) {
    int result = -1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == target) {
            result = mid;
            l = mid + 1; // Find the largest index, so move to the right **opsional
        } else if (arr[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return result;
}