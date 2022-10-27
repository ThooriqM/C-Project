#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//Linked List for store all data
struct node{
    char namaBarang[50];
    int hargaBarang;
    int kodeBarang;

    struct node *nextNode;
};

//linked list for cashout (menyimpan barang yang ingin dibeli)
struct finalNode{
    char namaBarang[50];
    int hargaBarang;
    int kodeBarang;

    int jumlah;
    int total;

    struct node *nextNode;
};

//binary Tree for searching data
struct binaryTree{
    char namaBarang[50];
    int hargaBarang;
    int kodeBarang;

    struct binaryTree *leftPtr;
    struct binaryTree *rightPtr;
};

void mainMenu(void);
void display_katalog(struct node *startNode);
struct node *addNodeLinkedListFirst(struct node *startNode, int kodeBarang, int hargaBarang, char namaBarang[50]);
struct finalNode *searchNode(struct node *startNode, struct finalNode *newNode, int kodeBarangInput, int jumlah);
void displayCashOut(struct finalNode *startFinalNode);
int inputErrorHandling(struct node *startNode, int kodeBarang);
void user_instruction(void);
void display_nama_barang_menu3(struct binaryTree *startNode, char namaBarangInput[50]);
void menu_1(struct node *startNode, struct finalNode *newNode);
void menu_3(struct binaryTree *headTree);
void printTreeNode(struct binaryTree *headTree, int kodeBarangInput);

struct node *deleteStuff(struct node *startNode,int kodeBarangInput);


int main(){
    int choice, choice3, n;
    int kodeBarangInput;
    int hargaBarangInput;
    char namaBarangInput[50];
    char namaBarangInput1[50];
    int errorHandlingOutput;
    int errorHandling;


    struct finalNode *newNode1 = NULL;


    //Linked list predefined data
    struct node *data_1 = NULL;
    struct node *data_2 = NULL;
    struct node *data_3 = NULL;
    struct node *data_4 = NULL;
    struct node *data_5 = NULL;
    struct node *data_6 = NULL;
    struct node *data_7 = NULL;
    struct node *data_8 = NULL;
    struct node *data_9 = NULL;
    struct node *data_10 = NULL;

    data_1 = (struct node*)malloc(sizeof(struct node));
    data_2 = (struct node*)malloc(sizeof(struct node));
    data_3 = (struct node*)malloc(sizeof(struct node));
    data_4 = (struct node*)malloc(sizeof(struct node));
    data_5 = (struct node*)malloc(sizeof(struct node));
    data_6 = (struct node*)malloc(sizeof(struct node));
    data_7 = (struct node*)malloc(sizeof(struct node));
    data_8 = (struct node*)malloc(sizeof(struct node));
    data_9 = (struct node*)malloc(sizeof(struct node));
    data_10 = (struct node*)malloc(sizeof(struct node));

    strcpy(data_1->namaBarang, "Susu Merk A");data_1->hargaBarang = 15000;data_1->kodeBarang = 123;data_1->nextNode = data_2;
    strcpy(data_2->namaBarang, "Deodorant Merk C");data_2->hargaBarang = 10000;data_2->kodeBarang = 789;data_2->nextNode = data_3;
    strcpy(data_3->namaBarang, "Air Merk B");data_3->hargaBarang = 5000;data_3->kodeBarang = 456;data_3->nextNode = data_4;
    strcpy(data_4->namaBarang, "Kopi Merk F");data_4->hargaBarang = 7000;data_4->kodeBarang = 558;data_4->nextNode = data_5;
    strcpy(data_5->namaBarang, "Tisu Merk H");data_5->hargaBarang = 2000;data_5->kodeBarang = 992;data_5->nextNode = data_6;
    strcpy(data_6->namaBarang, "Jus Merk O");data_6->hargaBarang = 12000;data_6->kodeBarang = 295;data_6->nextNode = data_7;
    strcpy(data_7->namaBarang, "Yogurt Merk X");data_7->hargaBarang = 4000;data_7->kodeBarang = 195;data_7->nextNode = data_8;
    strcpy(data_8->namaBarang, "Coklat Merk D");data_8->hargaBarang = 8000;data_8->kodeBarang = 336;data_8->nextNode = data_9;
    strcpy(data_9->namaBarang, "Pulpen Merk S");data_9->hargaBarang = 20000;data_9->kodeBarang = 741;data_9->nextNode = data_10;
    strcpy(data_10->namaBarang, "Minyak Merk P");data_10->hargaBarang = 25000;data_10->kodeBarang = 990;data_10->nextNode = NULL;


    //binary Tree predefined data
    struct binaryTree *data1 = NULL;
    struct binaryTree *data2 = NULL;
    struct binaryTree *data3 = NULL;
    struct binaryTree *data4 = NULL;
    struct binaryTree *data5 = NULL;
    struct binaryTree *data6 = NULL;
    struct binaryTree *data7 = NULL;
    struct binaryTree *data8 = NULL;
    struct binaryTree *data9 = NULL;
    struct binaryTree *data10 = NULL;

    data1 = (struct binaryTree*)malloc(sizeof(struct binaryTree));
    data2 = (struct binaryTree*)malloc(sizeof(struct binaryTree));
    data3 = (struct binaryTree*)malloc(sizeof(struct binaryTree));
    data4 = (struct binaryTree*)malloc(sizeof(struct binaryTree));
    data5 = (struct binaryTree*)malloc(sizeof(struct binaryTree));
    data6 = (struct binaryTree*)malloc(sizeof(struct binaryTree));
    data7 = (struct binaryTree*)malloc(sizeof(struct binaryTree));
    data8 = (struct binaryTree*)malloc(sizeof(struct binaryTree));
    data9 = (struct binaryTree*)malloc(sizeof(struct binaryTree));
    data10 = (struct binaryTree*)malloc(sizeof(struct binaryTree));


    strcpy(data1->namaBarang, "Susu Merk A");data1->hargaBarang = 15000;data1->kodeBarang = 123;data1->leftPtr = NULL;data1->rightPtr = NULL;
    strcpy(data2->namaBarang, "Deodorant Merk C");data2->hargaBarang = 10000;data2->kodeBarang = 789;data2->leftPtr =data9;data2->rightPtr = data10;
    strcpy(data3->namaBarang, "Air Merk B");data3->hargaBarang = 5000;data3->kodeBarang = 456;data3->leftPtr = data7;data3->rightPtr = data2;
    strcpy(data4->namaBarang, "Kopi Merk F");data4->hargaBarang = 7000;data4->kodeBarang = 558;data4->leftPtr = NULL;data4->rightPtr = NULL;
    strcpy(data5->namaBarang, "Tisu Merk H");data5->hargaBarang = 2000;data5->kodeBarang = 992;data5->leftPtr = NULL;data5->rightPtr = NULL;
    strcpy(data6->namaBarang, "Jus Merk O");data6->hargaBarang = 12000;data6->kodeBarang = 295;data6->leftPtr = NULL;data6->rightPtr = data8;
    strcpy(data7->namaBarang, "Yogurt Merk X");data7->hargaBarang = 4000;data7->kodeBarang = 195;data7->leftPtr = data1;data7->rightPtr = data6;
    strcpy(data8->namaBarang, "Coklat Merk D");data8->hargaBarang = 8000;data8->kodeBarang = 336;data8->leftPtr = NULL;data8->rightPtr = NULL;
    strcpy(data9->namaBarang, "Pulpen Merk S");data9->hargaBarang = 20000;data9->kodeBarang = 741;data9->leftPtr = data4;data9->rightPtr = NULL;
    strcpy(data10->namaBarang, "Minyak Merk P");data10->hargaBarang = 25000;data10->kodeBarang = 990;data10->leftPtr = NULL;data10->rightPtr = data5;



    //predefined data


    while(1){
        mainMenu();
        printf("Silakan masukkan pilihan Anda: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice){
            case 1:
                //input kode barang dan jumlah barang sekaligus error handling-nya
                menu_1(data_1, newNode1);
                break;
            case 2:
                user_instruction();
                break;
            case 3:
				//menggunakan binary tree untuk mencari barang
                display_katalog(data_1);
                printf("\n");
                menu_3(data3);

                break;
            case 4:

                while(1){
                    printf("1. Tambah Barang Baru\n");
                    printf("2. Hapus Barang\n");
                    printf("Silakan masukkan pilihan Anda: ");
                    scanf("%d", &choice);

                    if(choice == 2){
                        while(1){
                            printf("Masukkan kode Barang yang ingin dihapus: ");
                            scanf("%d", &kodeBarangInput);
                            errorHandling = inputErrorHandling(data_1, kodeBarangInput);
                            if(errorHandling == 1){
                                data_1 = deleteStuff(data_1, kodeBarangInput);
                                display_katalog(data_1);
                                while(1){
                                    choice  = 0;
                                    printf("Apakah masih ingin menghapus Barang?\n");
                                    printf("1. Ya\n");
                                    printf("2. Tidak\n");
                                    printf("Masukkan pilihan Anda (1/2): ");
                                    scanf("%d", &choice);
                                    if(choice == 1 || choice == 2){
                                        printf("\n");
                                        break;
                                    }else{
                                        printf("Maaf, hanya menerima input 1 atau 2 saja\n");
                                        continue;
                                    }
                                }
                                if(choice == 1){
                                    continue;
                                }else if(choice == 2){
                                    break;
                                }
                            }else{
                                printf("Kode Barang tidak ditemukan\n");
                                while(1){
                                    choice  = 0;
                                    printf("Apakah masih ingin menghapus Barang?\n");
                                    printf("1. Ya\n");
                                    printf("2. Tidak\n");
                                    printf("Masukkan pilihan Anda (1/2): ");
                                    scanf("%d", &choice);
                                    if(choice == 1 || choice == 2){
                                        printf("\n");
                                        break;
                                    }else{
                                        printf("Maaf, hanya menerima input 1 atau 2 saja\n");
                                        continue;
                                    }
                                }
                                if(choice == 1){
                                    continue;
                                }else if(choice == 2){
                                    break;
                                }
                                continue;
                            }
                        }
                        if(choice == 2){
                            break;
                        }
                    }else if(choice == 1){
                        printf("Menu ini untuk sekarang tidak tersedia.\n");
                    }else{
                        printf("\nHanya menerima angka 1 dan 2 saja.\n");
                        continue;
                    }
                }
                break;
            case 5:
                exit(1);
            default:
                printf("Invalid input\n");
        }

    }
}

void mainMenu(void){
    printf("==========E-MART=========");
    printf("\n");
    printf("Selamat datang di E-Mart!");
    printf("\n");
    printf("1. Mulai Belanja\n");
    printf("2. Petunjuk Penggunaan\n");
    printf("3. Katalog Barang\n");
    printf("4. Edit Katalog\n");
    printf("5. Keluar\n");
}

void display_katalog(struct node *startNode){
    int i = 1;
    struct node *firstNode;

    if(startNode == NULL){
        printf("Linked List is Empty\n");
        return;
    }

    firstNode = startNode;
    printf("No.\tKode\tNama Barang\t\t\tHarga\t\t\n");
    printf("=====================================================\n");
    while(firstNode != NULL){
        printf("%d\t", i);
        printf("%d\t", firstNode->kodeBarang);
        printf("%-16s\t\t", firstNode->namaBarang);
        printf("%d\t\t\n", firstNode->hargaBarang);
        i++;
        firstNode = firstNode->nextNode;
    }
    printf("=====================================================\n");
}

struct node *addNodeLinkedListFirst(struct node *startNode, int kodeBarangInput, int hargaBarangInput, char namaBarangInput[50]){
    struct node *tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->kodeBarang = kodeBarangInput;
    tmp->hargaBarang = hargaBarangInput;
    strcpy(tmp->namaBarang, namaBarangInput);

    tmp->nextNode = startNode;
    startNode = tmp;
    return startNode;


}

struct finalNode *searchNode(struct node *startNode, struct finalNode *newNode, int kodeBarangInput, int jumlah){
    struct node *i;
    struct finalNode *tmp;

    i = startNode;

    while(i != NULL){
        if(i->kodeBarang == kodeBarangInput){
            tmp = (struct finalNode*)malloc(sizeof(struct finalNode));
            tmp->kodeBarang = i->kodeBarang;
            tmp->hargaBarang = i->hargaBarang;
            strcpy(tmp->namaBarang, i->namaBarang);
            tmp->jumlah = jumlah;
            tmp->total = tmp->hargaBarang * tmp->jumlah;

            tmp->nextNode = newNode;
            newNode = tmp;
            return newNode;
        }
        i = i->nextNode;
    }

    printf("Node is not found\n");
}

void displayCashOut(struct finalNode *startFinalNode){
    int i = 1;
    int total = 0;
    struct finalNode *firstFinalNode;

    if(startFinalNode == NULL){
        printf("Linked List is Empty\n");
        return;
    }

    firstFinalNode = startFinalNode;
    printf("No.\tKode\tNama Barang\t\t\tHarga\t\tJumlah\t\tTotal\n");
    printf("=====================================================================================\n");
    while(firstFinalNode != NULL){
        printf("%d\t", i);
        printf("%d\t", firstFinalNode->kodeBarang);
        printf("%-16s\t\t", firstFinalNode->namaBarang);
        printf("%d\t\t", firstFinalNode->hargaBarang);
        printf("%d\t\t", firstFinalNode->jumlah);
        printf("%d\n", firstFinalNode->total);

        total += firstFinalNode->total;
        i++;
        firstFinalNode = firstFinalNode->nextNode;
    }
    printf("=====================================================================================\n");
    printf("Total: %d\n", total);

}

int inputErrorHandling(struct node *startNode, int kodeBarang){
    while(startNode != NULL){
        if(startNode->kodeBarang == kodeBarang){
            return 1;
        }else{
            startNode = startNode->nextNode;
        }
    }
    return 0;
}

void user_instruction(void){
    printf("\n=========================PETUNJUK PENGGUNAAN=========================\n");
    printf(">>>>Jika memilih menu 'Mulai Belanja'\n");
    printf("1a. Akan ditampilkan katalog barang beserta harga dan kode barang\n");
    printf("2a. Masukkan kode dari barang yang ingin dibeli\n");
    printf("3a. Masukkan jumlah barang yang ingin dibeli\n");
    printf("4a. Diberikan pilihan untuk berbelanja lagi atau tidak\n");
    printf("5a. Jika masih ingin berbelanja pilih 'Ya' dan ulangi langkah 2a dan 3a\n");
    printf("6a. Jika sudah tidak ingin berbelanja pilih 'Tidak'\n");
    printf("7a. Struk akan dicetak mulai dari barang termurah ke termahal beserta total harganya\n");
    printf("\n>>>>Jika memilih menu 'Katalog Barang'\n");
    printf("1b. Akan ditampilkan katalog barang beserta harga dan kode barang\n");
    printf("2b. Diberikan pilihan apakah ingin mencari barang atau tidak\n");
    printf("3b. Jika ingin mencari barang pilih 'Ya'\n");
    printf("4b. Masukkan nama barang yang ingin dicari\n");
    printf("5b. Hasil pencarian akan muncul\n");
    printf("6b. Kembali diberikan pilihan seperti pada langkah 2b\n");
    printf("7b. Jika masih ingin mencari barang ulangi langkah 3b dan 4b\n");
    printf("8b. Jika sudah tidak ingin mencari barang pilih 'Tidak'\n");
    printf("9b. Anda akan dikembalikan ke menu utama\n");
    printf("\n");
}

void display_nama_barang_menu3(struct binaryTree *startNode, char namaBarangInput[50]){
    while(startNode != NULL){
        if(startNode->namaBarang[0] == namaBarangInput[0]){
            printf("Barang\t\t\t\t\t\tHarga\tKode\n");
            printf("=======================================\n");
            printf("%s\t\t\t\t\t\t%d\t%d\n", startNode->namaBarang, startNode->hargaBarang, startNode->kodeBarang);
            break;
        }else if(startNode->namaBarang[0] > namaBarangInput[0]){
            display_nama_barang_menu3(startNode->rightPtr, namaBarangInput);
        }else if(startNode->namaBarang[0] < namaBarangInput[0]){
            display_nama_barang_menu3(startNode->leftPtr, namaBarangInput);
        }
    }
}


void menu_1(struct node *startNode, struct finalNode *newNode){
    int kodeBarangInput;
    int errorHandlingOutput;
    int n;
    int choice3;
    int j;


    while(1){
        j = 0;
        display_katalog(startNode);
        printf("\nMasukkan kode Barang: ");
        scanf("%d", &kodeBarangInput);

        errorHandlingOutput = inputErrorHandling(startNode, kodeBarangInput);
        //jika barang ada
        if(errorHandlingOutput == 1){
            printf("Jumlah barang yang ingin dibeli: ");
            scanf("%d", &n);

            newNode = searchNode(startNode, newNode, kodeBarangInput, n);

            while(j != 1){
                printf("Apakah masih ingin berbelanja?\n");
                printf("1.Ya\n2.Tidak\n");
                printf("Masukkan pilihan Anda (1/2): ");
                scanf("%d", &choice3);
                printf("\n");
                if(choice3 == 1){
                    //menu_1(startNode, newNode);
                    j = 0;
                    break;
                }else if(choice3 == 2){
                    j = 1;
                    break;
                }else{
                    printf("Maaf, hanya menerima input 1 atau 2 saja\n\n");
                    continue;
                }
            }
            if(choice3 == 1){
                continue;
            }else if(choice3 == 2){
                break;
            }

        }else if(errorHandlingOutput == 0){
            printf("Barang tidak ditemukan, silakan coba lagi\n\n");
            continue;
        }
    }
    displayCashOut(newNode);
    printf("\n");

}

void menu_3(struct binaryTree *headTree){
    int choice3;
    int choice3_1;
    int kodeBarangInput1;

    while(1){
        printf("Apakah ingin mencari barang?\n");
        printf("1.Ya\n2.Tidak\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &choice3);

            if(choice3 == 1){
            	while(1){
            		printf("Silakan masukkan kode barang yang ingin dicari: ");
                	scanf("%d", &kodeBarangInput1);
					printTreeNode(headTree, kodeBarangInput1);
                
                	while(1){
                    	printf("Apakah ingin mencari barang?\n");
                    	printf("1.Ya\n2.Tidak\n");
                    	printf("Masukkan pilihan Anda: ");
                    	scanf("%d", &choice3_1);
                    	printf("\n");
                    	if(choice3_1 == 1 || choice3_1 == 2){
                        	break;
                    	}else{
                        	printf("Hanya menerima angka 1 atau 2\n");
                        	continue;
                    	}
                	}		
                if(choice3_1 == 1){
                    continue;
                }else if(choice3_1 == 2){
                    break;
                }
							}

            }else if(choice3 == 2){
                break;
            }else{
                printf("Hanya menerima angka 1 atau 2\n");
                continue;
            }
        break;

    }
}

void printTreeNode(struct binaryTree *headTree, int kodeBarangInput){
    if(headTree == NULL){
        printf("Barang tidak ditemukan\n\n");
    }

    while(headTree != NULL){
        if(kodeBarangInput == headTree->kodeBarang){
            printf(">>>>> Berikut adalah barang yang Anda cari\n\n");

            printf("Kode\t\tNama Barang\t\tHarga\n");
            printf("=============================================\n");
            printf("%d\t\t", headTree->kodeBarang);
            printf("%s\t\t", headTree->namaBarang);
            printf("%d\n", headTree->hargaBarang);
            printf("=============================================\n");

            printf("\n");
            break;
        }else if(kodeBarangInput > headTree->kodeBarang){
            printTreeNode(headTree->rightPtr, kodeBarangInput);
            break;
        }else if(kodeBarangInput < headTree->kodeBarang){
            printTreeNode(headTree->leftPtr, kodeBarangInput);
            break;
        }
    }
}


struct node *addNewStuff(struct node *startNode, int kodeBarangInput, int hargaBarangInput, char namaBarangInput[50]){
    struct node *tmp;

    while(startNode != NULL){
        tmp = (struct node*)malloc(sizeof(struct node));
        tmp->kodeBarang = kodeBarangInput;
        tmp->hargaBarang = hargaBarangInput;
        strcpy(tmp->namaBarang, namaBarangInput);

        tmp->nextNode = startNode;
        startNode = tmp;
        return startNode;

    }
}

struct node *deleteStuff(struct node *startNode,int kodeBarangInput){
    struct node *tmp, *i;

    if(startNode == NULL){
        printf("Linked list is Empty\n");
        return startNode;
    }

    if(startNode->kodeBarang == kodeBarangInput){
        tmp = startNode;
        startNode = startNode->nextNode;
        free(tmp);
        return startNode;
    }

    i = startNode;

    while(i->nextNode != NULL){
        if(i->nextNode->kodeBarang == kodeBarangInput){
            tmp = i->nextNode;
            i->nextNode = tmp->nextNode;
            free(tmp);
            return startNode;
        }
    }
    printf("Node tidak ditemukan\n");
    return startNode;
}

