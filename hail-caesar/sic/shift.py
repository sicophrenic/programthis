#!/usr/bin/python
def main():
	string = raw_input('Enter a string: ')
	shift = int(raw_input('How much do you want to shift?: '))
	
	rtn = ''
	for char in string:
		if char.isalpha():
			# rtn += char
			if char.isupper():
				rtn += chr((((ord(char)-ord('A'))+shift)%26)+ord('A'))
			else:
				rtn += chr((((ord(char)-ord('a'))+shift)%26)+ord('a'))
		else:
			rtn += char
	print rtn
	
if __name__ == '__main__':
	main()