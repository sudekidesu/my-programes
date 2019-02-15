n=int(input())
#n=10**100000
ans=int(1)
nt=int(3)
while n>0:
    if n%2==1:
        ans*=nt
    nt*=nt
    n=int(n/2)
    ans%=int(998244353)
print(ans)
