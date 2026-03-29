//Posisi Lampu Lalu Lintas
//Utara
const int utaraMerah = 10;
const int utaraKuning = 9;
const int utaraHijau = 8;

//Timur
const int timurMerah = 4;
const int timurKuning = 3;
const int timurHijau = 2;

//Selatan
const int selatanMerah = 7;
const int selatanKuning = 6;
const int selatanHijau = 5;

//Barat
const int baratMerah = 13;
const int baratKuning = 12;
const int baratHijau = 11;

//Mulai Program
void setup() {
  // Mengatur semua pin yang terhubung pada perangkat-
  // Arduino terhadap pin ke lampu sebagai OUTPUT
  // Pin dipakai adalah pin 2 hingga pin 13
  for (int pin = 2; pin <= 13; pin++) {
    pinMode(pin, OUTPUT);
  }

  // KONDISI AWAL: Semua lampu merah menyala  
  // High untuk nyala dan Low sebagai mati
  // Utara
  digitalWrite(utaraMerah, HIGH);
  digitalWrite(utaraKuning, LOW);
  digitalWrite(utaraHijau, LOW);
  
  // Timur
  digitalWrite(timurMerah, HIGH);
  digitalWrite(timurKuning, LOW);
  digitalWrite(timurHijau, LOW);
  
  // Selatan
  digitalWrite(selatanMerah, HIGH);
  digitalWrite(selatanKuning, LOW);
  digitalWrite(selatanHijau, LOW);
  
  // Barat
  digitalWrite(baratMerah, HIGH);
  digitalWrite(baratKuning, LOW);
  digitalWrite(baratHijau, LOW);
  
  // jeda 2 detik sebelum siklus lalin dimulai,
  // mempertahankan warna merah di 4 sisi
  delay(2000); 
}

//Mulai Siklus Lalin
//menggunakan program perulangan
void loop() {
  
  // Lalin bergilir searah jarum jam
  // Fungsi modular "aktifkanSimpang()"
  aktifkanSimpang(utaraMerah, utaraKuning, utaraHijau);        // 1. Utara jalan
  aktifkanSimpang(timurMerah, timurKuning, timurHijau);        // 2. Timur jalan
  aktifkanSimpang(selatanMerah, selatanKuning, selatanHijau);  // 3. Selatan jalan
  aktifkanSimpang(baratMerah, baratKuning, baratHijau);        // 4. Barat jalan
}

// Fungsi Modularnya
// mengontrol pergantian lampu untuk satu arah/simpang
void aktifkanSimpang(int pinMerah, int pinKuning, int pinHijau) {
  
  // 1. Mematikan lampu Merah dan menyalakan lampu Hijau
  digitalWrite(pinMerah, LOW);
  digitalWrite(pinHijau, HIGH);
  // Durasi lampu Hijau
  delay(5000); 
  
  // 2. Matikan lampu Hijau, mulai alihkan ke lampu Kuning
  digitalWrite(pinHijau, LOW);
  
  // 3. Efek berkedip untuk lampu kuning sebanyak 3 kali
  for (int i = 0; i < 3; i++) {
    digitalWrite(pinKuning, HIGH);
    // Durasi kedip: Kuning nyala 0.3 detik
    delay(300); 
    digitalWrite(pinKuning, LOW);
    // Durasi kedip: Kuning mati 0.3 detik
    delay(300); 
  }
  // Matikan kuning
  digitalWrite(pinKuning, LOW); 
  
  // 5. Kembalikan ke kondisi awal, Merah, sebelum pindah ke simpang berikutnya
  digitalWrite(pinMerah, HIGH);
  
  // Jeda antar transisi pindah simpang
  // supaya tidak bertindih/bertabrakan
  delay(1000); 
}
