Urutan pemrosesan Testbench:
-Asumsikan pengguna telah memasukkan semua masukkan kedalam direktori Outbox
-Melalui modus B (Modus Pengiriman), semua pesan ditransfer dari direktori Outbox ke direktori Sending
Transfer dilakukan menggunakan skala prioritas, yaitu priority queue
-Melalui modus C (Modus Penerimaan), dilakukan beberapa pemrosesan sebagai berikut:
1. List Pesan, yaitu memindahkan semua pesan dari direktori Sending ke direktori Inbox
2. Baca Pesan, yaitu membaca pesan yang ID nya terdefinisi (ref: List Pesan)
3. Hapus Pesan, yaitu menghapus pesan yang berada di direktori Inbox dan ID terdefinisi