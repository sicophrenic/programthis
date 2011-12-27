#!/usr/bin/python

from sys import argv, exit
import math

def main():
	string = argv[1].lower()
	key = argv[2].lower()
	
	slen = len(string)
	klen = len(key)
	
	if slen > klen:
		newkey = key*(int(math.ceil(float(slen)/float(klen))))
		if len(newkey) > slen:
			key = newkey[0:slen]
		else:
			key = newkey
	elif slen < klen:
		key = key[0:slen]

	s = ""
	for i in range(0,slen):
		schar = string[i]
		kchar = key[i]
		nchar = " "
		if schar.isalpha():
			sord = ord(schar)-ord('a')
			kord = ord(kchar)-ord('a')
			nord = (sord+kord)%26+ord('a')
			nchar = chr(nord)
		else:
			nchar = schar
		s += nchar
	
	print s
		

if __name__ == '__main__':
	main()
