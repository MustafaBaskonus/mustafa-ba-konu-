/*
* 1-ödev.cxx
* Mustafa Başkonuş
* Bu program 3 - 15 arasındaki tek sayılar boyutunda düz üçgen, ters üçgen ve 5 - 15 arasındaki tek sayılar boyutunda elmas basar.
*/


#include <iostream>

using namespace std;

void duzUcgen(int boyut);
void tersUcgen(int boyut);
void elmas(int boyut);

int main()
{
	int sec1 = 4;//kullanıcının yapmak istediği iş.
	int uzunluk = 4;//İlk seferde döngüye girilmesi için 'boyut' değişkeni 4.

	cout << "Lutfen yapmak istediginiz islemi seciniz."<<endl;
	cout << "1 : Duz Ucgen\n2 : Ters Ucgen\n3 : Elmas\n4 : Cikis\n";
	cin >> sec1;//kullanıcının seçtiği işlem alınır.
	

		
	if (sec1 == 1) //Seçim 1 ise	
	{
		int can = 3;//kullanıcını sayı girme hakkı
		int haber = 0;//
		while (can > 0 && ((uzunluk%2)!=1 || 3>=uzunluk || uzunluk>=15))//İlk seferde döngüye girilmesi için 'boyut' değişkeni 4, 'can' değişkeni üç olarak belirlendi.
		{
			cout << "Duz ucgenin tabani kac birimlik olsun?\n\n";
			cin >>uzunluk;
			if ((uzunluk % 2) == 1 && 3 <= uzunluk && uzunluk <= 15)
			{
				haber = 1;
			}
			if (haber == 0)
			{
				can--;//'can' değişkeni kalan seçim hakkını temsil eder.
				cout << "Gecersiz boyut girdiniz!!" << endl << can << " hakkiniz kaldi\n\n";
			}
		}
		if (can != 0)//Eğer seçim hakkı bitmediyse
			duzUcgen(uzunluk);//Fonksiyonunu çağır
		else //değer girme hakkı bittiyse kapanır.
			exit(1);

	}
	


	if (sec1 == 2)
	{
		int can = 3;
		int haber = 0;
		while (can > 0 && ((uzunluk % 2) != 1 || 3 >= uzunluk || uzunluk >= 15))//İlk seferde döngüye girilmesi için 'boyut' değişkeni 4, 'can' değişkeni üç olarak belirlendi.
		{
			cout << "Ters ucgenin tavani kac birimlik olsun?\n\n";
			cin >> uzunluk;
			if ((uzunluk % 2) == 1 && 3 <= uzunluk && uzunluk <= 15)
			{
				haber = 1;
			}
			if (haber == 0)
			{
				can--;//'can' değişkeni kalan seçim hakkını temsil eder.
				cout << "Gecersiz boyut girdiniz!!" << endl << can << " hakkiniz kaldi\n\n";
			}
			
		}
		if (can != 0)
			tersUcgen(uzunluk);
		else //değer girme hakkı bittiyse kapanır.
			exit(1);
	}





	if (sec1 == 3) {
		int can = 3;
		int haber = 0;
		
		while (can > 0 && ((uzunluk % 2) != 1 || 3 >= uzunluk || uzunluk >= 15))//İlk seferde döngüye girilmesi için 'boyut' değişkeni 4, 'can' değişkeni üç olarak belirlendi.
		{
			cout << "Elmasin ortası kac birimlik olsun?\n\n";
			cin >> uzunluk;
			if ((uzunluk % 2) == 1 && 3 <= uzunluk && uzunluk <= 15)
			{
				haber = 1;
			}
			if (haber == 0)
			{
				can--;//'can' değişkeni kalan seçim hakkını temsil eder.
				cout << "Gecersiz boyut girdiniz!!" << endl << can << " hakkiniz kaldi\n\n";
			}
		}
		if (can != 0)
			elmas(uzunluk);
		else //değer girme hakkı bittiyse kapanır.
			exit(1);
	}



	if (sec1 == 4)
	{
		exit(1);
	}

	return 0;
}



void duzUcgen(int boyut)
{

	int x, y, carp = 1, bosluk = (boyut - 1) / 2;//'bosluk' değişkeni ilk yıldızı basarken kaç boşluk bırakılacağını belirtir.'x' ve 'y' değişkenleri döngü sayaçlarıdır

	for (x = 0; x < (boyut + 1) / 2; x++) {
		for (y = 0; y < bosluk; y++) {//Boşlukları basan döngü
			cout << " ";
		}

		for (y = 0; y < carp; y++) {//Yıldızları basan döngü
			cout << "*";
		}

		cout << endl;
		carp += 2;//Üçgenin oluşturduğu şekil piramit şeklinde olduğu için her seferde 2 şer tane artacak.
		bosluk -= 1;
	}
}




void tersUcgen(int boyut)
{

	int x = 0, y = 0, bosluk = 0, z = (boyut + 1) / 2;//'z' değişkeni piramitin yüksekliğinin kaç satır olacağını tutar.

	while (z > 0) {//Üçgenin kaç satır olacağını belirleyen döngü oluşturuldu.

		while (bosluk <= y) {//Boşluk basan döngü
			cout << " ";
			bosluk++;
		}

		while (x < boyut) {//Yıldız basan döngü
			cout << "*";
			x++;
		}

		cout << endl;
		x = 0;
		bosluk = 0;
		y++;
		z--;
		boyut -= 2;
	}
}



void elmas(int boyut)
{

	duzUcgen(boyut);
	tersUcgen(boyut - 2);
}
