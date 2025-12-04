void setup() {
pinMode(buzzer,OUTPUT); // Buzzer'in bağlı olduğu pini çıkış olarak ayarladık.
 
}
 
void loop() {
 digitalWrite(buzzer,HIGH); //Buzzer'a güç göndererek ses çıkarmasını sağladık.
 delay(1000);                  // 1 saniye boyunca çalmasını söyledik.
 digitalWrite(buzzer,LOW); //Buzzerın gücünü keserek susmasını sağladık sağladık.
 delay(1000);                 // 1 saniye boyunca susmasını söyledik.
}