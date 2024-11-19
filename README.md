# To-Do-List
To-Do List adalah aplikasi sederhana berbasis terminal yang dibuat dengan bahasa C untuk mencatat dan mengelola tugas harian.

Fitur
Lihat daftar kegiatan.
Tambah kegiatan.
Hapus kegiatan berdasarkan nomor.

Struktur Program
1. Priority Queue

Digunakan untuk menyimpan dan mengatur daftar kegiatan berdasarkan prioritas.
Kegiatan dengan prioritas lebih tinggi akan ditempatkan lebih dahulu (prioritas kecil = lebih tinggi).
Implementasi menggunakan array dengan logika heap untuk menjaga urutan prioritas.

2. Stack (Opsional)

Disiapkan untuk mencatat riwayat kegiatan (misalnya, kegiatan yang sudah selesai).
Implementasi stack berbasis array dengan fungsi push dan pop.

3. Fungsi Utama

Tambah Kegiatan: Menambahkan deskripsi dan prioritas kegiatan ke dalam Priority Queue.
Lihat Daftar Kegiatan: Menampilkan semua kegiatan berdasarkan prioritas.
Tandai Kegiatan Selesai: Menghapus kegiatan dengan prioritas tertinggi dari Priority Queue.
Keluar: Menghentikan program.
