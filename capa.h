/*
   centra();
   cursor();
   letra();
   letra_num();
   numero();
*/



#include <dos.h>
#include <conio.h>
#include <ctype.h>


void centra (char cadena[81],int y)
{
 int largo;
 int x;

 largo=strlen (cadena);
 x = (80 - largo) / 2;
 gotoxy (x,y);
 cprintf ("%s",cadena);
}



void cursor(int super, int infer)
{
 /* Invisible --> super= 0x31, infer= 0x31
    Mayor     --> super= 1, infer=31
    Normal    --> super= 14,infer=31  */

 union REGS rin,rout;
 rin.h.ah=0x01;
 rin.h.cl=super;
 rin.h.ch=infer;
 int86(0x10,&rin,&rout);
}


char letra (char cadena[40], int maxi)
 {
  int conta;
  char tecla;

  conta = 0;
  textcolor(WHITE); textbackground(BLACK);
  do {
	  tecla = getch();
	  if (tecla == 0) tecla = getch(); else
	  if (tecla == 8 && conta > 0) {
					conta--; cadena[conta] = 0;
					textcolor (RED);
					cprintf("%c²%c",8,8);
					textcolor (WHITE);
				   } else
	  if ((isalpha(tecla) != 0 || tecla == '¤' || tecla=='¥' || tecla == '.' || tecla == ',') && conta < maxi)
				   {
					cadena[conta] = tecla; conta++;
					cprintf("%c",tecla);
				   } else
	  if (tecla == ' ' && conta >= 1 && conta < maxi)
				   {
					cadena[conta] = tecla; conta++;
					cprintf("%c",tecla);
				   }
	 if (conta==maxi) printf("\a");
	 if (isdigit (tecla) != 0) printf ("\a");
	 } while ((tecla != '\r' || conta < 1));
	 cadena[conta] = '\0';
  }

char letra_num (char cadena[40], int maxi)
 {
  int conta;
  char tecla;

  conta = 0;
  textcolor(WHITE); textbackground(BLACK);
  do {
	  tecla = getch();
	  if (tecla == 0) tecla = getch(); else
	  if (tecla == 8 && conta > 0) {
					conta--; cadena[conta] = 0;
					textcolor (RED);
					cprintf("%c²%c",8,8);
					textcolor (WHITE);
				   } else
	  if ((isalpha(tecla) != 0 || tecla == '¤' || tecla=='¥' || tecla == '.' || tecla == ',') && conta < maxi)
				   {
					cadena[conta] = tecla; conta++;
					cprintf("%c",tecla);
				   } else
	  if (tecla == ' ' && conta >= 1 && conta < maxi)
				   {
					cadena[conta] = tecla; conta++;
					cprintf("%c",tecla);
				   }
	 if (conta==maxi) printf("\a");
         if ( (isdigit(tecla) != 0)  && (conta < maxi) && (tecla!='§') && (tecla!='¦') )
				   {
					cadena[conta] = tecla; conta++;
					cprintf("%c",tecla);
				   }
	 } while ((tecla != '\r' || conta < 1));
	 cadena[conta] = '\0';
  }
int numero (int maxi)
 {
  int nume,conta;
  char tecla, cadena [10];

  conta = 0;
  textcolor(WHITE); textbackground(BLACK);
  do {
	  tecla = getch();
	  if (tecla == 0) tecla = getch(); else
	  if (tecla == 8 && conta > 0) {
					conta--; cadena [conta] = 0;
					textcolor (RED);
					cprintf("%c²%c",8,8);
					textcolor (WHITE);
				   } else
	  if ( (isdigit(tecla) != 0)  && (conta < maxi) && (tecla!='§') && (tecla!='¦') )
				   {
					cadena[conta] = tecla; conta++;
					cprintf("%c",tecla);
				   }
	 if (isalpha (tecla) != 0) printf ("\a");
  } while ((tecla != '\r' || conta < 1));
  cadena[conta] = '\0';
  nume = atoi (cadena);
  return (nume);
}



