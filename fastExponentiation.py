#Fast Exponentiation
#If we find out any number's power by naive method, it takes more time.
#And for very large values, it can blow up the memory.
#In this method, the time taken is O(logn) and it is memory efficient.

def power(a,n):
    if(n==0):
        return 1
    if(n==1):
        return a
    else:
        R=power(a,n//2)
        if(n&1):
            return a*R*R
        else:
            return R*R

print(power(2,43))  #2 to the power 43 = 8796093022208 in logn :)