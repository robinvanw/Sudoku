
#include <stdio.h>

int main(void)
{
	int zijnrijengeldig(int puzzel[9][9]);
	int zijnkolommengeldig(int puzzel[9][9]);
	int zijnblokkengeldig(int puzzel[9][9]);
	int isgeldig(int puzzel[9][9]);
	int oplossen(int puzzel[9][9]);
	int oplossenreverse(int puzzel[9][9]);
	int controle(int puzzel[9][9], int puzzelreverse[9][9]);

	int rij, kolom, puzzel[9][9], puzzelreverse[9][9], geldig;

	FILE * bestand;
	bestand = fopen("F:\Sudoku leeg.txt", "r");

	printf("\nWelkom\n\n");

	for (rij = 0; rij < 9; rij = rij + 1)
	{
		for (kolom = 0; kolom < 9; kolom = kolom + 1)
		{
			fscanf(bestand, "%d", &puzzel[rij][kolom]);
			puzzelreverse[rij][kolom] = puzzel[rij][kolom];
			printf("%d ", puzzel[rij][kolom]);
		}
		printf("\n");
	}

	printf("\nWilt u deze sudoku oplossen ? (enter)");
	getchar();
	printf("\nBezig met oplossen ...\n");

	oplossen(puzzel);

	printf("\n");

	for (rij = 0; rij < 9; rij = rij + 1)
	{
		for (kolom = 0; kolom < 9; kolom = kolom + 1)
		{
			printf("%d ",puzzel[rij][kolom]);
		}
		printf("\n");
	}

	printf("\nBezig met oplossen controle ...\n\n");

	oplossenreverse(puzzelreverse);

	for (rij = 0; rij < 9; rij = rij + 1)
	{
		for (kolom = 0; kolom < 9; kolom = kolom + 1)
		{
			printf("%d ", puzzelreverse[rij][kolom]);
		}
		printf("\n");
	}

	geldig = controle(puzzel, puzzelreverse);

	if (geldig == 1)	{ printf("\nDe sudoku is opgelost en is geldig !\n"); }
	else				{ printf("\nDe sudoku is opgelost maar is NIET geldig !\n"); }

	fclose(bestand);
	getchar();
	return 0;
}

int zijnrijengeldig(int puzzel[9][9])
{
	int rij, kolom, check[9], teller, digit;

	for (teller = 0; teller < 9; teller = teller + 1)	{ check[teller] = 0; }

	for (rij = 0; rij < 9; rij = rij + 1)
	{
		for (teller = 0; teller < 9; teller = teller + 1)	{ check[teller] = 0; }
		for (kolom = 0; kolom < 9; kolom = kolom + 1)
		{
			digit = puzzel[rij][kolom];
			if (digit != 0)
			{
				if (check[digit - 1] == 0)
				{
					check[digit - 1] = 1;
				}
				else
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

int zijnkolommengeldig(int puzzel[9][9])
{
	int rij, kolom, check[9], teller, digit;

	for (teller = 0; teller < 9; teller = teller + 1)	{ check[teller] = 0; }

	for (kolom = 0; kolom < 9; kolom = kolom + 1)
	{
		for (teller = 0; teller < 9; teller = teller + 1)	{ check[teller] = 0; }
		for (rij = 0; rij < 9; rij = rij + 1)
		{
			digit = puzzel[rij][kolom];
			if (digit != 0)
			{
				if (check[digit - 1] == 0)
				{
					check[digit - 1] = 1;
				}
				else
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

int zijnblokkengeldig(int puzzel[9][9])
{
	int rij, kolom, check[9], teller, digit;
	int plus[3] = { 0, 3, 6 };
	int selectrij,selectkolom;

	for (selectrij = 0; selectrij < 3; selectrij = selectrij + 1)
	{
		for (selectkolom = 0; selectkolom < 3; selectkolom = selectkolom + 1)
		{
			for (teller = 0; teller < 9; teller = teller + 1)	{ check[teller] = 0; }

			for (rij = (0 + plus[selectrij]); rij < (3 + plus[selectrij]); rij = rij + 1)
			{
				for (kolom = (0 + plus[selectkolom]); kolom < (3 + plus[selectkolom]); kolom = kolom + 1)
				{
					digit = puzzel[rij][kolom];
					if (digit != 0)
					{
						if (check[digit - 1] == 0)
						{
							check[digit - 1] = 1;
						}
						else
						{
							return 0;
						}
					}
				}
			}
		}
	}
	return 1;
}

int isgeldig(int puzzel[9][9])
{
	int antwoordrij, antwoordkolom, antwoordblok, geldig=0;

	antwoordrij = zijnrijengeldig(puzzel);
	antwoordkolom = zijnkolommengeldig(puzzel);
	antwoordblok = zijnblokkengeldig(puzzel);

	geldig = antwoordrij + antwoordkolom + antwoordblok;

	if (geldig == 3)	{return 1;}
	else				{return 0;}
}

int oplossen(int puzzel[9][9])
{
	int rij, kolom, digit;

	for (rij = 0; rij < 9; rij = rij + 1)
	{
		for (kolom = 0; kolom < 9; kolom = kolom + 1)
		{
			if (puzzel[rij][kolom] == 0)
			{
				for (digit = 1; digit <= 9; digit = digit + 1)
				{
					puzzel[rij][kolom] = digit;
					if (isgeldig(puzzel) && oplossen(puzzel) == 1)
					{
						return 1;
					}
					puzzel[rij][kolom] = 0;
				}
				return 0;
			}
		}
	}
	return 1;
}

int oplossenreverse(int puzzel[9][9])
{
	int rij, kolom, digit;

	for (rij = 9; rij > 0; rij = rij - 1)
	{
		for (kolom = 9; kolom > 0; kolom = kolom - 1)
		{
			if (puzzel[rij][kolom] == 0)
			{
				for (digit = 9; digit >= 1; digit = digit - 1)
				{
					puzzel[rij][kolom] = digit;
					if (isgeldig(puzzel) && oplossen(puzzel) == 1)
					{
						return 1;
					}
					puzzel[rij][kolom] = 0;
				}
				return 0;
			}
		}
	}
	return 1;
}

int controle(int puzzel[9][9], int puzzelreverse[9][9])
{
	int rij, kolom, goed=0, digit1, digit2;

	for (rij = 0; rij < 9; rij = rij + 1)
	{
		for (kolom = 0; kolom < 9; kolom = kolom + 1)
		{
			if (puzzel[rij][kolom] == puzzelreverse[rij][kolom])	{ goed = goed + 1; }
			else													{ return 0; }
		}
	}
	if (goed == 81)		{ return 1; }
	else				{ return 0; }
}

/*
Sudoku 1

1 0 0 0 0 0 0 0 6
0 0 6 0 2 0 7 0 0
7 8 9 4 5 0 1 0 3
0 0 0 8 0 7 0 0 4
0 0 0 0 3 0 0 0 0
0 9 0 0 0 4 2 0 1
3 1 2 9 7 0 0 4 0
0 4 0 0 1 2 0 7 8
9 0 8 0 0 0 0 0 0

Sudoku 2

8 6 0 0 2 0 0 0 0
0 0 0 7 0 0 0 5 9
0 0 0 0 0 0 0 0 0
0 0 0 0 6 0 8 0 0
0 4 0 0 0 0 0 0 0
0 0 5 3 0 0 0 0 7
0 0 0 0 0 0 0 0 0
0 2 0 0 0 0 6 0 0
0 0 7 5 0 9 0 0 0

Sudoku 3

0 6 0 0 2 0 0 0 0
0 0 0 7 0 0 0 5 9
0 0 0 0 0 0 0 0 0
0 0 0 0 6 0 8 0 0
0 4 0 0 0 0 0 0 0
0 0 5 3 0 0 0 0 7
0 0 0 0 0 0 0 0 0
0 2 0 0 0 0 6 0 0
0 0 7 5 0 9 0 0 0

Sudoku leeg

0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
*/