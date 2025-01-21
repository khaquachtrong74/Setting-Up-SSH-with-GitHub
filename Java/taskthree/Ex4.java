package taskthree;

// interact with String
class Ex4 {
	public static void main(String[] args) {
		NameString test = new NameString("nguyen van chien");
		System.out.println(test.firstAndLast());
		System.out.println(test.getName());
		System.out.println(test.capitalize());
	}
}

class NameString {
	private String fullName = "";

	public NameString(String name) {
		this.fullName = name;
	}

	public NameString() {
		this.fullName = "";
	}

	public void setName(String name) {
		this.fullName = name;
	}

	public String getName() {
		return this.fullName;
	}

	// return the first and last name
	public String firstAndLast() {
		fullName = fullName.trim();
		String[] tmp = fullName.split(" ");
		return tmp[0] + " " + tmp[tmp.length - 1];
	}

	// return the middle name
	public String middleName() {
		fullName = fullName.trim();
		String[] tmp = fullName.split(" ");
		String ketqua = "";
		for (int i = 1; i < tmp.length - 1; i++) {
			ketqua += tmp[i] + " ";

		}
		return ketqua;
	}

	// Capitalize the full name
	public String capitalize() {
		fullName = fullName.trim();
		String[] tmp = fullName.split(" ");
		fullName = "";
		
		for (int i = 0; i < tmp.length; i++) {
			if (tmp[i].charAt(0) >= 'a' && tmp[i].charAt(0) <= 'z') {
				String b = "";
				for (int j = 0; j < tmp[i].length(); j++) {
					if (j == 0) {
						b += (char)(tmp[i].charAt(j)-32);
						continue;
					} else {
						b += tmp[i].charAt(j);
					}
				}
				fullName +=b +" ";
			}
		}
		return fullName;
	}
	
}
