class Vigenere {
	public static void main(String[] args) {
		char[] string = args[0].toLowerCase().toCharArray();
		char[] key = args[1].toLowerCase().toCharArray();
		
		// System.out.println(string);
		// System.out.println(key);
		
		double dslen = string.length;
		double dklen = key.length;
		int islen = string.length;
		int iklen = key.length;
		
		// System.out.println(islen);
		// System.out.println(iklen);
		
		if (islen > iklen) {
			// #TODO# Use type-casting here instead?
			double repeat = Math.ceil(dslen/dklen);
			key = duplicate(args[1].toLowerCase(), repeat).toCharArray();
		} else if (iklen < islen) {
			key = args[1].toLowerCase().substring(0, islen).toCharArray();
		}
		
		// System.out.println(key);
		String output = "";
		int i;
		char nchar;
		for(i=0; i<islen; i++) {
			nchar = string[i];
			if (Character.isLetter(nchar)) {
				char schar = (char) (string[i]-'a');
				char kchar = (char) (key[i]-'a');
				nchar = (char) (((schar+kchar)%26)+'a');
			}
			output += nchar;
		}
		System.out.println(output);
	}
	
	private static String duplicate(String key, double repeat) {
		// System.out.println(repeat);
		String rtn= "";
		rtn += key;
		while (repeat > 1) {
			rtn += key;
			repeat--;
		}
		return rtn;
	}
}