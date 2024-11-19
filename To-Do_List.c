// Danu Alamsyah Putra
// Teknologi Rekayasa Komputer
// Politeknik Negeri Semarang

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // Maksimum jumlah elemen

// Struktur untuk menyimpan informasi kegiatan
typedef struct Kegiatan {
    char deskripsi[256];
    int prioritas;
} Kegiatan;

// Struktur stack untuk menyimpan riwayat
typedef struct Stack {
    Kegiatan kegiatan[MAX];
    int atas;
} Stack;

// Struktur priority queue untuk menyimpan dan mengatur kegiatan berdasarkan prioritas
typedef struct PriorityQueue {
    Kegiatan kegiatan[MAX];
    int ukuran; // Jumlah elemen dalam priority queue
} PriorityQueue;

// Inisialisasi stack
void initStack(Stack *s) {
    s->atas = -1;
}

// Mengecek apakah stack penuh
int isFullStack(Stack *s) {
    return s->atas == MAX - 1;
}

// Mengecek apakah stack kosong
int isEmptyStack(Stack *s) {
    return s->atas == -1;
}

// Menambahkan elemen ke stack
void pushStack(Stack *s, Kegiatan kegiatan) {
    if (isFullStack(s)) {
        printf("Stack penuh.\n");
    } else {
        s->kegiatan[++(s->atas)] = kegiatan;
    }
}

// Menghapus elemen dari stack
Kegiatan popStack(Stack *s) {
    if (isEmptyStack(s)) {
        printf("Stack kosong.\n");
        Kegiatan kegiatanKosong = {"", 0};
        return kegiatanKosong;
    } else {
        return s->kegiatan[(s->atas)--];
    }
}

// Inisialisasi priority queue
void initPriorityQueue(PriorityQueue *pq) {
    pq->ukuran = 0;
}

// Menukar dua elemen kegiatan
void swap(Kegiatan *a, Kegiatan *b) {
    Kegiatan temp = *a;
    *a = *b;
    *b = temp;
}

// Menambahkan elemen ke priority queue
void enqueue(PriorityQueue *pq, Kegiatan kegiatan) {
    if (pq->ukuran == MAX) {
        printf("Priority Queue penuh.\n");
        return;
    }
    pq->kegiatan[pq->ukuran++] = kegiatan; // Tambah kegiatan ke array
    int i = pq->ukuran - 1;
    while (i > 0 && pq->kegiatan[i].prioritas < pq->kegiatan[(i - 1) / 2].prioritas) {
        swap(&pq->kegiatan[i], &pq->kegiatan[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Menghapus elemen dengan prioritas tertinggi dari priority queue
Kegiatan dequeue(PriorityQueue *pq) {
    if (pq->ukuran == 0) {
        printf("Priority Queue kosong.\n");
        Kegiatan kegiatanKosong = {"", 0};
        return kegiatanKosong;
    }
    Kegiatan root = pq->kegiatan[0];
    pq->kegiatan[0] = pq->kegiatan[--pq->ukuran];
    int i = 0;
    while (2 * i + 1 < pq->ukuran) {
        int child = 2 * i + 1;
        if (child + 1 < pq->ukuran && pq->kegiatan[child].prioritas > pq->kegiatan[child + 1].prioritas) {
            child++;
        }
        if (pq->kegiatan[i].prioritas <= pq->kegiatan[child].prioritas) {
            break;
        }
        swap(&pq->kegiatan[i], &pq->kegiatan[child]);
        i = child;
    }
    return root;
}

// Menampilkan semua kegiatan dalam priority queue
void lihatDaftarKegiatan(PriorityQueue *pq) {
    printf("\nDaftar Kegiatan:\n");
    for (int i = 0; i < pq->ukuran; i++) {
        printf("%s (Prioritas: %d)\n", pq->kegiatan[i].deskripsi, pq->kegiatan[i].prioritas);
    }
}

// Menambahkan kegiatan baru ke priority queue
void tambahKegiatan(PriorityQueue *pq) {
    if (pq->ukuran == MAX) {
        printf("Priority Queue penuh. Tidak bisa menambahkan kegiatan.\n");
        return;
    }

    Kegiatan kegiatanBaru;
    printf("Masukkan deskripsi kegiatan: ");
    getchar();
    fgets(kegiatanBaru.deskripsi, 256, stdin);
    kegiatanBaru.deskripsi[strcspn(kegiatanBaru.deskripsi, "\n")] = '\0';
    printf("Masukkan prioritas kegiatan (1-3): ");
    scanf("%d", &kegiatanBaru.prioritas);

    if (kegiatanBaru.prioritas < 1 || kegiatanBaru.prioritas > 3) {
        printf("Prioritas tidak valid. Masukkan prioritas antara 1 dan 3.\n");
        return;
    }

    enqueue(pq, kegiatanBaru); // Tambah kegiatan ke priority queue
}

// Menandai kegiatan sebagai selesai dan menghapusnya dari priority queue
void tandaiKegiatanSelesai(PriorityQueue *pq) {
    if (pq->ukuran == 0) {
        printf("Tidak ada kegiatan untuk ditandai sebagai selesai.\n");
        return;
    }

    Kegiatan kegiatan = dequeue(pq); // Hapus
    printf("Kegiatan '%s' dengan prioritas %d telah ditandai sebagai selesai.\n", kegiatan.deskripsi, kegiatan.prioritas);
}

// Fungsi utama
int main() {
    PriorityQueue pq;
    initPriorityQueue(&pq);

    int pilihan;
    while (1) {
        printf("\nAplikasi TO-DO List\n");
        printf("1. Lihat daftar kegiatan\n");
        printf("2. Tambah kegiatan\n");
        printf("3. Tandai kegiatan selesai\n");
        printf("4. Keluar\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                lihatDaftarKegiatan(&pq);
                break;
            case 2:
                tambahKegiatan(&pq);
                break;
            case 3:
                tandaiKegiatanSelesai(&pq);
                break;
            case 4:
                exit(0);
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }

    return 0;
}
