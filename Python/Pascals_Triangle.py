from typing import *

#Function to calculate nCr (binomial coefficient)
def nCr(n, r):
    res = 1
    # calculating nCr:
    for i in range(r):
        res = res * (n - i) #Multiply by (n-i) (numerator part)
        res = res // (i + 1) #Divide by (i+1) (denominator part)
    return int(res)

def pascalTriangle(n : int) -> List[List[int]]:
    ans = []
    #Store the entire pascal's triangle:
    for row in range(1, n+1):
        tempLst = [] 
        for col in range(1, row+1): 
            tempLst.append(nCr(row - 1, col - 1))
        ans.append(tempLst)
    return ans

if __name__ == '__main__':
    n = 5
    ans = pascalTriangle(n)
    for it in ans:
        for ele in it:
            print(ele, end=" ")
        print()