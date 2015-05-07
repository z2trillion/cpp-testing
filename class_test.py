def multiply(x, y):
	return x * y

class incrementer():
	def __init__(self):
		print 'i exist!'
		self.counter = 0
	def __iter__(self):
		return self
	def next(self):
		self.counter += 1
		print 'i = %i' %self.counter
		return self.counter

if __name__ == "__main__":
	for i in incrementer():
		print i
		if i > 20:
			break
