#include <stdio.h>
#include <stdlib.h>

typedef struct reservasiVaksin{ 		// Menjelaskan identitas dan keadaan user
	char nama[100];
	char nik[100];
	int umur;
	int alergi;
	int penyintas;
	int autoimun;
} resv;

// Fungsi Modular
void clearScreen();					// Berfungsi untuk membersihkan layar
int mengulangAtauBerhenti();		// Berfungsi untuk mengulang atau memberhentikan program
void displayMenu();					// Berfungsi untuk menampilkan menu awal

int main() {
	resv *ptr;
	clearScreen();
	const char *domisili[] = { "", "Jakarta", "Bogor", "Depok", "Tangerang", "Bekasi" }; //5 jenis domisili Jabodetabek
	const char *namaKontakLayananDomisili[] = { "", "Rifaldi", "Bintang", "Mulyono", "Agnes", "Alika" }; //nama 5 orang petugas masing2 domisili tsb
	const char *nomorKontakLayananDomisili[] = { "", "0262 4995 4563", "0539 5311 5110", "0865 7028 6708", "0890 7625 8681", "0851 2299 6121" }; //no hp 5 orang petugas tadi
	const char *rumahSakitRujukan[] = { "", "Rumah Sakit Fatmawati", "RSUD Kota Bogor", "RS Mitra Keluarga", "RSUD Kota Tangerang", "RSUD Kota Bekasi"}; // 5 Rumah Sakit rujukan sesuai dengan domisili
	const char namaKontakLayananPusat[] = "Rahman"; //nama koordinator pusat
	const char nomorKontakLayananPusat[] = "0858 5883 3885"; //no hp koordinator pusat
	int penerima, i, j = 0, domisili_pilihan; 
	char temp; 
	
	ptr = (resv *) malloc(penerima * sizeof(resv));
	int *s = calloc (penerima, sizeof(int));

	if(ptr == NULL){
		printf("Error! memory not allocated.");
		exit(0);
	}

	if(s == NULL){
		printf("Error! memory not allocated.");
		exit(0);
	}
  
	do { // Pengulangan Utama Apabila User ingin memesan vaksin kembali
		do {
			kembali:     // Mengembalikan user ke menu awal
    		displayMenu();
    		printf("Masukkan jumlah penerima vaksin : ");
    		scanf("%d", &penerima);

    		if ( penerima <= 0 || penerima > 3){
        		j = mengulangAtauBerhenti(); 
        		if( j == 0){ //  0 disini adalah mengulang, input berhenti akan langsung diexit dari fungsinya
        			clearScreen();
					continue;
	    		}
	    	}

    		printf("\nMasukkan Nama dan NIK masing-masing secara berurutan\n");
    		printf("Contoh : Nama : Daffa Hilmy \n         NIK  : 1234567890\n");

    		for (i = 0; i < penerima; i++){
    	    	printf("\n%d. ", i+1);
    	    	printf("Nama : ");
    	    	scanf("%c",&temp);
				scanf("%[^\n]s", &(ptr + i)->nama);
				printf("   NIK  : ");
				scanf("%s", &(ptr + i)->nik);
   	
		    	printf("\nApakah anda berumur dibawah 17 tahun?\n(pilih 1=ya,pilih 0=tidak) : ");
    			scanf("%d", &(ptr + i)->umur);
    			switch((ptr + i)->umur){
    				case 0 :                   		// Apabila memenuhi syarat
    					break;
        			case 1 : 
        				*(s + i) = 1;             	// Apabila tidak memenuhi syarat
            			break;
        			default :
        				j = mengulangAtauBerhenti();  // Apabila input salah, user dapat mengulang atau menghentikan program
        				if (j == 0){
        					clearScreen();
        					goto kembali;				// Mengembalikan user ke menu awal
						}
    					break;
        		}

        		printf("\nApakah anda memiliki alergi terhadap bahan vaksin?\n(pilih 1=ya,pilih 0=tidak) : ");
        		scanf("%d", &(ptr + i)->alergi);
    			switch((ptr + i)->alergi){
        			case 0 :          				// Apabila memenuhi syarat
            			break;
        			case 1 : 
            			*(s + i) = 1;             	// Apabila tidak memenuhi syarat
            			break;
          			default :
            			j = mengulangAtauBerhenti();  // Apabila input salah, user dapat mengulang atau menghentikan program
        				if (j == 0){
        					clearScreen();
        					goto kembali;			// Mengembalikan user ke menu awal
						}
    					break;
        		}	

        		printf("\nApakah anda merupakan penyintas covid dalam 3 bulan terakhir?\n(pilih 1=ya,pilih 0=tidak) : ");
        		scanf("%d", &(ptr + i)->penyintas);
				switch((ptr + i)->penyintas){
        			case 0 :  		                 // Apabila memenuhi syarat
        				break;
        			case 1 : 
            			*(s + i) = 1;	             // Apabila tidak memenuhi syarat
            			break;
          			default :
            			j = mengulangAtauBerhenti();  // Apabila input salah, user dapat mengulang atau menghentikan program
        				if (j == 0){
        					clearScreen();
        					goto kembali;			// Mengembalikan user ke menu awal
						}
    					break;
        		}

       			printf("\nApakah anda memiliki penyakit autoimun?\n(pilih 1=ya,pilih 0=tidak) : ");
       			scanf("%d", &(ptr + i)->autoimun);
        		switch((ptr + i)->autoimun){
          			case 0 :                   		// Apabila memenuhi syarat
            			break;
          			case 1 : 
            			*(s + i) = 1;               // Apabila tidak memenuhi syarat
            			break;
          			default :
            			j = mengulangAtauBerhenti();  // Apabila input salah, user dapat mengulang atau menghentikan program
        				if (j == 0){
        					clearScreen();
        					goto kembali;			// Mengembalikan user ke menu awal
						}
    					break;
        		}
			}
			
			printf( "\nKonfirmasi data? (ya = 1, ulang = 0): " ); //konfirmasi data, 1 untuk lanjut dan 0 untuk mengulang
			scanf( "%d", &j );
			clearScreen();
			if (j * j != j){
				j = mengulangAtauBerhenti();
				clearScreen();
			}
			
    	}while ( j == 0); // Do While 1

		do{  // DO WHILE 2
			clearScreen();
			printf("\nPilihlah domisili anda\n");

			for (i=1;i<=5;++i){
        		printf("%d. %s\n", i, domisili[i]);
			}

    		printf("Pilihan Domisili : ");
    		scanf("%d", &domisili_pilihan);
    		switch(domisili_pilihan){
        		case 1:
        			j = 1;
					break;
				case 2:
        			j = 2;
					break;
				case 3:	
        			j = 3;		//switch domisili_pilihan.
					break;		//pemesan juga  akan diberikan kesempatan untuk membatalkan atau mengulang pesanan
				case 4:	
    			    j = 4;		//apabila domisili tidak valid
					break;
				case 5:
    			    j = 5;
					break;
				default:
        			j = mengulangAtauBerhenti();
        			break;
        	}
    	}while (j == 0); // Do While 2
  
    	// Mencetak Output
    	clearScreen();
    	printf("\n=== HASIL PERSYARATAN VAKSIN ===\n");// OUTPUT
    	for(i=0; i<penerima; ++i){
    		printf("\nNama Pemesan : %s\nNIK\t     : %s", (ptr + i)->nama, (ptr +i)->nik);
    		if(*(s + i) == 0){
        		printf("\n--------------------------------------------------");
        		printf("\n| Status : Anda lolos persyaratan vaksin");
    			printf("\n| Domisili : %s", domisili[domisili_pilihan] );
    			printf("\n| Rumah Sakit Rujukan : %s", rumahSakitRujukan[domisili_pilihan]);
            	printf("\n| Contact Person : %s", namaKontakLayananDomisili[domisili_pilihan]);
        		printf("\n| Nomor Contact Person : %s", nomorKontakLayananDomisili[domisili_pilihan]);
        		printf("\n|\n|      Tertanda\n|" );
        		printf("        __\n|" );
        		printf("       /  \\________\n|" );
        		printf("       \\_ /        \\\n|" );
        		printf("        /          /\n|" );
        		printf("    /\\_/          /\n|" );     //terlihat berantakan
        		printf("    \\_/ \\________/\n|" );     //namun seperti inilah cara supaya outputnya tidak berantakan
        		printf("     /    \\\n|" );
        		printf("    /      \\\n|" );
        		printf("   /        \\\n|" );
        		printf("  /          \\___/\n|" );
        		printf("\n|" );
        		printf("       %s       \n|", namaKontakLayananPusat);
        		printf("   %s\n|", nomorKontakLayananPusat);
        		printf("\n--------------------------------------------------\n");
      		}else if(*(s + i) == 1){
        		printf("\nStatus : Anda tidak lolos persyaratan vaksin\n");
      		}
    	}
    	
    	// Menawarkan pemesan kesempatan untuk melanjutkan pemesanan atau berhenti melakukan pemesanan
    	printf( "\nHentikan pemesanan? (ya = 1, pesan lagi = 0): " );
		scanf( "%d", &j );
		clearScreen();
		if (j * j != j){
			j = mengulangAtauBerhenti();
			clearScreen();
		}
		
	}while (j == 0);  // DO WHILE INTI
  return 0;
}

int mengulangAtauBerhenti(){
	int j;
	do{
    	printf( "Input tidak valid. Hentikan pemesanan? (ya = 1, ulang = 0): " );
    	scanf( "%d", &j ); //kalau tidak valid, user bisa keluar dari program atau mencoba input lagi
    	if( j == 1 ){
    		printf( "\nPemesanan vaksin COVID-19 telah dihentikan.\n" ); //batal deh
    		exit(0);
    	}else if( j == 0 ){
    		return 0;
    	}
	} while( j * j != j ); //disini j hanya bisa 1 atau 0. Maka, do while akan terus looping apabila input j bukan 1 atau 0
}

void displayMenu(){
	printf( "\n---------- PROGRAM PEMESANAN VAKSIN COVID-19 DAERAH JABODETABEK ---------- \n" ); //introduksi tentang program dan 
	printf( "\nPoin-poin penting: \n" );
	printf( "1. Harap isi data sesuai yang diminta saja. Program akan memulai kembali apabila anda salah dalam memasukkan data\n");
	printf( "2. Pemesanan vaksin hanya dikhususkan masyarakat di daerah Jabodetabek.\n");
	printf( "3. Harap matikan program apabila pemesanan akan dilakukan untuk luar Jabodetabek.\n" );
	printf( "4. Tiap pemesanan tidak lebih dari 3 vaksin\n" );
	printf( "5. Vaksin tidak dikenakan biaya sepeserpun\n" );
	printf( "6. Layanan pemesanan vaksin tersedia 24/7 untuk setiap domisili\n" );
	printf( "7. Terdapat syarat-syarat yang harus dipenuhi oleh penerima vaksin, yaitu:\n" );
	printf( "    a. Berusia di atas 17 tahun\n" );
	printf( "    b. Tidak memiliki alergi terhadap bahan vaksin\n" );
	printf( "    c. Bukan merupakan penyintas Covid-19 dalam 3 bulan terakhir\n" );
	printf( "    d. Tidak memiliki penyakit autoimun\n" );
	        
	printf( "note: Semua data yang akan diinput akan kembali dicek kebenarannya oleh layanan pusat\n\n\n" );
}

void clearScreen(){
	system ("cls");   // Untuk membersihkan layar
}
