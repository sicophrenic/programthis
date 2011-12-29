class Shift {
	public static void main(String[] args) {
		String str = args[0];
		int shift = Integer.parseInt(args[1]);
		
		int i;
		String rtn = "";
		char nchar;
		for(i=0; i<str.length(); i++) {
			nchar = str.toCharArray()[i];
			if (Character.isLetter(nchar)) {
				if (Character.isUpperCase(nchar)) {
					nchar = (char) ((char) ((nchar-'A'+shift)%26)+'A');
				} else {
					nchar = (char) ((char) ((nchar-'a'+shift)%26)+'a');
				}
			}
			rtn += nchar;
		}
		System.out.println(rtn);
	}
}