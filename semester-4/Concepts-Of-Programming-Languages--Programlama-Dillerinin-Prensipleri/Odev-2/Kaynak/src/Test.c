/**
 * 	 @author		Yusuf Ozaslan
 * 	 @class			1. ogretim A grubu
 *	 @No			B201210033
 * 	 @email			yusuf.ozaslan@ogr.sakarya.edu.tr
 *	 @since			17/04/2022
 *	 @assignment	2. Odev
 **/
#include "stdio.h"
#include "stdlib.h"
#include "Oyun.h"

int main()
{
	Oyun oyun = new_Oyun();
	oyun->Basla(oyun);
	oyun->delete(oyun);
	printf("\n\n");
	return 0;
}