
#include <stdio.h>

int main(void)
{
	int zijnrijengeldig(int puzzel[9][9]);
	int zijnkolommengeldig(int puzzel[9][9]);
	int zijnblokkengeldig(int puzzel[9][9]);
	
	int puzzle1[9][9] =
	{
		{ 8, 6, 0, 0, 2, 0, 0, 0, 0 },
		{ 0, 0, 0, 7, 0, 0, 0, 5, 9 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 6, 0, 8, 0, 0 },
		{ 0, 4, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 5, 3, 0, 0, 0, 0, 7 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 2, 0, 0, 0, 0, 6, 0, 0 },
		{ 0, 0, 7, 5, 0, 9, 0, 0, 0 }
	};
	int solution1[9][9] =
	{
		{ 8, 6, 3, 9, 2, 5, 7, 4, 1 },
		{ 4, 1, 2, 7, 8, 6, 3, 5, 9 },
		{ 7, 5, 9, 4, 1, 3, 2, 8, 6 },
		{ 9, 7, 1, 2, 6, 4, 8, 3, 5 },
		{ 3, 4, 6, 8, 5, 7, 9, 1, 2 },
		{ 2, 8, 5, 3, 9, 1, 4, 6, 7 },
		{ 1, 9, 8, 6, 3, 2, 5, 7, 4 },
		{ 5, 2, 4, 1, 7, 8, 6, 9, 3 },
		{ 6, 3, 7, 5, 4, 9, 1, 2, 8 }
	};

	int antwoordrij,antwoordkolom,antwoordblok;

	printf("Welkom\n");

	antwoordrij = zijnrijengeldig(solution1);
	antwoordkolom = zijnkolommengeldig(solution1);
	antwoordblok = zijnblokkengeldig(solution1);

	printf("\n\nEn de antwoorden zijn = %d %d %d", antwoordrij, antwoordkolom, antwoordblok);

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
						printf("\nCheck rij %d kolom %d uitkomst %d", rij+1, kolom+1, puzzel[rij][kolom]);

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