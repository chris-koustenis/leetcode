class Solution:
    def reverse(self, x: int) -> int:
        # Initialize the reversed number.
        reversed_number = 0
        # Initialize the sign of the number.
        sign = 1
        # Check if the number is negative.
        if x < 0:
            sign = -1
            x = -x
        # Iterate over the number, extracting the last digit.
        while x > 0:
            last_digit = x % 10
            reversed_number = reversed_number * 10 + last_digit
            x = x // 10 # Integer division.
        # Check if the reversed number is within the 32-bit signed integer range.
        if reversed_number > 2**31 - 1 or reversed_number < -2**31:
            return 0
        # Return the reversed number with the sign.
        return sign * reversed_number
        
        
        
        


s = Solution()
print(s.reverse(123)) # 321
print(s.reverse(-123)) # -321
print(s.reverse(120)) # 21
print(s.reverse(0)) # 0