#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include "dynlist.h"

//Thomas Linssen

const size_t Height = 10, Width = 20;

//template<typename T, size_t Y, size_t X>
void Clear(char (&inv)[Height][Width])//(T (&inv)[Y][X])
{	
		for(size_t i = 0; i < Height; i++)
		{
			for(size_t j = 0; j < Width; j++)
			{
				inv[i][j] = '~';
			}
		}	
}

//template<typename T, size_t Y, size_t X>
void display(char (&inv)[Height][Width], const DynamicList<char>& items)//(T (&inv)[Y][X])
{	
	size_t index = 0;
	for(size_t i = 0; i < Height; i++)
	{
		bool done;
		for(size_t j = 0; j < Width; j++)
		{
			inv[i][j] = items.Get(index++);
			if(index == items.Length()){done = 1; break;}
		}
		if(done)break;
	}
	
	for(size_t i = 0; i < Height; i++)
	{
		for(size_t j = 0; j < Width; j++)
		{
			printf("%c", inv[i][j]);
		}
		printf("\n");
	}	
	printf("\n");
}

void Insert(char (&inv)[Height][Width], size_t y, size_t x, char item)
{
	inv[y][x] = item;
}

void Remove(char (&inv)[Height][Width], size_t y, size_t x)
{
	inv[y][x] = '~';
}

void sort(const char (&inv)[Height][Width], DynamicList<char>& itemList)
{	
	std::vector<uint8_t> items;
	items.reserve(itemList.Length());
	
	for(size_t i = 0; i < itemList.Length(); i++)
	{
		items.emplace_back(static_cast<uint8_t>(itemList.Get(i)));
	}
	
    std::sort(items.begin(), items.end(), std::greater<uint8_t>());
	
	for(size_t i = 0; i < itemList.Length(); i++)
	{
		itemList.Insert(i,static_cast<char>(items[i]));
	}	
}

void UseItem(const char (&inv)[Height][Width], size_t y, size_t x)
{
	printf("selects item on x %i and y %i\n", x, y);
	
	char item = inv[y][x];
	switch(item)
	{
		case '!': printf("*uses axe*"); break;
		case '&': printf("*uses sword*"); break;
		case '$': printf("*uses gun*"); break;
		case '@': printf("*uses stone*"); break;
		case '*': printf("*uses hammer*"); break;
	}
}

int main()
{
	char inv[Height][Width];
	Clear(inv); //Reset/initiate de inventory naar 'niets'

	//Aparte lijst om items bij te houden
	DynamicList<char> items;
	
	//De speler 'ontvangt' een hoeveelheid items (optimalizeer later)
	items.Add('!');
	items.Add('$');
	items.Add('!');
	items.Add('$');
	items.Add('&');
	items.Add('$');
	items.Add('!');
	items.Add('!');
	items.Add('@');
	
	//Visueel aspect
	sort(inv, items);	//Sorteert de items van groot naar klein (gebaseerd op ASCII waarden in decimaal)
	display(inv, items);
	
	//Gebruik een item
	UseItem(inv, 0,3);
	
	return 0;
}



























