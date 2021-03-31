import random

def is_sorted(stack):
	arr = stack.copy()
	arr.sort()
	l = len(stack)
	for i in range(l):
		if arr[i] != stack[i]:
			return 0
	return 1
		

def swap(stack):
	global MOVES_COUNTS
	save = stack[0]
	stack[0] = stack[1]
	stack[1] = save
	MOVES_COUNTS += 1


def s_swap(stack_a, stack_b):
	global MOVES_COUNTS
	swap(stack_a)
	swap(stack_b)
	MOVES_COUNTS -= 1


def rotate(stack):
	global MOVES_COUNTS
	l = len(stack) - 1
	ferst = stack[0]
	stack.remove(ferst)
	stack.insert(l, ferst)
	MOVES_COUNTS += 1


def s_rotate(stack_a, stack_b):
	rotate(stack_a)
	rotate(stack_b)
	global MOVES_COUNTS
	MOVES_COUNTS -= 1


def s_reverse_rotate(stack_a, stack_b):
	reverse_rotate(stack_a)
	reverse_rotate(stack_b)
	global MOVES_COUNTS
	MOVES_COUNTS -= 1


def reverse_rotate(stack):
	global MOVES_COUNTS
	last = stack[-1]
	stack.remove(last)
	stack.insert(0, last)
	MOVES_COUNTS += 1


def	push_to(source, destination):
	global MOVES_COUNTS
	value = source[0]
	destination.insert(0, value)
	source.remove(value)
	MOVES_COUNTS += 1



def initial_values_global(stack_a):
	global RANGE_NUMBER, REAPET_100
	l = len(stack_a)


def	initial_stack(stack_a, stack_b, reapet):
	range_number = reapet * 100
	print('range is ', range_number)

	range_min = range_number - 100
	rotate_count = 0
	count = 0
	l = len(stack_a)
	while len(stack_a) and  len(stack_b) != 100:
		if stack_a[0] < range_number and stack_a[0] >= range_min:
			push_to(stack_a, stack_b)
		else:
			rotate(stack_a)
			rotate_count += 1
		count += 1
		if len(stack_a) == 0 or count > l or range_min > stack_a[0]:
			break
		#print(stack_b)
	while rotate_count:
		rotate_count -= 1
		reverse_rotate(stack_a)
def	set_the_10_5_number(stack_a, stack_b, reapet):

	range_number = (reapet * 10)
	count = 0
	tst = []
	rotate_count = 0
	#print('range is', range_number)
	while count < 10 and len(stack_b):
		if stack_b[0] < range_number:
			tst.append(stack_b[0])
			push_to(stack_b, stack_a)
			count += 1
		else:
			rotate(stack_b)
	
	count = 0
	range_number -= 5
	rotate_count = 0
	while len(stack_a) and count < 5:
		if stack_a[0] >= range_number and stack_a[0] < range_number + 5:
			push_to(stack_a, stack_b)
			count += 1
		else:
			rotate(stack_a)
			rotate_count += 1

	while rotate_count:
		reverse_rotate(stack_a)
		rotate_count -= 1
	#print('stack_a', stack_a[:5] , range_number)
	#print('stack_b', stack_b[:5], range_number + 5)

def	finish_sorting(stack_a, stack_b):
	
	for i in range(5):
		rotate(stack_a)
	
	for i in range(5):
		push_to(stack_b, stack_a)
		rotate(stack_a)


def chose_operation(a_oper, b_oper, a_count, b_count, depth=1):

	if len(b_oper) > b_count and  a_count + 1 < len(a_oper) and a_oper[a_count + 1] == b_oper[b_count]:
		return 1
	if len(a_oper) > a_count and b_count + 1 < len(b_oper) and a_oper[a_count] == b_oper[b_count + 1]:
		return 2

	if depth == 1:
		chose_a = chose_operation(a_oper, b_oper, a_count + 1, b_count, 2)
		chose_b = chose_operation(a_oper, b_oper, a_count, b_count + 1, 2)
		if chose_a:
			return chose_a
		if chose_b:
			return chose_b
	if len(a_oper) > a_count:
		return 1
	if len(b_oper) > b_count:
		return 2


def exec_operation(stack_a, stack_b, oper, index):
	if index == 3:
		if oper == 1:
			s_swap(stack_a, stack_b)
		if oper == 2:
			s_rotate(stack_a, stack_b)
		if oper == 3:
			s_reverse_rotate(stack_a, stack_b)

	if index == 2:
		if oper == 1:
			swap(stack_b)
		if oper == 2:
			rotate(stack_b)
		if oper == 3:
			reverse_rotate(stack_b)

	if index == 1:
		if oper == 1:
			swap(stack_a)
		if oper == 2:
			rotate(stack_a)
		if oper == 3:
			reverse_rotate(stack_a)


def make_operation(stack_a, stack_b, a_oper, b_oper):
	# 1 is swap
	# 2 is rotate
	# 3 is reverse_rotate
	count_a = 0
	count_b = 0
	l_a = len(a_oper)
	l_b = len(b_oper)
	i = 0
	while count_a < l_a or count_b < l_b:	
		if count_a < l_a and count_b < l_b and a_oper[count_a] == b_oper[count_b]:
			exec_operation(stack_a, stack_b, a_oper[count_a], 3)
			count_a += 1
			count_b += 1
		else:
			chose = chose_operation(a_oper, b_oper, count_a, count_b)
			if chose == 3 or chose == 1:
				exec_operation(stack_a, stack_b, a_oper[count_a], chose)
				count_a += 1
			if chose == 3 or chose == 2:
				exec_operation(stack_a, stack_b, b_oper[count_b], chose)
				count_b += 1
		i += 1


def	sort_5_number(stack):
	for i in range(5):
		a_operation = sort_number_by_index(stack_a.copy(), i)
		b_peration = sort_number_by_index(stack_b.copy(), i)
		make_operation(stack_a, stack_b, a_operation, b_peration)



def	sort_last_number_by_index(stack, i, l):
	global MOVES_COUNTS
	if len(stack) == 0:
		return 
	mx = max(stack[:l - i])
	rotate_count = 0
	if stack[l - 1 - i] != mx:
		while stack[0] != mx:
			rotate(stack)
			rotate_count += 1
		while rotate_count != l - 1 - i:
			swap(stack)
			rotate(stack)

			rotate_count += 1
		while rotate_count:
			reverse_rotate(stack)
			rotate_count -= 1


def	sort_number_by_index(stack, i):
	global MOVES_COUNTS
	save = MOVES_COUNTS
	operation = []
	if len(stack) == 0:
		return operation
	mx = max(stack[:5 - i])
	rotate_count = 0
	if stack[4 - i] != mx:
		while stack[0] != mx:
			rotate(stack)
			operation.append(2)
			rotate_count += 1
		while rotate_count != 4 - i:
			swap(stack)
			operation.append(1)
			rotate(stack)
			operation.append(2)

			rotate_count += 1
		while rotate_count:
			reverse_rotate(stack)
			operation.append(3)
			rotate_count -= 1
			MOVES_COUNTS = save
	return operation


def test(stack_a, stack_b):
	global REAPET_100, RANGE_NUMBER
	reapet = 1
	r = 10
	if REAPET_100 != 0:
		for j in range(1, REAPET_100 + 1):
			initial_stack(stack_a, stack_b, j)
			for i in range(1, r + 1):
				set_the_10_5_number(stack_a, stack_b, reapet)
				sort_5_number(stack_a)
				finish_sorting(stack_a, stack_b)
				reapet += 1
		if RANGE_NUMBER % 100 :
			print(stack_a)
			initial_stack(stack_a, stack_b, j + 1)
			r = RANGE_NUMBER % 100
			r = r // 10 + 1
			for i in range(1, r):
				set_the_10_5_number(stack_a, stack_b, reapet)
				sort_5_number(stack_a)
				#print(stack_a[:5])
				#print(stack_b[:5])
				finish_sorting(stack_a, stack_b)
				reapet += 1

	else:
		r = RANGE_NUMBER // 10 + 1
		#if RANGE_NUMBER % 10:
		#	r += 1
		initial_stack(stack_a, stack_b, 1)
		for i in range(1, r):
			set_the_10_5_number(stack_a, stack_b, reapet)
			sort_5_number(stack_a)
			finish_sorting(stack_a, stack_b)
			reapet += 1
	if len(stack_b):
		for i in range(len(stack_b)):
			sort_last_number_by_index(stack_b, i, len(stack_b))
		for i in range(len(stack_b)):
			push_to(stack_b, stack_a)
			rotate(stack_a)

MOVES_COUNTS = 0
RANGE_NUMBER = 5
REAPET_100 = RANGE_NUMBER//100

stack_a = random.sample(range(RANGE_NUMBER), RANGE_NUMBER)
save = MOVES_COUNTS
stack_b = []
test(stack_a, stack_b)
print(stack_a)
print('-------------------------------')
print(stack_b)
print(MOVES_COUNTS)
