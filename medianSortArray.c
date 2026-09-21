#include <stdio.h>
#include <stdio.h>


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0, j = 0;
    int last;
    int next;
    while(i + j < (nums1Size + nums2Size)/2 && (i < nums1Size) && (j < nums2Size)){
        if(nums1[i] < nums2[j]){
            last = nums1[i];
            i++;
        }else{
            last = nums2[j];
            j++;
        }
    }
    if(i == nums1Size){
        for(; (i + j) < (nums1Size + nums2Size)/2 ; j++){
            last = nums2[j];
        }
        next = nums2[j];
    }else if(j == nums2Size){
        for(; (i + j) < (nums1Size + nums2Size)/2 ; i++){
            last = nums1[i];
        }
        next = nums1[i];
    }else{
        if(nums1[i] < nums2[j]){
            next = nums1[i];
        }else{
            next = nums2[j];
        }
    }
    

    if((nums1Size + nums2Size) % 2){
        return next;
    }else{
        return (double)(last + next)/ 2.0;
    }
}

int main() {
    int nums1[] = {1, 3};
    int nums2[] = {2};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int size2 = sizeof(nums2) / sizeof(nums2[0]);

    double median = findMedianSortedArrays(nums1, size1, nums2, size2);
    printf("Median: %.5f\n", median);

    return 0;
}