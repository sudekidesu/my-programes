n,m= map(int, input().split())
#n=10**100000
ans=int(1)
nt=int(2)
while n>0:
    if n%2==1:
        ans*=nt
    nt*=nt
    n=int(n/2)
ans%=int(1000000007)
print(ans)
