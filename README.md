# LATIHAN1DPBO2024
## Janji
Saya [Jidan Abdurahman Aufan] mengerjakan Latihan Praktikum 1 dalam mata kuliah [Desain Pemrograman Berorientasi Objek]
untuk keberkahannya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
## Deskripsi Program
Program berbasis OOP menggunakan bahasa pemrograman C++, Java, Python, dan PHP yang menampilkan informasi daftar anggota DPR (sekumpulan objek anggota DPR) dan memiliki fitur menambah, mengubah, dan menghapus data. Setiap anggota DPR memiliki data id, nama, nama bidang, tempat pemilihan, jabatan, nama partai, dan foto profil (khusus bahasa PHP).

## Penjelasan Desain 
Program terdiri dari 3 kelas, yaitu AnggotaDPR, DataController, dan Tabel (khusus untuk python ditambah ConsoleUtilities untuk clear console yang cross-platform). DataController memiliki container data, lalu memiliki fungsi fungsi untuk mengoperasikan data dalam container tersebut sebagai berikut: 
- create(menambahkan data ke dalam container)
- modify(mengubah isian data tertentu dengan memilih data berdasarkan id)
- delete(menghapus data yang dipilih dengan id)
- showAll(untuk menampilkan seluruh data yang ada, yaitu mengambil seluruh data, lalu dibungkus data tsb agar bisa dimasukkan kedalam tabel yang akan ditampilkan, tabel di instansiasi baru setiap pemanggilan fungsi ini)