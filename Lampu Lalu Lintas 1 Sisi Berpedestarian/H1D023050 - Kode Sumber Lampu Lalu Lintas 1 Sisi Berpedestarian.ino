// --- PIN TOMBOL INTERUPSI ---
const int pinTombol = 2;

// --- PIN LAMPU KENDARAAN (JALAN RAYA) ---
const int kendMerah = 13;
const int kendKuning = 12;
const int kendHijau = 11;

// --- PIN LAMPU PEDESTRIAN SISI 1 ---
const int ped1Merah = 10;
const int ped1Hijau = 9;

// --- PIN LAMPU PEDESTRIAN SISI 2 ---
const int ped2Merah = 8;
const int ped2Hijau = 7;

void setup() {
  pinMode(pinTombol, INPUT_PULLUP);

  for (int pin = 7; pin <= 13; pin++) {
    pinMode(pin, OUTPUT);
  }

  // KONDISI AWAL: Semua lampu wajib merah saat baru dimulai
  digitalWrite(kendMerah, HIGH);
  digitalWrite(kendKuning, LOW);
  digitalWrite(kendHijau, LOW);

  digitalWrite(ped1Merah, HIGH);
  digitalWrite(ped1Hijau, LOW);

  digitalWrite(ped2Merah, HIGH);
  digitalWrite(ped2Hijau, LOW);

  // Semua merah selama 2 detik
  delay(2000);

  // Ubah lampu kendaraan menjadi hijau agar siap masuk ke siklus loop() normal
  digitalWrite(kendMerah, LOW);
  digitalWrite(kendHijau, HIGH);
}

void loop() {
  // 1. FASE JALAN KENDARAAN & CEK TOMBOL
  boolean adaPermintaanPenyeberang = false;

  for (int i = 0; i < 50; i++) {
    if (digitalRead(pinTombol) == LOW) {
      adaPermintaanPenyeberang = true; 
      delay(200); 
      break; 
    }
    delay(100);
  }

  // 2. KENDARAAN BERSIAP BERHENTI (Kuning Berkedip 3x)
  digitalWrite(kendHijau, LOW);
  
  for (int j = 0; j < 3; j++) {
    digitalWrite(kendKuning, HIGH);
    delay(300); 
    digitalWrite(kendKuning, LOW);
    delay(300); 
  }
  digitalWrite(kendKuning, LOW); 

  // 3. FASE MENYEBERANG (KENDARAAN MERAH, PEDESTRIAN HIJAU)
  digitalWrite(kendMerah, HIGH);
  delay(1000); // Jeda keamanan

  digitalWrite(ped1Merah, LOW);
  digitalWrite(ped2Merah, LOW);
  digitalWrite(ped1Hijau, HIGH);
  digitalWrite(ped2Hijau, HIGH);

  delay(5000); // Durasi menyeberang

  // 4. PERINGATAN WAKTU MENYEBERANG HABIS (Hijau Pedestrian Berkedip)
  for (int k = 0; k < 3; k++) {
    digitalWrite(ped1Hijau, LOW);
    digitalWrite(ped2Hijau, LOW);
    delay(300);
    digitalWrite(ped1Hijau, HIGH);
    digitalWrite(ped2Hijau, HIGH);
    delay(300);
  }
  digitalWrite(ped1Hijau, LOW);
  digitalWrite(ped2Hijau, LOW);

  // 5. KENDARAAN JALAN KEMBALI
  digitalWrite(ped1Merah, HIGH);
  digitalWrite(ped2Merah, HIGH);
  delay(1000); 

  digitalWrite(kendMerah, LOW);
  digitalWrite(kendHijau, HIGH);

  if (adaPermintaanPenyeberang) {
    delay(3000); // Mencegah interupsi beruntun
  }
}
