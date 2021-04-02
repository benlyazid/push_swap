import math

def solution(area):
	tab = []
	save = area
	minus_area = 1
	for i in range(4):
		a = math.sqrt(area)
		if a == int(a) and a > 1:
			a -= 1
		tab.append(int(a))
		area -= (int(a)**2)

	tab.sort(reverse=True)
	print(tab)
	scorre = 0
	for i in tab:
		scorre += i** 2
	print(scorre, save)
	return tab

'''for i in range(9,10):
	area = i
	result = solution(area)
	area_check = 0
	for a in result:
		area_check += a**2
	print(result, area, area_check)'''
solution(10)