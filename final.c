/* Fecha Inicio -> 26/04-1999 */
/* Lenguaje: C /*
/* Proyecto de fin de curso (98-99)*/
/* Fecha Final -> 01/06/1999 */
/* NOTA: BIEN */


#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <ctype.h>
#include "capa.h"

char tema[12][51]={"INFANTIL.dat","AVENTURA.dat","CFICCION.dat","TERROR.dat","EDUCA.dat",
		  "POESIA.dat","INFORMA.dat","ADULTO.dat","REVISTA.dat","OTROS.dat","BAJAS.dat","PRESTAMO.dat"};
char tema_bien[12][51]={"INFANTIL","AVENTURA","CIENCIA-FICCION","TERROR","EDUCATIVOS",
			 "POESIA","INFORMATICA","ADULTO","REVISTA","OTROS","BAJAS","PRESTAMOS"};
int pos_menu;
int num_tema=0;
char nom_tema[51];
struct tipo_libro
{
 char titulo[51];
 char autor[51];
 char editorial[51];
 char tema[51];    /* El tema pre-definido */
 unsigned int ano; /* A¤o de edicion */
 int ejemplares;   /* numero de ejemplares */
 char estado[51];  /* Prestado, perdido, disponible .... */
 char baja[51];    /* Motivo de la bajas */
};
struct tipo_libro libro;
FILE *f;



void no_file(void)
{
 textcolor (RED+128);
 textbackground (BLACK);
 clrscr();
 centra ("ERROR #1: Fichero no encontrado.\a",12);
 getch();
}
void no_regi(void)
{
 textcolor (RED+128);
 textbackground (BLACK);
 clrscr();
 centra ("ERROR #2: Registro no encontrado.\a",12);
 getch();
}
void restringido(void)
{
 textbackground (BLACK);
 textcolor (RED+128);
 clrscr();
 centra ("ERROR #3: Opci¢n no diponible para este tema.\a",12);
 getch();
}
void ficha_repe(int aux_num_tema)
{
 textbackground (BLACK);
 textcolor (RED+128);
 clrscr();
 centra ("ERROR #4: Ficha repetida en el tema:",12);
 textcolor (YELLOW);
 centra (tema_bien [aux_num_tema],14);
 cprintf ("\a");
 getch();
}
no_ejemplares()
{
 textbackground (BLACK);
 textcolor (RED+128);
 clrscr();
 centra ("ERROR #5: En estos momentos el libro no est  DISPONIBLE:",12);
 cprintf ("\a");
 getch();
}
no_aprobado()
{
 textbackground (BLACK);
 textcolor (RED+128);
 clrscr();
 centra ("ERROR #6: No se puede abandonar el programa sin aprobarlo",12);
 cprintf ("\a");
 getch();
}

acerca_de ()
{
 int pos;
 char opc;


 textbackground (BLACK);
 textcolor ( LIGHTBLUE);
 clrscr();
 centra ("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»",5);
 centra ("º                                                            º",6);
 centra ("ÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹",7);
 centra ("º                                                            º",8);
 centra ("º                                                            º",9);
 centra ("º                                                            º",10);
 centra ("º                                                            º",11);
 centra ("º                                                            º",12);
 centra ("º                                                            º",13);
 centra ("º                                                            º",14);
 centra ("º                                                            º",15);
 centra ("º                                                            º",16);
 centra ("ÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹",17);
 centra ("º                                                            º",18);
 centra ("º                                                            º",19);
 centra ("ÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍËÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹",20);
 centra ("º                             º                              º",21);
 centra ("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÊÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼",22);
 textcolor (WHITE+128);
 centra ("CAPASOFT",6);
 textcolor (WHITE);
 gotoxy (22,9);
 cprintf ("Programador :");
 centra ("Lenguaje de programaci¢n : Turbo C 2.0",12);
 centra ("Agradecimientos : Anaya Multimedia",15);
 centra ("Dedicado : a Sr. Carande",18);
 centra ("y especialmente a mi novia ANNA (por su paciencia).",19);
 gotoxy (23,21);cprintf ("1998");
 gotoxy (54,21);cprintf ("1999");
 textcolor (YELLOW);
 gotoxy (36,9);
 cprintf ("Sergio Caparr¢s Jurado");
 gotoxy (41,19);
 cprintf ("ANNA");
 getch();
}

void ilumina (int pos,int color)
{
 if (color==1) textcolor (WHITE);
 if (color==2) textcolor (YELLOW);
 switch (pos)
 {
  case 1: centra ("ALTAS",10);break;
  case 2: centra ("BAJAS",11);break;
  case 3: centra ("PRESTAMOS",12);break;
  case 4: centra ("LISTADO",13);break;
  case 5: centra ("MODIFICACION",14);break;
  case 6: centra ("CONSULTA",15);break;
  case 7: centra ("TEMARIO",16);break;
  case 8: centra ("PROGRAMADOR",17);break;
  case 9: centra ("SALIR",18);break;
 }
}

void borra_linea_fondo (int i)
{
 textcolor (RED);
 centra ("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²",i);
}


int menu(int pos)
{
 char opc;
 int pos2;

 if (pos==1) pos2=8;
 else pos2=pos-1;
 textbackground (BLACK);
 clrscr();
 textcolor (LIGHTBLUE);
 textbackground (BLUE);
 centra ("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»",5);
 centra ("º                          º",6);
 centra ("ÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹",7);
 centra ("º                          º",8);
 centra ("º                          º",9);
 centra ("º                          º",10);
 centra ("º                          º",11);
 centra ("º                          º",12);
 centra ("º                          º",13);
 centra ("º                          º",14);
 centra ("º                          º",15);
 centra ("º                          º",16);
 centra ("º                          º",17);
 centra ("º                          º",18);
 centra ("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼",19);
 textcolor (LIGHTRED);
 centra (tema_bien[num_tema],6);
 textcolor (WHITE);
 centra ("ALTAS",10);
 centra ("BAJAS",11);
 centra ("PRESTAMOS",12);
 centra ("LISTADO",13);
 centra ("MODIFICACION",14);
 centra ("CONSULTA",15);
 centra ("TEMARIO",16);
 centra ("PROGRAMADOR",17);
 centra ("SALIR",18);
 do
 {
  ilumina (pos2,1);
  ilumina (pos,2);
  pos2=pos;
  opc=getch();
  switch (opc)
  {
   case ('P'): pos++; break;
   case ('H'): pos--; break;
  }
  if (pos>9) pos=1;
  if (pos<1) pos=9;
 }while (opc!=13);
 return (pos);
}

/* Sirve para abrir el fichero corespondiente al TEMA*/


void menu2 (void)
{
 int i;

 textbackground (BLACK);
 clrscr();
 textcolor (BLACK);
 textbackground (WHITE);
 centra ("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»",2);
 centra ("º                          º",3);
 centra ("ÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹",4);
 centra ("º                          º",5);
 centra ("º                          º",6);
 centra ("º                          º",07);
 centra ("º                          º",8);
 centra ("º                          º",9);
 centra ("º                          º",10);
 centra ("º                          º",11);
 centra ("º                          º",12);
 centra ("º                          º",13);
 centra ("º                          º",14);
 centra ("º                          º",15);
 centra ("º                          º",16);
 centra ("º                          º",17);
 centra ("º                          º",18);
 centra ("º                          º",19);
 centra ("º                          º",20);
 centra ("º                          º",21);
 centra ("º                          º",22);
 centra ("º                          º",23);
 centra ("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼",24);
 textcolor (LIGHTRED);
 centra ("TEMARIO",3);
 textcolor (BLUE);
 for (i=0;i<12;i++) centra ( (tema_bien[i]),i+8);
}

cambia_tema()
{
 char opc;
 int pos,pos2;
 int bandera;
 menu2();

 bandera=0;
 pos=num_tema;
 pos2=0;  /* Es innecesario, pero asignandole un valor no me da WARNING */
 textcolor (WHITE);
 centra ( (tema_bien[pos]),pos+8);
 do
 {
  if (pos>11) pos=0;
  if (pos<0) pos=11;
  textcolor (WHITE);
  centra ( (tema_bien[pos]),pos+8);
  textcolor (BLUE);
  if (bandera!=0) centra ( (tema_bien[pos2]),pos2+8);
  bandera=1;
  pos2=pos;
  do
  {
   opc= getch();
  }while ( (opc!='P') && (opc!='H') && (opc!=13) );
  switch (opc)
  {
   case 'P': pos++;break;
   case 'H': pos--;break;
  }/* del SWITCH */

 }while (opc!=13);
 num_tema = pos;
}



void ficha(void)
{
 int i;

 textcolor (RED);
 textbackground (BLACK);
 clrscr();
 for  (i=1;i<26;i++)
 {
  centra ("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²",i);
 }
 textbackground (WHITE);
 textcolor (BLACK);
 centra ("         Sergio Caparr¢s Jurado - Programa Final de Curso (98-99)         ",1);
 textbackground (BLACK);
 textcolor (YELLOW+128);
 gotoxy (1,1);cprintf ("* Nazgul *");
 gotoxy (69,1); cprintf ("* Nazgul *");
 textcolor (WHITE);
 gotoxy (4,4);cprintf ("T¡tulo: ");
 gotoxy (4,6);cprintf ("Autor: ");
 gotoxy (4,8);cprintf ("Editorial: ");
 gotoxy (4,10);cprintf ("Tema: ");
 gotoxy (4,12);cprintf ("A¤o: ");
 gotoxy (4,14);cprintf ("N£mero de ejemplares: ");
 gotoxy (4,16);cprintf ("Estado actual: ");
 textbackground (BLUE);
 gotoxy (1,2);
 cprintf ("                                                                              ");
 gotoxy (1,25);
 cprintf ("                                                                              ");
 centra (tema_bien[num_tema],25);

}

void muestra_ficha (struct tipo_libro libro, int ana)
{
 ficha();
 textbackground (BLACK);
 gotoxy (12,4);cprintf ("%s",libro.titulo);
 gotoxy (11,6);cprintf ("%s",libro.autor);
 gotoxy (15,8);cprintf ("%s",libro.editorial);
 gotoxy (10,10);cprintf ("%s",libro.tema);
 gotoxy (9,12);cprintf ("%d",libro.ano);
 gotoxy (26,14);cprintf ("%d",libro.ejemplares);
 gotoxy (19,16);cprintf ("%s",libro.estado);
 if ( (num_tema==10) && (ana==1) )  /* SI ESTAMOS CON LAS BAJAS MUESTRA EL CAMPO DEL MOTIVO DE LAS BAJAS*/
 {
  gotoxy (4,18);
  cprintf ("Motivo de la baja: %s", libro.baja);
 }
 if ( (num_tema==11) && (ana==1) ) /* SI ESTAMOS EN PRESTAMOS MUESTRA A QUIEN SE HA PRESTADO */
 {
  gotoxy (4,18);
  cprintf ("Prestado a: %s",libro.baja);
 }

}

int busca_ficha (char titulo[51], int aux_num_tema)

/* DEVUELVE:
	pos: la posicion (si lo encuentra);
	-2 : Si el FICHERO no est  creado (no existe)
	-1 : Si el FICHERO si est  creado pero no encuentra la ficha. */


{
 struct tipo_libro aux_libro;
 int i=0;
 FILE *f2;

 f2=fopen(tema[aux_num_tema],"rb");
 if (f2 != NULL)
 do
 {
  fseek (f2, i*sizeof (struct tipo_libro), SEEK_SET);
  fread (&aux_libro, sizeof (struct tipo_libro),1,f2);
  if (strcmpi (aux_libro.titulo,titulo) == 0)
  {
   fclose (f2);
   return (i); /*Si lo encuentra delvuelve la posicion */
  }

  i++;
  if  (feof (f2) != 0)
  {
   fclose (f2);
   return (-1);
  }
 }while (i==i); /* siempre */
 if (f2==NULL) return (-2);
}


void altas(void)
{
 struct tipo_libro aux_libro;
 int aux_tema;
 int repe;



 if (num_tema==10) { restringido();return; }
 if (num_tema==11) { restringido();return; }
 ficha();
 textbackground (BLUE);
 textcolor (WHITE);
 centra ("ALTAS",2);
 textbackground (BLACK);
 textcolor (YELLOW);gotoxy (4,4);cprintf ("T¡tulo: ");
 letra_num (aux_libro.titulo,50);
 for (aux_tema=0; aux_tema<10;aux_tema++) /* NO MIRA EN BAJAS NI EN PRESTAMOS*/
 {
  repe = busca_ficha(aux_libro.titulo,aux_tema);
  if ( (repe!= -1) && (repe!= -2) )/* Si no repetida */
  {
   ficha_repe(aux_tema);
   return;
  }
 }
 textcolor (WHITE);gotoxy (4,4);cprintf ("T¡tulo: ");
 textcolor (YELLOW);gotoxy (4,6);cprintf ("Autor: ");
 letra (aux_libro.autor,50);
 textcolor (WHITE);gotoxy (4,6);cprintf ("Autor: ");
 textcolor (YELLOW);gotoxy(4,8);cprintf ("Editorial: ");
 letra (aux_libro.editorial,50);
 textcolor (WHITE);gotoxy (4,8);cprintf ("Editorial: ");
 textcolor (WHITE);gotoxy (4,10);cprintf ("Tema: ");
 strcpy (aux_libro.tema,tema_bien[num_tema]);
 cprintf ("%s", aux_libro.tema);
 textcolor (YELLOW);gotoxy (4,12);cprintf ("A¤o: ");
 do
 {
  gotoxy (9,12);
  textcolor (RED);
  cprintf ("²²²²");
  gotoxy (9,12);
  aux_libro.ano=numero(4);
 }while ( (aux_libro.ano>2100) || (aux_libro.ano<1000) );
 textcolor (WHITE);gotoxy (4,12);cprintf ("A¤o: ");
 textcolor (YELLOW); gotoxy (4,14);cprintf ("N£mero de ejemplares: ");
 do
 {
  textcolor (RED);
  gotoxy (26,14);
  cprintf ("²²²");
  gotoxy (26,14);
  aux_libro.ejemplares=numero (3);
 }while (aux_libro.ejemplares<1);
 textcolor (WHITE);gotoxy (4,14);cprintf ("N£mero de ejemplares: ");
 gotoxy (4,16);cprintf ("Estado actual: ");
 strcpy (aux_libro.estado,"DISPONIBLE");
 cprintf ("%s", aux_libro.estado);
 f = fopen (tema[num_tema],"ab"); /*Abre o crea un file con el nombre de TEMA*/
 fwrite (&aux_libro, sizeof (struct tipo_libro),1,f);
 fclose (f);
 getch();
}




reorganiza (FILE *pf,const int elimina)
{
 char dato;
 long cont;


 cont=ftell(pf);
 fseek (pf,cont+elimina,SEEK_SET);
 fread (&dato,1,1,pf);
 while (!(feof(pf)))
 {
  fseek (pf,cont,SEEK_SET);
  fputc (dato,pf);
  cont++;
  fseek (pf,cont+elimina,SEEK_SET);
  fread (&dato,1,1,pf);
 };
 if (cont>=0) chsize (fileno(pf),cont);
}



dar_baja (int pos)
{
 FILE *f2;
 char aux_baja[51];
 struct tipo_libro aux_libro;

 textcolor (RED);
 centra ("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²",20);
 centra ("²²²",21);
 textcolor (YELLOW);
 gotoxy (4,18);
 cprintf ("Motivo de la baja: ");
 letra (aux_baja,50);
 f2=fopen (tema[10],"ab");
 fseek (f, pos * sizeof (struct tipo_libro),SEEK_SET);
 fread (&aux_libro, sizeof (struct tipo_libro),1,f);  /* Lee de F */
 strcpy ( aux_libro.estado,"BAJA TEMPORAL");
 strcpy (aux_libro.baja, aux_baja);
 aux_libro.ejemplares=1; /* REsta 1*/
 fwrite (&aux_libro, sizeof (struct tipo_libro), 1, f2); /* Graba en f2*/
 fclose (f2);
}

dar_prestamo (int pos)
{
 FILE *f2;
 char aux_baja[51];
 struct tipo_libro aux_libro;

 textcolor (RED);
 centra ("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²",20);
 centra ("²²²",21);
 textcolor (YELLOW);
 gotoxy (4,18);
 cprintf ("Prestado a: ");
 letra_num (aux_baja,50);
 f2=fopen (tema[11],"ab");
 fseek (f, pos * sizeof (struct tipo_libro),SEEK_SET);
 fread (&aux_libro, sizeof (struct tipo_libro),1,f);  /* Lee de F */
 strcpy ( aux_libro.estado,"PRESTADO");
 strcpy (aux_libro.baja, aux_baja);
 aux_libro.ejemplares=1; /* REsta 1*/
 fwrite (&aux_libro, sizeof (struct tipo_libro), 1, f2); /* Graba en f2*/
 fclose (f2);
}

void bajas(void)
{
 char titulo[51];
 char op;
 int pos;
 struct tipo_libro aux_libro;
 /*int num_reg;*/


 if (num_tema==11) { restringido ();return; }

 f= fopen (tema[num_tema],"r+b");
 fseek (f,0,2); /* Se posiciona al final del FILE */
 /*num_reg = ftell (f)/ sizeof (struct tipo_libro);*/  /* Coge el numero de fichas */
 if (f!=NULL)
 {
  ficha();
  textcolor (WHITE);
  textbackground (BLUE);
  centra ("BAJAS",2);
  textbackground (BLACK);
  textcolor (YELLOW);
  gotoxy (4,4);
  cprintf ("T¡tulo: ");
  letra_num (titulo,50);
  pos=busca_ficha (titulo,num_tema);
  if (pos== -1) no_regi();
  else /* SI SE ENCUENTRA LA FICHA */
  {
   fseek (f,pos * sizeof (struct tipo_libro), SEEK_SET);
   fread (&aux_libro, sizeof (struct tipo_libro), 1, f);
   muestra_ficha (aux_libro,1);
   textcolor (WHITE);
   textbackground (BLUE);
   centra ("BAJAS",2);
   textbackground (BLACK);
   textcolor (YELLOW);
   if (num_tema==10) centra ("¨Quiere borrar definitivamente este libro?",20);
   if (num_tema!=10) centra ("¨Quiere dar de baja este libro?",20);
   centra ("S/N",21);
   do
   {
	op= toupper ( getch() );
   }while ( (op!='S') && (op!='N') );
   if ( (op=='S') && (num_tema!=10) )
   {
	if (aux_libro.ejemplares == 1)
	{
	 dar_baja(pos);
	 fseek (f, pos*sizeof (struct tipo_libro), SEEK_SET);
	 reorganiza (f,sizeof (struct tipo_libro) );
	}


	if (aux_libro.ejemplares > 1)
	{
	 aux_libro.ejemplares--;  /*Resta un libro */
	 fseek (f,pos*sizeof (struct tipo_libro),SEEK_SET);
	 fwrite (&aux_libro,sizeof (struct tipo_libro),1,f);
	 dar_baja(pos); /* Baja temporal */
	}
   }
   if ( (op=='S') && (num_tema==10) )
   {
	fseek (f, pos * sizeof (struct tipo_libro), SEEK_SET);
	reorganiza (f, sizeof (struct tipo_libro) ); /* BAJA DEFINITIVA */
   }
  }
 }else no_file(); /* SI NO EXISTE EL FICHERO */
 fclose (f);
}

void prestamo(void)
{
 char titulo[51];
 char op;
 int pos;
 struct tipo_libro aux_libro;
 /*int num_reg;*/

 if (num_tema==11) { restringido(); return; }
 if (num_tema==10) { restringido(); return; }




 f= fopen (tema[num_tema],"r+b");
 fseek (f,0,2); /* Se posiciona al final del FILE */
 /*num_reg = ftell (f)/ sizeof (struct tipo_libro);*/  /* Coge el numero de fichas */
 if (f!=NULL)
 {
  ficha();
  textcolor (WHITE);
  textbackground (BLUE);
  centra ("PRESTAMOS",2);
  textbackground (BLACK);
  textcolor (YELLOW);
  gotoxy (4,4);
  cprintf ("T¡tulo: ");
  letra_num (titulo,50);
  pos=busca_ficha (titulo,num_tema);
  if (pos== -1) no_regi();
  else /* SI SE ENCUENTRA LA FICHA */
  {
   fseek (f,pos * sizeof (struct tipo_libro), SEEK_SET);
   fread (&aux_libro, sizeof (struct tipo_libro), 1, f);
   muestra_ficha (aux_libro,0);
   textcolor (WHITE);
   textbackground (BLUE);
   centra ("PRESTAMOS",2);
   textbackground (BLACK);
   textcolor (YELLOW);
   centra ("Quiere prestar este libro.",20);
   centra ("S/N",21);
   do
   {
	op= toupper ( getch() );
   }while ( (op!='S') && (op!='N') );
   if  (op=='S')
   {
	if (aux_libro.ejemplares > 0)
	{
	 aux_libro.ejemplares--;  /*Resta un libro */
	 fseek (f,pos*sizeof (struct tipo_libro),SEEK_SET);
	 fwrite (&aux_libro,sizeof (struct tipo_libro),1,f);
	 dar_prestamo(pos); /* Baja temporal */
	}
	else
	{
	 no_ejemplares();
	}
   }
  }
 }else no_file(); /* SI NO EXISTE EL FICHERO */
 fclose (f);
}


int menu3()
{
 int pos=1;
 char opc;

 textbackground (BLACK);
 clrscr();
 textcolor (WHITE);
 do
 {
  if (pos==1)
  {
   textbackground (RED);
   centra ("Consulta en tema actual",12);
   textbackground (BLACK);
   centra ("Consulta en todos los temas",13);
  }
  else
  {
   textbackground (BLACK);
   centra ("Consulta en tema actual",12);
   textbackground (RED);
   centra ("Consulta en todos los temas",13);
  }
  do
  {
   opc= toupper (getch());
  }while ( (opc!='P') && (opc!='H') && (opc!=13) && (opc!=27) );
  if (pos==1) pos=2;
  else pos=1;
 }while ( (opc!=13) && (opc!=27) );
 if (opc==27) return (0); /* Si presionas ESC devuelve 0 */
 else return (pos); /*Si pulsas una opci¢n devuelve la posicion */
}









void consulta(void)
{
 char titulo[51];
 int opc;
 int aux_tema;
 int aux_pos;
 char ch;
 int pos=-1; /* -1 si no encuentra ficha y la posicion si la encuentra */
 struct tipo_libro aux_libro;


 opc = menu3();
 if (opc==0) return; /* Si se pulsa ESC sale al men£ pricipal*/
 if (opc==2)
 {
  f=fopen (tema[num_tema],"rb");
  if (f==NULL) {no_file();return;}
  ficha();
  textcolor (WHITE);
  textbackground (BLUE);
  centra ("CONSULTA INDIVIDUAL",2);
  textbackground (BLACK);
  textcolor (YELLOW+128);
  gotoxy (4,4);
  cprintf ("T¡tulo: ");
  letra_num (titulo,50);
  pos = busca_ficha (titulo,num_tema); /* Devuelve la posicion de la ficha */
  if (pos==-1) no_regi();
  else
  {
   fseek (f, pos*sizeof (struct tipo_libro), SEEK_SET);
   fread (&aux_libro, sizeof (struct tipo_libro),1,f);
   muestra_ficha (aux_libro,1);
   textcolor (WHITE);
   textbackground (BLUE);
   centra ("CONSULTA INDIVIDUAL",2);
   textcolor (7);
   centra ("þ þ þ Pulse [ESC] para salir þ þ þ",24);
   textbackground (BLACK);
   do
   {
    ch = getch();
   }while (ch!=27);
  }
 }
 if (opc==1)
 {
  ficha();
  textcolor (WHITE);
  textbackground (BLUE);
  centra ("CONSULTA GLOBAL",2);
  textbackground (BLACK);
  textcolor (YELLOW+128);
  gotoxy (4,4);
  cprintf ("T¡tulo: ");
  letra_num (titulo,50);
  for (aux_tema=0;aux_tema<10;aux_tema++)
  {
   pos = busca_ficha (titulo,aux_tema); /* Devuelve la posicion de la ficha */
   if (pos>=0) break;
  }
  if ( (pos==-1)|| (pos==-2) ) no_regi();
  else
  {
   f= fopen (tema[aux_tema],"rb");
   fseek (f, pos*sizeof (struct tipo_libro), SEEK_SET);
   fread (&aux_libro, sizeof (struct tipo_libro),1,f);
   muestra_ficha (aux_libro,0);
   textcolor (WHITE);
   textbackground (BLUE);
   centra ("CONSULTA GLOBAL",2);
   textcolor (7);
   centra ("þ þ þ Pulse [ESC] para salir þ þ þ",24);
   textbackground (BLACK);
   do
   {
    ch = getch();
   }while (ch!=27);
  }
 }
 fclose (f);
}

void listado(void)
{
 int i=0;
 char ch=2;
 struct tipo_libro aux_libro;
 int num_reg; /* El numero de fichas (registros) que contiene el fichaero */


 f= fopen (tema[num_tema],"rb");
 if (f==NULL) no_file();
 else
 {
  fseek (f,0,2);
  num_reg= ftell (f)/sizeof (struct tipo_libro);
  if (num_reg==0) no_file();
  if (num_reg>0) /* SI HAY ALGUN FICHERO */
  {
   do
   {
	clrscr();
	fseek (f, i*sizeof (struct tipo_libro), SEEK_SET);
	fread (&aux_libro, sizeof (struct tipo_libro),1,f);
	muestra_ficha (aux_libro,1);
	textcolor (WHITE);
	textbackground (BLUE);
	centra ("LISTADO",2);
	textbackground (BLACK);
	i++;
	if ( (feof (f) != 00) || (ch==27) ) break;
	gotoxy (36,3);
	textcolor (YELLOW+128);
	cprintf ("%d/%d",i,num_reg);
	textcolor (7);
	textbackground (BLUE);
	centra ("[ENTER] -> siguiente ficha.  [ESC] -> salir del listado",24);
	do
	{
	 ch= getch();
	}while ( (ch!=27) && (ch!=13) );
   }while (i==i); /* siempre */
  }
 }
}

dar_alta_prestamo(int pos)
{

 struct tipo_libro aux_libro;
 int i;
 int aux_tema;
 int pos_alta;
 FILE *f2;



 fseek (f,pos*sizeof (struct tipo_libro), SEEK_SET);
 fread (&aux_libro, sizeof (struct tipo_libro),1,f);
 for (i=0;i<10;i++)  /* Averigua a que tema pertenece */
 {
  if (strcmpi (aux_libro.tema,tema_bien[i]) == 0 )
  {
   aux_tema=i;
   break;
  }
 }/* del FOR */

 f2 = fopen (tema[aux_tema],"r+b");
 pos_alta= busca_ficha (aux_libro.titulo,aux_tema);
 if (pos_alta < 0) /* no existe en las altas*/
 {
  strcpy (aux_libro.estado, "DISPONIBLE");
  fseek (f2,0,2);
  fwrite (&aux_libro,sizeof (struct tipo_libro),1,f2);
 }
 else /*si existe ficha, solo borra del prestamo y aumenta el numero de ejemplares */
 {
  fseek (f2, pos_alta* sizeof (struct tipo_libro), SEEK_SET);/* se posiciona en ficha encontrada */
  fread (&aux_libro,sizeof (struct tipo_libro),1,f2); /* lee ficha de alta */
  aux_libro.ejemplares++;  /* Aumenta los ejemplares*/
  fseek (f2, pos_alta* sizeof (struct tipo_libro), SEEK_SET);/* se vuelve a posicionar*/
  fwrite (&aux_libro,sizeof (struct tipo_libro),1,f2); /* Lo sobre escribe con los ejemplares aumentados*/
 }
 fseek (f, pos * sizeof (struct tipo_libro), SEEK_SET);
 reorganiza (f,sizeof (struct tipo_libro) );
 fclose (f2);
}

void alta_prestamo(void)
{
 int i=0;
 char ch=2;
 struct tipo_libro aux_libro;
 int num_reg; /* El numero de fichas (registros) que contiene el fichero */


 f = fopen (tema[num_tema],"r+b");
 if (f==NULL) no_file();
 else
 {
  fseek (f,0,2);
  num_reg= ftell (f)/sizeof (struct tipo_libro);
  if (num_reg>0) /* SI HAY ALGUN FICHERO */
  {
   do
   {
	clrscr();
	fseek (f, i*sizeof (struct tipo_libro), SEEK_SET);
	fread (&aux_libro, sizeof (struct tipo_libro),1,f);
	muestra_ficha (aux_libro,1);
	textcolor (WHITE);
	textbackground (BLUE);
	centra ("PRESTAO -> ALTAS",2);
	textcolor (7);
	centra ("þ [ENTER] -> Siguiente ficha, [-]  -> devolver libro a ALTAS, [ESC] -> SALIR þ",24);
	textbackground (BLACK);
	i++;
	if ( (feof (f) != 00) || (ch==27) ) break;
	gotoxy (36,3);
	textcolor (YELLOW+128);
	cprintf ("%d/%d",i,num_reg);
	do
	{
	 ch= getch();
	}while ( (ch!=13) && (ch!=27) && (ch!='-') );
	if (ch=='-')
	{
	 textcolor (YELLOW);
	 centra ("¨Seguro que desea retirar el prestamo?",20);
	 centra ("S/N",21);
	 do
	 {
	  ch= toupper ( getch () );
	 }while ( (ch!='S') &&  (ch!='N') );
	 if (ch=='S')
	 {
	  dar_alta_prestamo(i-1); /* Si presiona INSERT da de alta
				   el prestamo que est  en pantalla */
	  return;
	 }
	}
   }while (i==i); /* siempre */
  }
  else no_file();
 }
}


void modificacion(void)
{
 char titulo[51];
 char aux_titulo[51];
 int aux_tema;
 int repe;
 struct tipo_libro aux_libro;
 char aux_letras [51];
 int aux_num;
 int pos;
 char op;


 if (num_tema==10) { restringido(); return; }
 if (num_tema==11) { restringido(); return; }
 f=fopen (tema[num_tema],"r+b");
 if (f!=NULL)
 {
  ficha();
  textcolor (WHITE);
  textbackground (BLUE);
  centra ("MODIFICACION",2);
  textbackground (BLACK);
  textcolor (YELLOW);
  gotoxy (4,4);
  cprintf ("T¡tulo: ");
  letra_num (titulo,50);
  pos=busca_ficha(titulo,num_tema);
  if (pos==-1) no_regi();
  else
  {
   fseek (f, pos*sizeof (struct tipo_libro), SEEK_SET);
   fread (&aux_libro, sizeof (struct tipo_libro),1,f);
   muestra_ficha(aux_libro,1);
   textcolor (WHITE);
   textbackground (BLUE);
   centra ("MODIFICACION",2);
   textbackground (BLACK);
   textcolor (LIGHTBLUE+128);
   centra ("PULSA [ESC] PARA SALIR",24);

   do
   {
	textcolor (LIGHTGREEN); /* ilumina la letra de cada campo*/
	gotoxy (4,4);cprintf ("T");
	gotoxy (4,6);cprintf ("A");
	gotoxy (4,8);cprintf ("E");
	gotoxy (5,12);cprintf ("¥");
	gotoxy (4,14);cprintf ("N");
	gotoxy (5,16);cprintf ("S");
	do
	{
	 op= toupper(getch()); /* Coge el campo para modificarlo*/
	 if (op=='¤') op='¥';
	}while ( (op!='T') && (op!='A') && (op!='E') && (op!='¥')
	&& (op!='N') && (op!='S') && (op!=27) );
	switch (op)
	{
	 case 'T':
		  borra_linea_fondo(4);
		  textcolor (YELLOW);
		  gotoxy (4,4);cprintf ("T¡tulo: ");
		  letra_num (aux_titulo,50);
		  for (aux_tema=0; aux_tema<10;aux_tema++) /* NO MIRA EN BAJAS NI EN PRESTAMOS*/
		  {
		   repe = busca_ficha(aux_titulo,aux_tema);
		   if ( (repe!= -1) && (repe!= -2) )/* Si no repetida */
		   {
		    ficha_repe(aux_tema);
		    return;
		   }
		  }
		  strcpy (aux_libro.titulo , aux_titulo);
		  textcolor (WHITE);
		  gotoxy (4,4);cprintf ("T¡tulo: ");
		  break;
	 case 'A':
		  borra_linea_fondo (6);
		  textcolor (YELLOW);
		  gotoxy (4,6);cprintf ("Autor: ");
		  letra (aux_letras,50);
		  strcpy (aux_libro.autor , aux_letras);
		  textcolor (WHITE);
		  gotoxy (4,6);cprintf ("Autor: ");
		  break;
	 case 'E':
		  borra_linea_fondo (8);
		  textcolor (YELLOW);
		  gotoxy (4,8);cprintf ("Editorial: ");
		  letra (aux_letras,50);
		  strcpy (aux_libro.editorial , aux_letras);
		  textcolor (WHITE);
		  gotoxy (4,8);cprintf ("Editorial: ");
		  break;
	 case '¥':
		  borra_linea_fondo (12);
		  textcolor (YELLOW);
		  gotoxy (4,12); cprintf ("A¤o: ");
                  do
		  {
		   gotoxy (9,12);
		   textcolor (RED);
		   cprintf ("²²²²");
		   gotoxy (9,12);
		   aux_libro.ano=numero(4);
		  }while ( (aux_libro.ano>2100) || (aux_libro.ano<1000) );
		  textcolor (WHITE);
		  gotoxy (4,12);cprintf ("A¤o: ");
		  break;
	 case 'N':
		  borra_linea_fondo (14);
		  textcolor (YELLOW);
		  gotoxy (4,14);cprintf ("N£mero de ejemplares: ");
		  aux_libro.ejemplares= numero(4);
		  textcolor (WHITE);
		  gotoxy (4,14);cprintf ("N£mero de ejemplares: ");
		  break;
	 case 'S':
		  borra_linea_fondo (16);
		  textcolor (YELLOW);
		  gotoxy (4,16);cprintf ("Estado actual: ");
		  letra (aux_letras,50);
		  strcpy (aux_libro.estado , aux_letras);
		  textcolor (WHITE);
		  gotoxy (4,16);cprintf ("Estado actual: ");
		  break;
	} /* end del case */
   }while (op!=27);  /* mientras no se pulse ESC */
   fseek (f, pos*sizeof (struct tipo_libro), SEEK_SET);
   fwrite (&aux_libro, sizeof (struct tipo_libro),1,f);
  }
 }
 else no_file();
 fclose (f);
}





void main (void)
{
 pos_menu=1;
 cursor (0x31,0x31); /* QUITA EL CURSOR */
 cambia_tema();
 for (;;)
 {
  fcloseall();
  pos_menu=menu(pos_menu);
  switch (pos_menu)
  {
   case 1:
	 if (num_tema==11) alta_prestamo();
	 if (num_tema!=11) altas();
	 break;
   case 2: bajas(); break;
   case 3: prestamo(); break;
   case 4: listado();fclose (f);break;
   case 5: modificacion();break;
   case 6: consulta();break;
   case 7: cambia_tema();break;
   case 8: acerca_de();break;
   case 9: fcloseall();
	   textcolor (WHITE);
	   textbackground (BLACK);
	   clrscr();
	   centra ("þþþþ Sergio Caparr¢s Jurado (98-99) þþþþ",1);
	   printf ("\n\n\n");
	   cursor (14,31);
	   exit (0);
	   break;
  }
 }
}

