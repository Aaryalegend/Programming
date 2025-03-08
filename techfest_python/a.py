# # immutable
# a=9
# print(type(a))

# b=9.0
# print(type(b))

# c=False
# print(type(c))

# i=3+4j
# print(type(i))

# q = (1,2,3,4.0, 'a', [1,2,3])
# print(type(q))
# print(q[5][1])

# h=None
# print(type(h))

# # mutable
# p = [1,2,3,4]
# print(type(p))


# r = {'a':1, 'b':2}  
# print(type(r))

# s = {1,2,3,4}
# print(type(s))

# print(list(range(0,10)))

## Funtions in python

# def my_function(fname):
#   print(fname + " Babar")

# my_function("Aryan")
# my_function("Asawari")
# my_function("Atul") 

# def greet(name, surname):
#     print(f'Hi {name} {surname}')
#     print('Good Morning')

import hashlib

# Input string
input_string = "Hello, World!"

# Encode the string and compute SHA-256 hash
hash_object = hashlib.sha256(input_string.encode())
hex_dig = hash_object.hexdigest()

print("SHA-256 Hash:", hex_dig)
