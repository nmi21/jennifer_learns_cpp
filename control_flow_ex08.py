digits = input("Please enter a number: ")

# print(digits)
# print(type(digits))
# print(len(digits))
# print(digits[1])

# rev_num = ""

# if len(digits) <= 0:
#     print("Please enter a new number")
# else:
#     for i in range(len(digits)):
#         rev_num += digits[len(digits) - i - 1]

# print(rev_num)

rev_num = digits[::-1]
print(f"you reversed number is: {rev_num}")