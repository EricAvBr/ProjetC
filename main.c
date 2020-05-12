#import <stdio.h>
#define CHIFFREMENT_CLEF 4

//On a : 4 fonctions :
//VerifierAlphanumérique -> Renvoie un message d'erreur si il y a un caractère alphanumérique.
//ConvertirAccents -> Convertis les caractères alphanumériques (É, é, à, ù, etc) en caractère "simple".
//Chiffre -> Chiffre le texte avec le code césar.
//Déchiffre -> Déchiffre le texte avec le code césar.


void Chiffrement (char rep[], char chaineChiffree[]){
  char chaine[52] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char chaineMini[26] = "abcdefghijklmnopqrstuvwxyz";
  int a;
  for(i=0, i<strlen(rep))
    if(rep[i]=chaine[a])
      chaineChiffree[i]=chaine[a+CHIFFREMENT_CLEF]%26;
      i++;
    else
       if(rep[i])=chaineMini[a])
         rep[i]=chaineMini[a+CHIFFREMENT_CLEF]%26;
         i++;
       else
       a++;
}
  
  
void Dechiffrement (char rep[], char chaineChiffree[]){
  char chaine[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char chaineMini[26] = "abcdefghijklmnopqrstuvwxyz";
  int a;
  for(i=0, i<strlen(chaineChiffree))
    if(chaineChiffree[i]=chaine[a])
      rep[i]=chaine[a-CHIFFREMENT_CLEF]%26;
      i++;
    else
      if(chaineChiffree[i]=chaineMini[a])
        rep[i]=chaineMini[a-CHIFFREMENT_CLEF]%26;
        i++;
      else
      a++;
}

void ConvertirAccents(){}


void VerifierAlphanumerique(){}


void main(){}
