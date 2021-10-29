a=list(map(int,input().split()))
x=int(input())
l=0
r=len(a)-1
m=(l+r)//2
while(l<=r):
	m=(l+r)//2
	if(a[m]==x):
		print('Element found at location',m+1)
		break
	else:
		if(x>a[m]):
			l=m+1
		if(x<a[m]):
			r=m-1
else:
	print('Element not found')
