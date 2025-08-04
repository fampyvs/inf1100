#include <stdio.h>
#include <string.h>

int main() {
    //Programmet skal skrive ut første og siste bokstav i tekststrengen
    char *ptekst; // Endret **ptekst til *ptekst 
    char tekst[] = "Hvor skal det pekes?";
    ptekst = tekst; // Endret *ptekst = &tekst; til ptekst = tekst;
    
    int lengde = strlen(ptekst);
    
    printf("ptekst inneholder tekststrengen %s\n", ptekst); // Sto bare s (hvorfor?). Endret det til ptekst.
    printf("%s inneholder %c\n", tekst, ptekst[0]); // Sto s[0] (hvorfor?). Endret til %s så den kan bruke tekst.
    printf("%s inneholder %c\n", tekst, ptekst[lengde - 1]); // Sto s[lengde] (hvorfor?). Endret til %s å den kan bruke tekst.
    return 0;
}

/* Var en del andre endringer også. Noen linjer jeg slettet helt, de var ubrukelige. F.eks: ptekst[lengde] = tekst; 
og ptekst[0] = tekst;. Disse er unødevendige og tror ikke de egentlig vil gjøre det man ønsker.
Siden du ber om det samme i printf statementene. Andre endringer er at jeg har flyttet litt på linjene, slik
at det er litt mer leselig kode.
*/
