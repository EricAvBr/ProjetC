#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <string.h>


// ---------------------- A FAIRE -----------------------
void chiffrement(wchar_t* texte, wchar_t* texteChiffre, int* clef){  //A FAIRE
	char alphabet[26]= "abcdefghijklmnopqrstuvwxyz";
	int a;
	int i;
	texteChiffre=texte;
	for(i=0; i<wcslen(texte); i++)
	{
		for(a=0; a<strlen(alphabet); a++)
		{
			if(texte[a]=alphabet[i])
			{
				texteChiffre[a]=alphabet[i+2];
			}
		}
	}	
}
// ------------------- A FAIRE ------------------------------
void dechiffrement(){}                                                   


// ------------------- FONCTIONNEL ---------------------------
void convertirAccents(wchar_t* texte){
	int i;
	for(i=0; i<wcslen(texte); i++)
	{
		switch(texte[i]){
			case L'É': case L'é': case L'È': case L'è': case L'Ê': case L'ê': case L'Ë': case L'ë':
			texte[i]=L'e';
			break;
			case L'Á': case L'á': case L'À': case L'à': case L'Â': case L'â': case L'Ä': case L'ä':
			texte[i]=L'a';
			break;
			case L'Ç': case L'ç':
			texte[i]=L'c';
			break;
			case L'Î': case L'î': case L'Ï': case L'ï':
			texte[i]=L'i';
			break;
			case L'Ô': case L'ô':
			texte[i]=L'o';
			break;
			case L'Ù': case L'ù': case L'Û': case L'û': case L'Ü': case L'ü':
			texte[i]=L'u';
			break;
		default:
		texte[i]=texte[i];
	}
	}
}

// ------------------------ FONCTIONNEL ------------------------
int verifierAlphanumerique(wchar_t* texte){
	wchar_t caracAlpha[42]=L"><#({[]})*-+.@|&~_`^?;,:!%$§µ£¤*€=°²\'\\/";
	int i;
	int a;
	for(i=0; i<wcslen(texte); i++)
	{
		for(a=0; a<wcslen(caracAlpha); a++)
		{
			if(texte[i]==caracAlpha[a])
			{
				return 1;
			}
		}
	}
	return 0;
}

// ------------------ FONCTIONNEL ----------------------
void viderBuffer(){
	int c = 0;
	while (c != '\n' && c != EOF)
	{
	c = getchar();
	}
}


void main(){
	setlocale(LC_ALL,"fr_FR.UTF-8");
	wchar_t texte[200];
	wchar_t texteChiffre[200];
	int alphanum;
	int* clef;
	wprintf(L"---- Quel est le texte que vous voulez chiffer ? ----\n");
	fgetws(texte, 200, stdin);
	wprintf(L"---- Quelle clef de chiffrement souhaitez-vous ? Elle doit être comprise entre 0 et 25. ----\n");
	wscanf(L"%d", clef);
	alphanum = verifierAlphanumerique(texte);
	while(alphanum==1)
	{
		wprintf(L"---- Votre message ne doit pas contenir de caractères spéciaux. ----\n");
		wprintf(L"---- Quel est le message que vous voulez chiffrer ? ----\n");
		fgetws(texte, 200, stdin);
		alphanum = verifierAlphanumerique(texte);
		viderBuffer();
	}
	convertirAccents(texte);
	wprintf(L"---- Le texte converti sans accent : ----\n");
	wprintf(L"%ls\n", texte);
	wprintf(L"---- Le texte converti avec la méthode de chiffrement césar : ----\n");
	chiffrement(texte, texteChiffre, clef);
	wprintf(L"%ls\n", texteChiffre);
	viderBuffer();
}


