# dsa-cracker-sheet

450 problems links:
https://450dsa.com/
https://docs.google.com/spreadsheets/d/1FMdN_OCfOI0iAeDlqswCiC2DZzD4nPsb/edit?usp=sharing&ouid=105019633939354806682&rtpof=true&sd=true
https://www.geeksforgeeks.org/dsa-sheet-by-love-babbar/

## Important articles/links

### Q3:

https://www.geeksforgeeks.org/kth-smallest-largest-element-in-unsorted-array/
https://www.geeksforgeeks.org/kth-smallest-largest-element-in-unsorted-array-expected-linear-time/
https://ocw.mit.edu/courses/6-046j-introduction-to-algorithms-sma-5503-fall-2005/resources/lecture-6-order-statistics-median/

### Q8:

https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

#### Print the Largest Sum Contiguous Subarray

To print the subarray with the maximum sum the idea is to maintain start index of maximum_sum_ending_here at current index so that whenever maximum_sum_so_far is updated with maximum_sum_ending_here then start index and end index of subarray can be updated with start and current index.

Follow the below steps to implement the idea:

Initialize the variables s, start, and end with 0 and max_so_far = INT_MIN and max_ending_here = 0
Run a for loop from 0 to N-1 and for each index i:
Add the arr[i] to max_ending_here.
If max_so_far is less than max_ending_here then update max_so_far to max_ending_here and update start to s and end to i .
If max_ending_here < 0 then update max_ending_here = 0 and s with i+1.
Print values from index start to end.
