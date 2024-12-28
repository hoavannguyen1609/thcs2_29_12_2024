#include <stdio.h>

#define MAX_SIZE 100

void printEnterString(char s[]) {
	printf("Chuoi da nhap: ");
	
	int j = 0;
	
	while(s[j] != '\0') {
		putchar(s[j]);
		
		j++;
	}
	
	printf("\n");
	
}

int getDoDai(char s[]) {
	int x = 0;
	
	while(s[x]!='\0') {
		x++;
	}
	
	return x;
}

void demSoTu(char s[]) {
	int i = 0, dem = 0;
	
	while(i < getDoDai(s)) {
		if(s[i]!= ' ' && s[i+1] == ' ' || s[i+1]=='\0') {
			dem++;
		}
		
		i++;
	}
	
	printf("\nSo tu da nhap la: %d", dem);
}

char *convertToLowercase(char s[]) {
	int i = 0;
	
	while(i < getDoDai(s)) {
		if(s[i] >= 'A' && s[i] <= 'Z') {
			s[i] += 32;	
		}	
			
		i++;
	}
	
	return s;
}

char *convertToUppercase(char s[]) {
	int i = 0;
	
	while(i < getDoDai(s)) {
		if(s[i] >= 'a' && s[i] <= 'z') {
			s[i] -= 32;	
		}	
			
		i++;
	}
	
	return s;
}

void demKiTu(char s[]) {
	int dem[256] = {0};
	int t = getDoDai(s);
	int i = 0, j = 0;
	
	printf("\nSo lan xuat hien cua moi ky tu:");
	
	while(i<t) {
		dem[s[i]]++;
		
		i++;
	}
	
	while(j < 256) {
		if(dem[j]) {
			printf("\nKy tu '%c' xuat hien %d", j, dem[j]);
		}
		
		j++;
	}
}

char *catTrai(char s[], int n) {
	if(n >= getDoDai(s)) {
		return s;
	} else {
		char *newS;
	
		newS = new char[n+1];
	
		int i = 0;
	
		while(i < n) {
			newS[i] = s[i];
		
			i++;
		}
		
		newS[n] = '\0';
		return newS;
	}
}

char *catPhai(char s[], int n) {
	if(n >= getDoDai(s)) {
		return s;
	} else {
		char *newS;
	
		newS = new char[n+1];
	
		int i = 0;
	
		while(i < n) {
			newS[i] = s[getDoDai(s) - n + i];
		
			i++;
		}
		
		newS[n] = '\0';
		return newS;
	}
}

int main() {
	char s[MAX_SIZE];
	
	int i = 0;
	
	printf("Nhap mot chuoi ky tu (toi da 99 ky tu): ");
	
	char c;
	
	while ((c = getchar()) != '\n' && i < 99) {
        s[i++] = c;
    }
	
	s[i] = '\0';
	
	printEnterString(s);
	
	demSoTu(s);
	
	demKiTu(s);
	
	printf("\nNhap so tu muon cat trai va cat phai: ");
	
	int nCut;
	
	scanf("%d", &nCut);
	
	printf("\nChuoi '%s' cat trai voi %d ky tu: %s",s, nCut, catTrai(s, nCut));
	
	printf("\nChuoi '%s' cat phai voi %d ky tu: %s",s, nCut, catPhai(s, nCut));
	
	printf("\nChuyen doi sang ky tu thuong: %s",convertToLowercase(s));
	
	printf("\nChuyen doi sang ky tu hoa: %s",convertToUppercase(s));
	
	return 0;
}
