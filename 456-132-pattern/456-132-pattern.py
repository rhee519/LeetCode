class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        MIN = -int(10**9)
        st = []
        nums_k = MIN
        
        # i < j < k
        # nums_i < nums_k < nums_j
        for nums_i in nums[::-1]:
            # nums_k < nums_j == st[-1]
            # print(f"st: {st}, nums_i: {nums_i}, nums_k: {nums_k}")
            if st and nums_i < nums_k:
                return True
            while st and st[-1] < nums_i:
                nums_k = st.pop()
            st.append(nums_i)
                
        
        return False
                